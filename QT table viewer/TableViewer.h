// TableViewer.h
#ifndef TABLEVIEWER_H
#define TABLEVIEWER_H

#include <QWidget>
#include <QString>
#include <string>

class TableViewer : public QWidget {
public:
    TableViewer(const QString &csvFileName, const std::string &dataFolder, QWidget *parent = nullptr);

private:
    void setupTable(const QString &csvFileName, const std::string &dataFolder);
};

#endif // TABLEVIEWER_H
