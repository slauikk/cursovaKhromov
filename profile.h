#ifndef PROFILE_H
#define PROFILE_H
#include <QString>
class Profile
{
public:
    Profile(QString name, float monthlyBudget);

    QString gatName();
    float getMonthlyBudget();

private:
    QString name;
    float monthlyBudget;
};

#endif // PROFILE_H
