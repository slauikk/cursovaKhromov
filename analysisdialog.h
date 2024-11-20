#ifndef ANALYSISDIALOG_H
#define ANALYSISDIALOG_H

#include <QDialog>

namespace Ui {
class AnalysisDialog;
}

class AnalysisDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AnalysisDialog(QWidget *parent = nullptr);
    ~AnalysisDialog();

private slots:
    void on_pb_calculate_clicked();

    void on_pb_cancel_clicked();

private:
    Ui::AnalysisDialog *ui;
};

#endif // ANALYSISDIALOG_H
