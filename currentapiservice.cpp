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

    if (reply->error() == QNetworkReply::NoError) {

        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);

        if (jsonDoc.isArray()) {
            QJsonArray ratesArray = jsonDoc.array();
            QString usdBuy, usdSell, eurBuy, eurSell;


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

            qDebug() << "USD: Buy =" << usdBuy << ", Sell =" << usdSell;
            qDebug() << "EUR: Buy =" << eurBuy << ", Sell =" << eurSell;


            emit exchangeRatesFetched(usdBuy, usdSell, eurBuy, eurSell);
        }
    } else {
        qDebug() << "Error fetching exchange rates:" << reply->errorString();
    }

    reply->deleteLater();
}
