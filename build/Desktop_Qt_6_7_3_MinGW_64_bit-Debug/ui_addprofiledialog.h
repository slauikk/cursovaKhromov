/********************************************************************************
** Form generated from reading UI file 'addprofiledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPROFILEDIALOG_H
#define UI_ADDPROFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_AddProfileDialog
{
public:
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *le_name;
    QLineEdit *le_monthlyBudget;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_2;
    QPushButton *pb_create;
    QPushButton *pb_cancel;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *AddProfileDialog)
    {
        if (AddProfileDialog->objectName().isEmpty())
            AddProfileDialog->setObjectName("AddProfileDialog");
        AddProfileDialog->resize(400, 300);
        gridLayout_5 = new QGridLayout(AddProfileDialog);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(AddProfileDialog);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(AddProfileDialog);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        le_name = new QLineEdit(AddProfileDialog);
        le_name->setObjectName("le_name");

        gridLayout->addWidget(le_name, 1, 0, 1, 1);

        le_monthlyBudget = new QLineEdit(AddProfileDialog);
        le_monthlyBudget->setObjectName("le_monthlyBudget");

        gridLayout->addWidget(le_monthlyBudget, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(48, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        pb_create = new QPushButton(AddProfileDialog);
        pb_create->setObjectName("pb_create");

        gridLayout_2->addWidget(pb_create, 0, 0, 1, 1);

        pb_cancel = new QPushButton(AddProfileDialog);
        pb_cancel->setObjectName("pb_cancel");

        gridLayout_2->addWidget(pb_cancel, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 2, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);


        retranslateUi(AddProfileDialog);

        QMetaObject::connectSlotsByName(AddProfileDialog);
    } // setupUi

    void retranslateUi(QDialog *AddProfileDialog)
    {
        AddProfileDialog->setWindowTitle(QCoreApplication::translate("AddProfileDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddProfileDialog", "\320\235\320\260\320\267\320\262\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("AddProfileDialog", "\320\234\321\226\321\201\321\217\321\207\320\275\320\270\320\271 \320\261\321\216\320\264\320\266\320\265\321\202", nullptr));
        pb_create->setText(QCoreApplication::translate("AddProfileDialog", "\320\241\321\202\320\262\320\276\321\200\320\270\321\202\320\270", nullptr));
        pb_cancel->setText(QCoreApplication::translate("AddProfileDialog", "\320\241\320\272\320\260\321\201\321\203\320\262\320\260\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddProfileDialog: public Ui_AddProfileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPROFILEDIALOG_H
