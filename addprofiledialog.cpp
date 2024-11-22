#include "addprofiledialog.h"
#include "ui_addprofiledialog.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

AddProfileDialog::AddProfileDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddProfileDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Створення профілю");
}

AddProfileDialog::~AddProfileDialog()
{
    delete ui;
}

void AddProfileDialog::on_pb_create_clicked()
{
    QString name = ui->le_name->text().trimmed();
    QString monthlyBudgetStr = ui->le_monthlyBudget->text().trimmed();

    if (name.isEmpty() || monthlyBudgetStr.isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Будь ласка, заповніть усі поля.");
        return;
    }

    bool ok;
    float monthlyBudget = monthlyBudgetStr.toFloat(&ok);
    if (!ok || monthlyBudget <= 0) {
        QMessageBox::warning(this, "Помилка", "Бюджет має бути додатним числом.");
        return;
    }

    if (!isNameUnique(name)) {
        QMessageBox::warning(this, "Помилка", "Профіль із таким ім'ям вже існує.");
        return;
    }

    Profile *profile = new Profile(name, monthlyBudget);

    emit profileCreated(profile);

    accept();
}

void AddProfileDialog::on_pb_cancel_clicked()
{
    this->reject();
}

bool AddProfileDialog::isNameUnique(const QString &name)
{
    QSqlQuery query;

    QString sql = "SELECT COUNT(*) FROM Profiles WHERE profile_name = :name";
    query.prepare(sql);

    query.bindValue(":name", name);

    qDebug() << "Executing query:" << sql;
    qDebug() << "Bound values:" << query.boundValues();

    if (!query.exec()) {
        qDebug() << "Database error checking profile uniqueness:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        int count = query.value(0).toInt();
        qDebug() << "Count of profiles with profile_name:" << name << "is" << count;
        return count == 0;
    }

    qDebug() << "Query did not return results for uniqueness check.";
    return false;
}



