#ifndef ADDOUTLAYDIALOG_H
#define ADDOUTLAYDIALOG_H

#include <QDialog>
#include "sqlitedbmanager.h"
#include "outlay.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class addOutlayDialog;
}

class AddOutlayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddOutlayDialog(QWidget *parent = nullptr, SqliteDBManager* dbManager = nullptr);
    ~AddOutlayDialog();

    void setProfileId(int id);

signals:
    void outlayCreated(Outlay* outlay);

private slots:
    void on_pb_create_clicked();
    void on_pb_cancel_clicked();

private:
    Ui::addOutlayDialog *ui;
    int profileId;
    SqliteDBManager* dbManager;

    bool loadCategories();
    bool validateInputs();
};

#endif // ADDOUTLAYDIALOG_H
