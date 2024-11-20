#include "analysisdialog.h"
#include "ui_analysisdialog.h"

AnalysisDialog::AnalysisDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AnalysisDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Аналізатор");
}

AnalysisDialog::~AnalysisDialog()
{
    delete ui;
}

void AnalysisDialog::on_pb_calculate_clicked()
{

}


void AnalysisDialog::on_pb_cancel_clicked()
{
    this->close();
}


