#include "addoutlaydialog.h"
#include "ui_addoutlaydialog.h"

AddOutlayDialog::AddOutlayDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addOutlayDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Створення витрати");
}

AddOutlayDialog::~AddOutlayDialog()
{
    delete ui;
}

void AddOutlayDialog::on_pb_create_clicked()
{


    accept();
}


void AddOutlayDialog::on_pb_cancel_clicked()
{
    this->close();
}

