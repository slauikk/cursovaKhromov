#include "profile.h"

Profile::Profile(QString name, float monthlyBudget) {
    this->name = name;
    this->monthlyBudget = monthlyBudget;
}

QString Profile::gatName(){
    return name;
}


float Profile::getMonthlyBudget(){
    return monthlyBudget;
}
