#include <iostream>

using namespace std;

//class Node {
//public:
//    int data;
//    Node* next;
//    Node* prev;
//
//    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
//};
//
//class DoublyLinkedList {
//private:
//    Node* head;
//    Node* tail;
//
//public:
//    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
//
//    ~DoublyLinkedList() {
//        while (head) {
//            Node* temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//
//    void addToFront(int data) {
//        Node* newNode = new Node(data);
//        if (!newNode) throw "Memory allocation failed";
//        if (!head) {
//            head = tail = newNode;
//        }
//        else {
//            newNode->next = head;
//            head->prev = newNode;
//            head = newNode;
//        }
//    }
//
//    void removeFromFront() {
//        if (!head) throw "Cannot remove from an empty list";
//        Node* temp = head;
//        if (head == tail) {
//            head = tail = nullptr;
//        }
//        else {
//            head = head->next;
//            head->prev = nullptr;
//        }
//        delete temp;
//    }
//
//    void display() const {
//        if (!head) throw "List is empty";
//        Node* temp = head;
//        while (temp) {
//            cout << temp->data << " ";
//            temp = temp->next;
//        }
//        cout << endl;
//    }
//};
//
//int main() {
//    try {
//        DoublyLinkedList list;
//        list.addToFront(10);
//        list.addToFront(20);
//        list.display();
//
//        list.removeFromFront();
//        list.display();
//
//        list.removeFromFront();
//        list.display();
//    }
//    catch (const char* e) {
//        cerr << "Exception: " << e << endl;
//    }
//}


class CustomException {
public:
    virtual const char* what() const = 0;
};

class MathException : public CustomException {
public:
    const char* what() const override {
        return "Math error occurred";
    }
};

class DivisionByZeroException : public MathException {
public:
    const char* what() const override {
        return "Division by zero";
    }
};

class FileException : public CustomException {
public:
    const char* what() const override {
        return "File operation error occurred";
    }
};

class MemoryException : public CustomException {
public:
    const char* what() const override {
        return "Memory allocation failed";
    }
};

int main() {
    try {
        throw DivisionByZeroException();
    }
    catch (const CustomException& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    try {
        throw MemoryException();
    }
    catch (const CustomException& e) {
        cerr << "Exception: " << e.what() << endl;
    }

}

