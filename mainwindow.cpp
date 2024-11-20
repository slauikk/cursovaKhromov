#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , addOutlay(new AddOutlayDialog(this))
    , addProfile(new AddProfileDialog(this))
    , exchangeDialog(new ExchangeDialog(this))
    , analysisDialog(new AnalysisDialog(this))
{
    ui->setupUi(this);
    this->setWindowTitle("ZALUPA");

    QPieSeries *series = new QPieSeries();
    series->append("jopa", 30);
    series->append("penis", 30);
    series->append("pizda", 30);
    series->append("anus", 30);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("SOSAL?");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->horizontalLayout->addWidget(chartView);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_addOutlay_clicked()
{
    addOutlay->exec();
}


void MainWindow::on_pb_searchOutlay_clicked()
{

}


void MainWindow::on_pb_addProfile_clicked()
{
    addProfile->exec();
}


void MainWindow::on_pb_exchange_clicked()
{
    exchangeDialog->exec();
}


void MainWindow::on_pb_analysis_clicked()
{
    analysisDialog->exec();
}


void MainWindow::on_pb_exit_clicked()
{
    QApplication::exit();
}



