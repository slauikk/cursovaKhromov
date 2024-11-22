#ifndef SQLITEDBMANAGER_H
#define SQLITEDBMANAGER_H

#include <QString>
#include <QSqlDatabase>
#include "Profile.h"
#include "Outlay.h"

class SqliteDBManager {
public:
    explicit SqliteDBManager(const QString &path);
    ~SqliteDBManager();

    bool isConnected() const;
    bool createTables();
    bool insertProfile(Profile *profile);
    bool insertOutlay(Outlay *outlay);

private:
    QSqlDatabase db;

    bool isTableEmpty(const QString &tableName);
    void populateCategories();
};

#endif // SQLITEDBMANAGER_H
