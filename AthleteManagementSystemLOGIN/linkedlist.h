#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <QString>

struct Node {
    QString name;
    QString userId;
    QString password;
    QString memberType;
    Node *next;
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList();
    ~LinkedList();

    void insert(const QString &name, const QString &userId, const QString &password, const QString &memberType);
    bool remove(const QString &userId);
    Node* find(const QString &userId);
    void loadFromCSV(const QString &filename);
    void saveToCSV(const QString &filename);
    QString displayAll(); // For debugging purposes
};

#endif // LINKEDLIST_H
