/********************************************************************************
** Form generated from reading UI file 'addoutlaydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDOUTLAYDIALOG_H
#define UI_ADDOUTLAYDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_addOutlayDialog
{
public:
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QPushButton *pb_create;
    QPushButton *pb_cancel;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QDateTimeEdit *dateTimeEdit;
    QLineEdit *le_amount;
    QLabel *label_2;
    QComboBox *cb_category;
    QLineEdit *le_name;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *addOutlayDialog)
    {
        if (addOutlayDialog->objectName().isEmpty())
            addOutlayDialog->setObjectName("addOutlayDialog");
        addOutlayDialog->resize(413, 232);
        gridLayout_5 = new QGridLayout(addOutlayDialog);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        pb_create = new QPushButton(addOutlayDialog);
        pb_create->setObjectName("pb_create");

        gridLayout_2->addWidget(pb_create, 0, 0, 1, 1);

        pb_cancel = new QPushButton(addOutlayDialog);
        pb_cancel->setObjectName("pb_cancel");

        gridLayout_2->addWidget(pb_cancel, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(88, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        dateTimeEdit = new QDateTimeEdit(addOutlayDialog);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setDate(QDate(2001, 1, 1));

        gridLayout->addWidget(dateTimeEdit, 3, 1, 1, 1);

        le_amount = new QLineEdit(addOutlayDialog);
        le_amount->setObjectName("le_amount");

        gridLayout->addWidget(le_amount, 3, 0, 1, 1);

        label_2 = new QLabel(addOutlayDialog);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        cb_category = new QComboBox(addOutlayDialog);
        cb_category->setObjectName("cb_category");

        gridLayout->addWidget(cb_category, 1, 1, 1, 1);

        le_name = new QLineEdit(addOutlayDialog);
        le_name->setObjectName("le_name");

        gridLayout->addWidget(le_name, 1, 0, 1, 1);

        label = new QLabel(addOutlayDialog);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(addOutlayDialog);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        label_4 = new QLabel(addOutlayDialog);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 2);


        gridLayout_4->addLayout(gridLayout_3, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 2, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);


        retranslateUi(addOutlayDialog);

        QMetaObject::connectSlotsByName(addOutlayDialog);
    } // setupUi

    void retranslateUi(QDialog *addOutlayDialog)
    {
        addOutlayDialog->setWindowTitle(QCoreApplication::translate("addOutlayDialog", "Dialog", nullptr));
        pb_create->setText(QCoreApplication::translate("addOutlayDialog", "\320\241\321\202\320\262\320\276\321\200\320\270\321\202\320\270", nullptr));
        pb_cancel->setText(QCoreApplication::translate("addOutlayDialog", "\320\241\320\272\320\260\321\201\321\203\320\262\320\260\321\202\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("addOutlayDialog", "\320\241\321\203\320\274\320\260", nullptr));
        label->setText(QCoreApplication::translate("addOutlayDialog", "\320\235\320\260\320\267\320\262\320\260 ", nullptr));
        label_3->setText(QCoreApplication::translate("addOutlayDialog", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\321\226\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("addOutlayDialog", "\320\224\320\260\321\202\320\260 \321\202\320\260 \321\207\320\260\321\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addOutlayDialog: public Ui_addOutlayDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDOUTLAYDIALOG_H
