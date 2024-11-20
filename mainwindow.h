#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QPieSeries>
#include <addoutlaydialog.h>
#include <addprofiledialog.h>
#include <exchangedialog.h>
#include <analysisdialog.h>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_addOutlay_clicked();

    void on_pb_searchOutlay_clicked();

    void on_pb_addProfile_clicked();

    void on_pb_exchange_clicked();

    void on_pb_analysis_clicked();

    void on_pb_exit_clicked();

private:
    Ui::MainWindow *ui;

    AddOutlayDialog *addOutlay;
    AddProfileDialog *addProfile;
    ExchangeDialog *exchangeDialog;
    AnalysisDialog *analysisDialog;



};
#endif // MAINWINDOW_H
