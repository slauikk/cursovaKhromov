#ifndef ADDPROFILEDIALOG_H
#define ADDPROFILEDIALOG_H

#include <QDialog>
#include "Profile.h"

namespace Ui {
class AddProfileDialog;
}

class AddProfileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddProfileDialog(QWidget *parent = nullptr);
    ~AddProfileDialog();

signals:
    void profileCreated(Profile *profile);

private slots:
    void on_pb_create_clicked();
    void on_pb_cancel_clicked();

private:
    Ui::AddProfileDialog *ui;

    bool isNameUnique(const QString &name);
};

#endif // ADDPROFILEDIALOG_H
