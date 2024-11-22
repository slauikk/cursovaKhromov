/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pb_analysis;
    QPushButton *pb_exit;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *cb_profiles;
    QPushButton *pb_addProfile;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QTableView *tv_outlay;
    QSpacerItem *horizontalSpacer;
    QLineEdit *le_searchOutlay;
    QPushButton *pb_searchOutlay;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_addOutlay;
    QPushButton *pb_exchange;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1350, 897);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        pb_analysis = new QPushButton(centralwidget);
        pb_analysis->setObjectName("pb_analysis");

        gridLayout->addWidget(pb_analysis, 2, 3, 1, 1);

        pb_exit = new QPushButton(centralwidget);
        pb_exit->setObjectName("pb_exit");

        gridLayout->addWidget(pb_exit, 3, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(1325, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 4);

        cb_profiles = new QComboBox(centralwidget);
        cb_profiles->setObjectName("cb_profiles");

        gridLayout->addWidget(cb_profiles, 2, 0, 1, 1);

        pb_addProfile = new QPushButton(centralwidget);
        pb_addProfile->setObjectName("pb_addProfile");

        gridLayout->addWidget(pb_addProfile, 3, 0, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName("gridLayout_2");
        tv_outlay = new QTableView(tab);
        tv_outlay->setObjectName("tv_outlay");

        gridLayout_2->addWidget(tv_outlay, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(1068, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        le_searchOutlay = new QLineEdit(tab);
        le_searchOutlay->setObjectName("le_searchOutlay");

        gridLayout_2->addWidget(le_searchOutlay, 1, 1, 1, 1);

        pb_searchOutlay = new QPushButton(tab);
        pb_searchOutlay->setObjectName("pb_searchOutlay");

        gridLayout_2->addWidget(pb_searchOutlay, 1, 2, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");

        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 4);

        pb_addOutlay = new QPushButton(centralwidget);
        pb_addOutlay->setObjectName("pb_addOutlay");
        pb_addOutlay->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(pb_addOutlay, 2, 2, 1, 1);

        pb_exchange = new QPushButton(centralwidget);
        pb_exchange->setObjectName("pb_exchange");

        gridLayout->addWidget(pb_exchange, 3, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1350, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pb_analysis->setText(QCoreApplication::translate("MainWindow", "\320\220\320\275\320\260\320\273\321\226\320\267\320\260\321\202\320\276\321\200", nullptr));
        pb_exit->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\321\205\321\226\320\264", nullptr));
        pb_addProfile->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\264\320\260\321\202\320\270 \320\277\321\200\320\276\321\204\321\226\320\273\321\214", nullptr));
        pb_searchOutlay->setText(QCoreApplication::translate("MainWindow", "\320\250\321\203\320\272\320\260\321\202\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\320\224\321\226\320\260\320\263\321\200\320\260\320\274\320\260", nullptr));
        pb_addOutlay->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\264\320\260\321\202\320\270 \320\262\320\270\321\202\321\200\320\260\321\202\321\203", nullptr));
        pb_exchange->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\274\321\226\320\275 \320\262\320\260\320\273\321\216\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
