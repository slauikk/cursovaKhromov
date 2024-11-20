/********************************************************************************
** Form generated from reading UI file 'exchangedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXCHANGEDIALOG_H
#define UI_EXCHANGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExchangeDialog
{
public:
    QGridLayout *gridLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label;
    QDoubleSpinBox *dsb_uahTousd;
    QLabel *l_usd;
    QLabel *label_4;
    QLabel *label_2;
    QDoubleSpinBox *dsb_uahToeur;
    QLabel *l_eur;
    QWidget *page_2;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QLabel *label_5;
    QDoubleSpinBox *dsb_usdTouah;
    QLabel *l_uahFromusd;
    QLabel *label_7;
    QLabel *label_6;
    QDoubleSpinBox *dsb_eurTouah;
    QLabel *l_uahFromeur;
    QGridLayout *gridLayout_3;
    QPushButton *pb_changePage;
    QPushButton *pb_cancel;

    void setupUi(QDialog *ExchangeDialog)
    {
        if (ExchangeDialog->objectName().isEmpty())
            ExchangeDialog->setObjectName("ExchangeDialog");
        ExchangeDialog->resize(309, 203);
        gridLayout_4 = new QGridLayout(ExchangeDialog);
        gridLayout_4->setObjectName("gridLayout_4");
        stackedWidget = new QStackedWidget(ExchangeDialog);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        gridLayout_5 = new QGridLayout(page);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label = new QLabel(page);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 1, 1, 1);

        dsb_uahTousd = new QDoubleSpinBox(page);
        dsb_uahTousd->setObjectName("dsb_uahTousd");
        dsb_uahTousd->setMaximum(9999999.990000000223517);

        gridLayout->addWidget(dsb_uahTousd, 1, 0, 1, 1);

        l_usd = new QLabel(page);
        l_usd->setObjectName("l_usd");

        gridLayout->addWidget(l_usd, 1, 1, 1, 1);

        label_4 = new QLabel(page);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        dsb_uahToeur = new QDoubleSpinBox(page);
        dsb_uahToeur->setObjectName("dsb_uahToeur");
        dsb_uahToeur->setMaximum(9999999.990000000223517);

        gridLayout->addWidget(dsb_uahToeur, 3, 0, 1, 1);

        l_eur = new QLabel(page);
        l_eur->setObjectName("l_eur");

        gridLayout->addWidget(l_eur, 3, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        gridLayout_6 = new QGridLayout(page_2);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label_8 = new QLabel(page_2);
        label_8->setObjectName("label_8");

        gridLayout_2->addWidget(label_8, 0, 0, 1, 1);

        label_5 = new QLabel(page_2);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 0, 1, 1, 1);

        dsb_usdTouah = new QDoubleSpinBox(page_2);
        dsb_usdTouah->setObjectName("dsb_usdTouah");
        dsb_usdTouah->setMaximum(9999999.990000000223517);

        gridLayout_2->addWidget(dsb_usdTouah, 1, 0, 1, 1);

        l_uahFromusd = new QLabel(page_2);
        l_uahFromusd->setObjectName("l_uahFromusd");

        gridLayout_2->addWidget(l_uahFromusd, 1, 1, 1, 1);

        label_7 = new QLabel(page_2);
        label_7->setObjectName("label_7");

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        label_6 = new QLabel(page_2);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 2, 1, 1, 1);

        dsb_eurTouah = new QDoubleSpinBox(page_2);
        dsb_eurTouah->setObjectName("dsb_eurTouah");
        dsb_eurTouah->setMaximum(9999999.990000000223517);

        gridLayout_2->addWidget(dsb_eurTouah, 3, 0, 1, 1);

        l_uahFromeur = new QLabel(page_2);
        l_uahFromeur->setObjectName("l_uahFromeur");

        gridLayout_2->addWidget(l_uahFromeur, 3, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_2, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);

        gridLayout_4->addWidget(stackedWidget, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        pb_changePage = new QPushButton(ExchangeDialog);
        pb_changePage->setObjectName("pb_changePage");

        gridLayout_3->addWidget(pb_changePage, 0, 0, 1, 1);

        pb_cancel = new QPushButton(ExchangeDialog);
        pb_cancel->setObjectName("pb_cancel");

        gridLayout_3->addWidget(pb_cancel, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 1, 0, 1, 1);


        retranslateUi(ExchangeDialog);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ExchangeDialog);
    } // setupUi

    void retranslateUi(QDialog *ExchangeDialog)
    {
        ExchangeDialog->setWindowTitle(QCoreApplication::translate("ExchangeDialog", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("ExchangeDialog", "UAH", nullptr));
        label->setText(QCoreApplication::translate("ExchangeDialog", "USD", nullptr));
        l_usd->setText(QString());
        label_4->setText(QCoreApplication::translate("ExchangeDialog", "UAH", nullptr));
        label_2->setText(QCoreApplication::translate("ExchangeDialog", "EUR", nullptr));
        l_eur->setText(QString());
        label_8->setText(QCoreApplication::translate("ExchangeDialog", "USD", nullptr));
        label_5->setText(QCoreApplication::translate("ExchangeDialog", "UAH", nullptr));
        l_uahFromusd->setText(QString());
        label_7->setText(QCoreApplication::translate("ExchangeDialog", "EUR", nullptr));
        label_6->setText(QCoreApplication::translate("ExchangeDialog", "UAH", nullptr));
        l_uahFromeur->setText(QString());
        pb_changePage->setText(QCoreApplication::translate("ExchangeDialog", "\320\227\320\274\321\226\320\275\320\270\321\202\320\270 \320\276\321\200\321\226\321\224\320\275\321\202\320\260\321\206\321\226\321\216", nullptr));
        pb_cancel->setText(QCoreApplication::translate("ExchangeDialog", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExchangeDialog: public Ui_ExchangeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXCHANGEDIALOG_H
