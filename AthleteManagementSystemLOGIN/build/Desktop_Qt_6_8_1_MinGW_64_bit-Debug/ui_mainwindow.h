/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *nameInput;
    QLabel *label_2;
    QLineEdit *userIdInput;
    QLabel *label_3;
    QLineEdit *passwordInput;
    QLabel *label_4;
    QComboBox *memberTypeComboBox;
    QLabel *label_5;
    QLineEdit *adminCodeInput;
    QPushButton *loginButton;
    QPushButton *createAccountButton;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        formLayout_2 = new QFormLayout(centralwidget);
        formLayout_2->setObjectName("formLayout_2");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(6);
        formLayout->setVerticalSpacing(0);
        formLayout->setContentsMargins(15, -1, -1, -1);
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        nameInput = new QLineEdit(centralwidget);
        nameInput->setObjectName("nameInput");

        formLayout->setWidget(0, QFormLayout::FieldRole, nameInput);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        userIdInput = new QLineEdit(centralwidget);
        userIdInput->setObjectName("userIdInput");

        formLayout->setWidget(1, QFormLayout::FieldRole, userIdInput);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        passwordInput = new QLineEdit(centralwidget);
        passwordInput->setObjectName("passwordInput");

        formLayout->setWidget(2, QFormLayout::FieldRole, passwordInput);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        memberTypeComboBox = new QComboBox(centralwidget);
        memberTypeComboBox->addItem(QString());
        memberTypeComboBox->addItem(QString());
        memberTypeComboBox->setObjectName("memberTypeComboBox");

        formLayout->setWidget(3, QFormLayout::FieldRole, memberTypeComboBox);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        adminCodeInput = new QLineEdit(centralwidget);
        adminCodeInput->setObjectName("adminCodeInput");

        formLayout->setWidget(4, QFormLayout::FieldRole, adminCodeInput);

        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");

        formLayout->setWidget(5, QFormLayout::FieldRole, loginButton);

        createAccountButton = new QPushButton(centralwidget);
        createAccountButton->setObjectName("createAccountButton");

        formLayout->setWidget(6, QFormLayout::FieldRole, createAccountButton);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, formLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        nameInput->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "USER ID", nullptr));
        userIdInput->setText(QCoreApplication::translate("MainWindow", "User ID", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        passwordInput->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Member Type", nullptr));
        memberTypeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "User", nullptr));
        memberTypeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Administrator", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "Admin Code", nullptr));
        adminCodeInput->setText(QCoreApplication::translate("MainWindow", "Admin Code", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        createAccountButton->setText(QCoreApplication::translate("MainWindow", "Create Account", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "if no account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
