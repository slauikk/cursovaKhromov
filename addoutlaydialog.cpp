#include "addoutlaydialog.h"
#include "ui_addoutlaydialog.h"

AddOutlayDialog::AddOutlayDialog(QWidget *parent, SqliteDBManager* dbManager)
    : QDialog(parent)
    , ui(new Ui::addOutlayDialog)
    , profileId(0)
    , dbManager(dbManager)
{
    ui->setupUi(this);
    this->setWindowTitle("Створення витрати");
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    if (!loadCategories()) {
        QMessageBox::warning(this, "Помилка", "Не вдалося завантажити категорії з бази даних.");
    }
}

AddOutlayDialog::~AddOutlayDialog()
{
    delete ui;
}

void AddOutlayDialog::setProfileId(int id)
{
    profileId = id;
}

bool AddOutlayDialog::loadCategories()
{
    if (!dbManager) {
        return false;
    }

    QSqlQuery query("SELECT id, category_name FROM Categories");
    while (query.next()) {
        int categoryId = query.value(0).toInt();
        QString categoryName = query.value(1).toString();


        ui->cb_category->addItem(categoryName, categoryId);
    }

    return !ui->cb_category->count() == 0;
}

bool AddOutlayDialog::validateInputs()
{
    if (ui->le_name->text().isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Назва витрати не може бути порожньою.");
        return false;
    }

    if (ui->cb_category->currentIndex() == -1) {
        QMessageBox::warning(this, "Помилка", "Оберіть категорію витрати.");
        return false;
    }

    bool amountOk;
    float amount = ui->le_amount->text().toFloat(&amountOk);
    if (!amountOk || amount <= 0) {
        QMessageBox::warning(this, "Помилка", "Введіть коректну суму витрати.");
        return false;
    }

    return true;
}

void AddOutlayDialog::on_pb_create_clicked()
{
    if (!validateInputs()) {
        return;
    }

    QString name = ui->le_name->text();
    int categoryId = ui->cb_category->currentData().toInt();
    float amount = ui->le_amount->text().toFloat();
    QString timestamp = ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");

    Outlay* outlay = new Outlay(name, profileId, categoryId, amount, timestamp);

    emit outlayCreated(outlay);
    QMessageBox::information(this, "Успіх", "Витрату успішно створено!");
    accept();
}

void AddOutlayDialog::on_pb_cancel_clicked()
{
    reject();
}
