#ifndef TABLEVIEWERWINDOW_H
#define TABLEVIEWERWINDOW_H

#include <QMainWindow>
#include <QString>
#include <string>

namespace Ui {
class TableViewerWindow;
}

class TableViewerWindow : public QMainWindow
{
    Q_OBJECT

public:
    TableViewerWindow(QWidget *parent = nullptr);
    ~TableViewerWindow();

private:
    Ui::TableViewerWindow *ui;
};

#endif // TABLEVIEWERWINDOW_H
