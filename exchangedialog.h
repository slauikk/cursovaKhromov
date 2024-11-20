#ifndef EXCHANGEDIALOG_H
#define EXCHANGEDIALOG_H

#include <QDialog>
#include "currentapiservice.h"

namespace Ui {
class ExchangeDialog;
}

class ExchangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExchangeDialog(QWidget *parent = nullptr);
    ~ExchangeDialog();

private slots:
    void on_pb_cancel_clicked();
    void on_pb_changePage_clicked();
    void convertUAHToUSD();
    void convertUAHToEUR();
    void convertUSDtoUAH();
    void convertEURToUAH();

private:
    Ui::ExchangeDialog *ui;
    CurrentAPIService *apiService;

    double usdBuyRate;
    double usdSellRate;
    double eurBuyRate;
    double eurSellRate;

    void updateLabels();
};

#endif // EXCHANGEDIALOG_H
