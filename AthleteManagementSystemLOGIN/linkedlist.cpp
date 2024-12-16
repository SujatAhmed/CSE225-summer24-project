#include "linkedlist.h"
#include <QFile>
#include <QTextStream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    while (head) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insert(const QString &name, const QString &userId, const QString &password, const QString &memberType) {
    Node *newNode = new Node{name, userId, password, memberType, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

bool LinkedList::remove(const QString &userId) {
    Node *current = head, *prev = nullptr;
    while (current) {
        if (current->userId == userId) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

Node* LinkedList::find(const QString &userId) {
    Node *current = head;
    while (current) {
        if (current->userId == userId) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void LinkedList::loadFromCSV(const QString &filename) {
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        QString line;
        bool firstLine = true; // Skip headers
        while (!in.atEnd()) {
            line = in.readLine();
            if (firstLine) {
                firstLine = false;
                continue;
            }
            auto parts = line.split(",");
            if (parts.size() == 4) {
                insert(parts[0], parts[1], parts[2], parts[3]);
            }
        }
        file.close();
    }
}

void LinkedList::saveToCSV(const QString &filename) {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << "Name,UserId,Password,MemberType\n"; // Add headers
        Node *current = head;
        while (current) {
            out << current->name << "," << current->userId << "," << current->password << "," << current->memberType << "\n";
            current = current->next;
        }
        file.close();
    }
}

QString LinkedList::displayAll() {
    QString result;
    Node *current = head;
    while (current) {
        result += current->name + " | " + current->userId + " | " + current->memberType + "\n";
        current = current->next;
    }
    return result;
}
