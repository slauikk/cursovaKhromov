#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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

}

