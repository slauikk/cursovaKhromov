#include "exchangedialog.h"
#include "ui_exchangedialog.h"

ExchangeDialog::ExchangeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ExchangeDialog)
    , usdBuyRate(0.0)
    , usdSellRate(0.0)
    , eurBuyRate(0.0)
    , eurSellRate(0.0)
{
    ui->setupUi(this);
    this->setWindowTitle("Обмін валют");

    apiService = new CurrentAPIService(this);
    connect(apiService, &CurrentAPIService::exchangeRatesFetched, this, [this](const QString &usdBuy, const QString &usdSell, const QString &eurBuy, const QString &eurSell) {
        usdBuyRate = usdBuy.toDouble();
        usdSellRate = usdSell.toDouble();
        eurBuyRate = eurBuy.toDouble();
        eurSellRate = eurSell.toDouble();

        qDebug() << "Курси отримано:";
        qDebug() << "USD: Buy =" << usdBuyRate << ", Sell =" << usdSellRate;
        qDebug() << "EUR: Buy =" << eurBuyRate << ", Sell =" << eurSellRate;

        updateLabels();
    });

    apiService->fetchExchangeRates();

    connect(ui->dsb_uahTousd, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &ExchangeDialog::convertUAHToUSD);
    connect(ui->dsb_uahToeur, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &ExchangeDialog::convertUAHToEUR);
    connect(ui->dsb_usdTouah, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &ExchangeDialog::convertUSDtoUAH);
    connect(ui->dsb_eurTouah, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &ExchangeDialog::convertEURToUAH);
}

ExchangeDialog::~ExchangeDialog()
{
    delete ui;
}

void ExchangeDialog::on_pb_cancel_clicked()
{
    this->close();
}

void ExchangeDialog::on_pb_changePage_clicked()
{
    int currentIndex = ui->stackedWidget->currentIndex();
    int nextIndex = (currentIndex == 0) ? 1 : 0;
    ui->stackedWidget->setCurrentIndex(nextIndex);
}

void ExchangeDialog::convertUAHToUSD()
{
    if (usdBuyRate > 0.0) {
        double uah = ui->dsb_uahTousd->value();
        double usd = uah / usdBuyRate;
        ui->l_usd->setText(QString::number(usd, 'f', 2));
    }
}

void ExchangeDialog::convertUAHToEUR()
{
    if (eurBuyRate > 0.0) {
        double uah = ui->dsb_uahToeur->value();
        double eur = uah / eurBuyRate;
        ui->l_eur->setText(QString::number(eur, 'f', 2));
    }
}

void ExchangeDialog::convertUSDtoUAH()
{
    if (usdSellRate > 0.0) {
        double usd = ui->dsb_usdTouah->value();
        double uah = usd * usdSellRate;
        ui->l_uahFromusd->setText(QString::number(uah, 'f', 2));
    }
}

void ExchangeDialog::convertEURToUAH()
{
    if (eurSellRate > 0.0) {
        double eur = ui->dsb_eurTouah->value();
        double uah = eur * eurSellRate;
        ui->l_uahFromeur->setText(QString::number(uah, 'f', 2));
    }
}

void ExchangeDialog::updateLabels()
{
    convertUAHToUSD();
    convertUAHToEUR();
    convertUSDtoUAH();
    convertEURToUAH();
}
