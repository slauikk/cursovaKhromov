#include "addprofiledialog.h"
#include "ui_addprofiledialog.h"

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


    accept();
}


void AddProfileDialog::on_pb_cancel_clicked()
{
    this->close();
}

