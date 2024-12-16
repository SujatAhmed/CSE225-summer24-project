#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "linkedlist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();
    void on_createAccountButton_clicked();
    void on_memberTypeComboBox_activated(int index);

private:
    Ui::MainWindow *ui;
    LinkedList users;

    void initializeCSV(); // Ensures CSV exists with headers
    bool isStrongPassword(const QString &password);
    bool userExists(const QString &userId);
    bool addUserToCsv(const QString &name, const QString &userId, const QString &password, const QString &memberType);
    bool validateLogin(const QString &userId, const QString &password, const QString &memberType);
    bool deleteUserFromCsv(const QString &userId); // Admin only
};

#endif // MAINWINDOW_H
