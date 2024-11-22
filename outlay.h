#ifndef OUTLAY_H
#define OUTLAY_H
#include <QString>

class Outlay {
public:
    Outlay(QString name, int profileId, int categoryId, float amount, QString timestamp);

    QString getName() const;
    int getProfileId() const;
    int getCategoryId() const;
    float getAmount() const;
    QString getTimestamp() const;

private:
    QString name;
    int profileId;
    int categoryId;
    float amount;
    QString timestamp;
};

#endif // OUTLAY_H
