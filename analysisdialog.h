#ifndef ANALYSISDIALOG_H
#define ANALYSISDIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class AnalysisDialog;
}

class AnalysisDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AnalysisDialog(QWidget *parent = nullptr);
    ~AnalysisDialog();

    void setProfileId(int id);

private slots:
    void on_pb_cancel_clicked();

private:
    Ui::AnalysisDialog *ui;
    int profileId;

    void updateLabels();
};

#endif // ANALYSISDIALOG_H
