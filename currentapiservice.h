#ifndef CURRENTAPISERVICE_H
#define CURRENTAPISERVICE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

class CurrentAPIService : public QObject
{
    Q_OBJECT
public:
    explicit CurrentAPIService(QObject *parent = nullptr);
    void fetchExchangeRates();

signals:
    void exchangeRatesFetched(const QString &usdBuy, const QString &usdSell, const QString &eurBuy, const QString &eurSell);

private slots:
    void onReplyFinished();

private:
    QNetworkAccessManager *manager;
};

#endif // CURRENTAPISERVICE_H
