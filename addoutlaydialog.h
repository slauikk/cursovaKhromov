#ifndef ADDOUTLAYDIALOG_H
#define ADDOUTLAYDIALOG_H

#include <QDialog>

namespace Ui {
class addOutlayDialog;
}

class AddOutlayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddOutlayDialog(QWidget *parent = nullptr);
    ~AddOutlayDialog();

private slots:
    void on_pb_create_clicked();

    void on_pb_cancel_clicked();

private:
    Ui::addOutlayDialog *ui;
};

#endif // ADDOUTLAYDIALOG_H
