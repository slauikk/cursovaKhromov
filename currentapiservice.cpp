#include "CurrentAPIService.h"

CurrentAPIService::CurrentAPIService(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
}

void CurrentAPIService::fetchExchangeRates()
{
    QUrl url("https://api.privatbank.ua/p24api/pubinfo?exchange&coursid=5");
    QNetworkRequest request(url);
    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, this, &CurrentAPIService::onReplyFinished);
}

void CurrentAPIService::onReplyFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if (!reply)
        return;

    QString usdBuy = "40.50";
    QString usdSell = "41.00";
    QString eurBuy = "42.50";
    QString eurSell = "43.00";

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);

        if (jsonDoc.isArray()) {
            QJsonArray ratesArray = jsonDoc.array();

            for (const QJsonValue &value : ratesArray) {
                QJsonObject obj = value.toObject();
                QString ccy = obj["ccy"].toString();
                QString baseCcy = obj["base_ccy"].toString();

                if (baseCcy == "UAH") {
                    if (ccy == "USD") {
                        usdBuy = obj["buy"].toString();
                        usdSell = obj["sale"].toString();
                    } else if (ccy == "EUR") {
                        eurBuy = obj["buy"].toString();
                        eurSell = obj["sale"].toString();
                    }
                }
            }
        } else {
            qDebug() << "Response is not a valid JSON array.";
        }
    } else {
        qDebug() << "Error fetching exchange rates:" << reply->errorString();
        qDebug() << "Using default exchange rates.";
    }

    qDebug() << "USD: Buy =" << usdBuy << ", Sell =" << usdSell;
    qDebug() << "EUR: Buy =" << eurBuy << ", Sell =" << eurSell;

    emit exchangeRatesFetched(usdBuy, usdSell, eurBuy, eurSell);

    reply->deleteLater();
}
