#ifndef ADDPROFILEDIALOG_H
#define ADDPROFILEDIALOG_H

#include <QDialog>

namespace Ui {
class AddProfileDialog;
}

class AddProfileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddProfileDialog(QWidget *parent = nullptr);
    ~AddProfileDialog();

private slots:
    void on_pb_create_clicked();

    void on_pb_cancel_clicked();

private:
    Ui::AddProfileDialog *ui;
};

#endif // ADDPROFILEDIALOG_H
