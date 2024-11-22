#include "SqliteDBManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

SqliteDBManager::SqliteDBManager(const QString &path) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if (!db.open()) {
        qDebug() << "Error: connection with database failed";
    } else {
        qDebug() << "Database: connection ok";
        QSqlQuery query;
        query.exec("PRAGMA foreign_keys = ON;");
    }
}

SqliteDBManager::~SqliteDBManager() {
    if (db.isOpen()) {
        db.close();
    }
}

bool SqliteDBManager::isConnected() const {
    return db.isOpen();
}

bool SqliteDBManager::createTables() {
    QSqlQuery query;

    QString createProfilesTable = R"(
        CREATE TABLE IF NOT EXISTS Profiles (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            profile_name TEXT NOT NULL,
            monthly_budget REAL NOT NULL
        )
    )";
    if (!query.exec(createProfilesTable)) {
        qDebug() << "Couldn't create the Profiles table:" << query.lastError();
        return false;
    }

    QString createCategoriesTable = R"(
        CREATE TABLE IF NOT EXISTS Categories (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            category_name TEXT NOT NULL,
            is_mandatory BOOLEAN NOT NULL
        )
    )";
    if (!query.exec(createCategoriesTable)) {
        qDebug() << "Couldn't create the Categories table:" << query.lastError();
        return false;
    }

    if (isTableEmpty("Categories")) {
        populateCategories();
    }

    QString createOutlaysTable = R"(
        CREATE TABLE IF NOT EXISTS Outlays (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            profile_id INTEGER NOT NULL,
            category_id INTEGER NOT NULL,
            amount REAL NOT NULL,
            timestamp TEXT NOT NULL,
            FOREIGN KEY (profile_id) REFERENCES Profiles(id),
            FOREIGN KEY (category_id) REFERENCES Categories(id)
        )
    )";
    if (!query.exec(createOutlaysTable)) {
        qDebug() << "Couldn't create the Outlays table:" << query.lastError();
        return false;
    }

    qDebug() << "All tables created successfully.";
    return true;
}

void SqliteDBManager::populateCategories() {
    QSqlQuery query;

    QStringList categories = {
        "Продукти", "Транспорт", "Комунальні послуги", "Розваги", "Здоров'я",
        "Шопінг", "Освіта", "Платежі в інтернеті", "Подорожі", "Їжа на винос",
        "Автомобіль", "Подарунки", "Фітнес", "Кредити та борги", "Ремонт"
    };

    QStringList mandatoryFlags = {
        "1", "0", "1", "0", "1", // Продукти, Транспорт, Комунальні послуги, Розваги, Здоров'я
        "0", "1", "0", "0", "0", // Шопінг, Освіта, Платежі в інтернеті, Подорожі, Їжа на винос
        "1", "0", "0", "1", "0"  // Автомобіль, Подарунки, Фітнес, Кредити та борги, Ремонт
    };


    for (int i = 0; i < categories.size(); ++i) {
        query.prepare("INSERT INTO Categories (category_name, is_mandatory) VALUES (:name, :mandatory)");
        query.bindValue(":name", categories[i]);
        query.bindValue(":mandatory", mandatoryFlags[i]);
        if (!query.exec()) {
            qDebug() << "Couldn't insert into Categories:" << query.lastError();
        }
    }

    qDebug() << "Categories populated successfully.";
}

bool SqliteDBManager::insertProfile(Profile *profile) {
    QSqlQuery query;
    query.prepare("INSERT INTO Profiles (profile_name, monthly_budget) VALUES (:name, :budget)");
    query.bindValue(":name", profile->gatName());
    query.bindValue(":budget", profile->getMonthlyBudget());

    if (!query.exec()) {
        qDebug() << "Couldn't insert into Profiles:" << query.lastError();
        return false;
    }

    qDebug() << "Profile inserted successfully.";
    return true;
}

bool SqliteDBManager::insertOutlay(Outlay *outlay) {
    QSqlQuery query;

    query.prepare("INSERT INTO Outlays (name, profile_id, category_id, amount, timestamp) "
                  "VALUES (:name, :profile_id, :category_id, :amount, :timestamp)");
    query.bindValue(":name", outlay->getName());
    query.bindValue(":profile_id", outlay->getProfileId());
    query.bindValue(":category_id", outlay->getCategoryId());
    query.bindValue(":amount", outlay->getAmount());
    query.bindValue(":timestamp", outlay->getTimestamp());

    if (!query.exec()) {
        qDebug() << "Couldn't insert into Outlays:" << query.lastError();
        return false;
    }

    qDebug() << "Outlay inserted successfully.";
    return true;
}

bool SqliteDBManager::isTableEmpty(const QString &tableName) {
    QSqlQuery query;
    query.prepare(QString("SELECT COUNT(*) FROM %1").arg(tableName));

    if (!query.exec()) {
        qDebug() << "Couldn't check if table is empty:" << query.lastError();
        return false;
    }

    if (query.next()) {
        int count = query.value(0).toInt();
        return count == 0;
    }

    return false;
}

