/********************************************************************************
** Form generated from reading UI file 'analysisdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYSISDIALOG_H
#define UI_ANALYSISDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnalysisDialog
{
public:
    QComboBox *comboBox;
    QPushButton *pb_cancel;
    QPushButton *pb_calculate;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *l_notNecessarily;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_3;
    QLabel *l_saving;
    QLabel *label_5;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_4;
    QLabel *label_7;
    QLabel *l_spentNecessarily;
    QWidget *layoutWidget_4;
    QGridLayout *gridLayout_5;
    QLabel *label_9;
    QLabel *l_spentNotNecessarily;
    QWidget *layoutWidget_5;
    QGridLayout *gridLayout_6;
    QLabel *label_11;
    QLabel *l_remainder;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *l_maxNecessarily;

    void setupUi(QDialog *AnalysisDialog)
    {
        if (AnalysisDialog->objectName().isEmpty())
            AnalysisDialog->setObjectName("AnalysisDialog");
        AnalysisDialog->resize(673, 413);
        comboBox = new QComboBox(AnalysisDialog);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(50, 100, 121, 28));
        pb_cancel = new QPushButton(AnalysisDialog);
        pb_cancel->setObjectName("pb_cancel");
        pb_cancel->setGeometry(QRect(50, 230, 121, 29));
        pb_calculate = new QPushButton(AnalysisDialog);
        pb_calculate->setObjectName("pb_calculate");
        pb_calculate->setGeometry(QRect(50, 170, 121, 29));
        layoutWidget = new QWidget(AnalysisDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(380, 100, 110, 49));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        l_notNecessarily = new QLabel(layoutWidget);
        l_notNecessarily->setObjectName("l_notNecessarily");

        gridLayout_2->addWidget(l_notNecessarily, 1, 0, 1, 1);

        layoutWidget_2 = new QWidget(AnalysisDialog);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(540, 100, 68, 49));
        gridLayout_3 = new QGridLayout(layoutWidget_2);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        l_saving = new QLabel(layoutWidget_2);
        l_saving->setObjectName("l_saving");

        gridLayout_3->addWidget(l_saving, 2, 0, 1, 1);

        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName("label_5");

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        layoutWidget_3 = new QWidget(AnalysisDialog);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(210, 210, 141, 49));
        gridLayout_4 = new QGridLayout(layoutWidget_3);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_3);
        label_7->setObjectName("label_7");

        gridLayout_4->addWidget(label_7, 0, 0, 1, 1);

        l_spentNecessarily = new QLabel(layoutWidget_3);
        l_spentNecessarily->setObjectName("l_spentNecessarily");

        gridLayout_4->addWidget(l_spentNecessarily, 1, 0, 1, 1);

        layoutWidget_4 = new QWidget(AnalysisDialog);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(370, 210, 161, 49));
        gridLayout_5 = new QGridLayout(layoutWidget_4);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget_4);
        label_9->setObjectName("label_9");

        gridLayout_5->addWidget(label_9, 0, 0, 1, 1);

        l_spentNotNecessarily = new QLabel(layoutWidget_4);
        l_spentNotNecessarily->setObjectName("l_spentNotNecessarily");

        gridLayout_5->addWidget(l_spentNotNecessarily, 1, 0, 1, 1);

        layoutWidget_5 = new QWidget(AnalysisDialog);
        layoutWidget_5->setObjectName("layoutWidget_5");
        layoutWidget_5->setGeometry(QRect(550, 210, 65, 49));
        gridLayout_6 = new QGridLayout(layoutWidget_5);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget_5);
        label_11->setObjectName("label_11");

        gridLayout_6->addWidget(label_11, 0, 0, 1, 1);

        l_remainder = new QLabel(layoutWidget_5);
        l_remainder->setObjectName("l_remainder");

        gridLayout_6->addWidget(l_remainder, 1, 0, 1, 1);

        widget = new QWidget(AnalysisDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(200, 100, 154, 49));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        l_maxNecessarily = new QLabel(widget);
        l_maxNecessarily->setObjectName("l_maxNecessarily");

        gridLayout->addWidget(l_maxNecessarily, 1, 0, 1, 1);


        retranslateUi(AnalysisDialog);

        QMetaObject::connectSlotsByName(AnalysisDialog);
    } // setupUi

    void retranslateUi(QDialog *AnalysisDialog)
    {
        AnalysisDialog->setWindowTitle(QCoreApplication::translate("AnalysisDialog", "Dialog", nullptr));
        pb_cancel->setText(QCoreApplication::translate("AnalysisDialog", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        pb_calculate->setText(QCoreApplication::translate("AnalysisDialog", "\320\236\320\261\321\207\320\270\321\201\320\273\320\270\321\202\320\270", nullptr));
        label_3->setText(QCoreApplication::translate("AnalysisDialog", "\320\235\320\265 \320\276\320\261\320\276\320\262'\321\217\320\267\320\272\320\276\320\262\320\265", nullptr));
        l_notNecessarily->setText(QString());
        l_saving->setText(QString());
        label_5->setText(QCoreApplication::translate("AnalysisDialog", "\320\222\321\226\320\264\320\272\320\273\320\260\321\201\321\202\320\270", nullptr));
        label_7->setText(QCoreApplication::translate("AnalysisDialog", "\320\222\320\270\321\202\321\200\320\260\321\207\320\265\320\275\320\276 \320\275\320\260 \320\276\320\261\320\276\320\262.", nullptr));
        l_spentNecessarily->setText(QString());
        label_9->setText(QCoreApplication::translate("AnalysisDialog", "\320\222\320\270\321\202\321\200\320\260\321\207\320\265\320\275\320\276 \320\275\320\260 \320\275\320\265 \320\276\320\261\320\276\320\262.", nullptr));
        l_spentNotNecessarily->setText(QString());
        label_11->setText(QCoreApplication::translate("AnalysisDialog", "\320\227\320\260\320\273\320\270\321\210\320\276\320\272", nullptr));
        l_remainder->setText(QString());
        label->setText(QCoreApplication::translate("AnalysisDialog", "\320\234\320\260\320\272\321\201. \320\275\320\260 \320\276\320\261\320\276\320\262'\321\217\320\267\320\272\320\276\320\262\320\265 ", nullptr));
        l_maxNecessarily->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AnalysisDialog: public Ui_AnalysisDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYSISDIALOG_H
