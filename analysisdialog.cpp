#include "AnalysisDialog.h"
#include "ui_AnalysisDialog.h"
#include <QDateTime>

AnalysisDialog::AnalysisDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnalysisDialog),
    profileId(-1)
{
    ui->setupUi(this);
    this->setWindowTitle("Аналізатор");
}

AnalysisDialog::~AnalysisDialog()
{
    delete ui;
}

void AnalysisDialog::setProfileId(int id) {
    profileId = id;
    updateLabels();
}

void AnalysisDialog::updateLabels() {
    if (profileId == -1) {
        QMessageBox::warning(this, "Помилка", "Невідомий профіль.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT monthly_budget FROM Profiles WHERE id = :id");
    query.bindValue(":id", profileId);

    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "Помилка", "Не вдалося отримати бюджет профілю.");
        return;
    }

    double monthlyBudget = query.value(0).toDouble();

    double maxNecessarily = monthlyBudget * 0.50;
    double maxNotNecessarily = monthlyBudget * 0.30;
    double saving = monthlyBudget * 0.20;

    ui->l_maxNecessarily->setText(QString::number(maxNecessarily, 'f', 2));
    ui->l_notNecessarily->setText(QString::number(maxNotNecessarily, 'f', 2));
    ui->l_saving->setText(QString::number(saving, 'f', 2));

    double spentNecessarily = 0.0;
    double spentNotNecessarily = 0.0;

    QDate currentDate = QDate::currentDate();
    int currentYear = currentDate.year();
    int currentMonth = currentDate.month();

    QDate firstOfMonth(currentYear, currentMonth, 1);
    QDate lastOfMonth = firstOfMonth.addMonths(1).addDays(-1);

    QString firstOfMonthTimestamp = firstOfMonth.toString("yyyy-MM-dd") + " 00:00:00";
    QString lastOfMonthTimestamp = lastOfMonth.toString("yyyy-MM-dd") + " 23:59:59";

    query.prepare("SELECT SUM(amount) FROM Outlays "
                  "JOIN Categories ON Outlays.category_id = Categories.id "
                  "WHERE Categories.is_mandatory = 1 "
                  "AND Outlays.profile_id = :id "
                  "AND Outlays.timestamp >= :firstOfMonth "
                  "AND Outlays.timestamp <= :lastOfMonth");
    query.bindValue(":id", profileId);
    query.bindValue(":firstOfMonth", firstOfMonthTimestamp);
    query.bindValue(":lastOfMonth", lastOfMonthTimestamp);

    if (query.exec() && query.next()) {
        spentNecessarily = query.value(0).toDouble();
    }

    query.prepare("SELECT SUM(amount) FROM Outlays "
                  "JOIN Categories ON Outlays.category_id = Categories.id "
                  "WHERE Categories.is_mandatory = 0 "
                  "AND Outlays.profile_id = :id "
                  "AND Outlays.timestamp >= :firstOfMonth "
                  "AND Outlays.timestamp <= :lastOfMonth");
    query.bindValue(":id", profileId);
    query.bindValue(":firstOfMonth", firstOfMonthTimestamp);
    query.bindValue(":lastOfMonth", lastOfMonthTimestamp);

    if (query.exec() && query.next()) {
        spentNotNecessarily = query.value(0).toDouble();
    }

    ui->l_spentNecessarily->setText(QString::number(spentNecessarily, 'f', 2));
    ui->l_spentNotNecessarily->setText(QString::number(spentNotNecessarily, 'f', 2));

    double remainder = monthlyBudget - (spentNecessarily + spentNotNecessarily);
    ui->l_remainder->setText(QString::number(remainder, 'f', 2));
}

void AnalysisDialog::on_pb_cancel_clicked() {
    this->reject();
}
