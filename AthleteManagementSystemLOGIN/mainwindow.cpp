#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    initializeCSV();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::initializeCSV() {
    QFile file("members.csv");
    if (!file.exists()) {
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << "Name,UserId,Password,MemberType\n"; // Headers
            file.close();
        }
    }
}
/*
bool MainWindow::isStrongPassword(const QString &password) {
    password.contains(QRegExp("[A-Z]")) &&
        password.contains(QRegExp("[a-z]")) &&
        password.contains(QRegExp("[0-9]"));
}   return password.length() >= 8 &&
 */

void MainWindow::on_createAccountButton_clicked() {
    QString name = ui->nameInput->text();
    QString userId = ui->userIdInput->text();
    QString password = ui->passwordInput->text();
    QString memberType = ui->memberTypeComboBox->currentText();
    QString adminCode = ui->adminCodeInput->text();

    if (name.isEmpty() || userId.isEmpty() || password.isEmpty() || memberType.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields are required.");
        return;
    }

    if (memberType == "Administrator" && adminCode != "AthMng") {
        QMessageBox::warning(this, "Admin Code Error", "Invalid admin code.");
        return;
    }

    /*
    if (!isStrongPassword(password)) {
        QMessageBox::warning(this, "Password Error", "Password must be at least 8 characters long and contain uppercase, lowercase, and a number.");
        return;
    }
    */

    if (userExists(userId)) {
        QMessageBox::warning(this, "Error", "User ID already exists.");
        return;
    }

    if (addUserToCsv(name, userId, password, memberType)) {
        QMessageBox::information(this, "Success", "Account created successfully!");
        ui->nameInput->clear();
        ui->userIdInput->clear();
        ui->passwordInput->clear();
        ui->adminCodeInput->clear();
    } else {
        QMessageBox::critical(this, "Error", "Failed to create account.");
    }
}

void MainWindow::on_loginButton_clicked() {
    QString userId = ui->userIdInput->text();
    QString password = ui->passwordInput->text();
    QString memberType = ui->memberTypeComboBox->currentText();

    if (userId.isEmpty() || password.isEmpty() || memberType.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields are required.");
        return;
    }

    if (validateLogin(userId, password, memberType)) {
        QMessageBox::information(this, "Login Success", "Welcome, " + userId + "!");
        ui->userIdInput->clear();
        ui->passwordInput->clear();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid credentials.");
    }
}

bool MainWindow::userExists(const QString &userId) {
    QFile file("members.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream in(&file);
    QString line;
    while (in.readLineInto(&line)) {
        QStringList fields = line.split(",");
        if (fields.size() > 1 && fields[1] == userId) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

bool MainWindow::addUserToCsv(const QString &name, const QString &userId, const QString &password, const QString &memberType) {
    QFile file("members.csv");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        return false;
    }

    QTextStream out(&file);
    out << name << "," << userId << "," << password << "," << memberType << "\n";
    file.close();
    return true;
}

bool MainWindow::validateLogin(const QString &userId, const QString &password, const QString &memberType) {
    QFile file("members.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream in(&file);
    QString line;
    while (in.readLineInto(&line)) {
        QStringList fields = line.split(",");
        if (fields.size() >= 4 && fields[1] == userId && fields[2] == password && fields[3] == memberType) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}
