#include "outlay.h"

Outlay::Outlay(QString name, int profileId, int categoryId, float amount, QString timestamp) {
    this->name = name;
    this->profileId = profileId;
    this->categoryId = categoryId;
    this->amount = amount;
    this->timestamp = timestamp;
}
QString Outlay::getName() const {
    return name;
}

int Outlay::getProfileId() const {
    return profileId;
}
int Outlay::getCategoryId() const {
    return categoryId;
}
float Outlay::getAmount() const {
    return amount;
}
QString Outlay::getTimestamp() const {
    return timestamp;
}
