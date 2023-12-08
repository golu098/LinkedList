#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {};
};

class SingleLinkedList {
private:
    Node* head;

public:
    SingleLinkedList() : head(nullptr) {}

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtPosition(int value, int position) {
        Node* newNode = new Node(value);

        if (position == 0) {
            insertAtHead(value);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void deletionAtHead() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deletionAtTail() {
        if (head == nullptr) {
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    void deletionAtPosition(int position) {
        if (head == nullptr) {
            return;
        }

        if (position == 0) {
            deletionAtHead();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SingleLinkedList obj;

    int choice, value, position;

    do {
        cout << "1. Insert at head\n2. Insert at position\n3. Insert at tail\n";
        cout << "4. Delete at head\n5. Delete at tail\n6. Delete at position\n";
        cout << "7. Display\n8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at head: ";
            cin >> value;
            obj.insertAtHead(value);
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter position to insert: ";
            cin >> position;
            obj.insertAtPosition(value, position);
            break;
        case 3:
            cout << "Enter value to insert at tail: ";
            cin >> value;
            obj.insertAtTail(value);
            break;
        case 4:
            obj.deletionAtHead();
            break;
        case 5:
            obj.deletionAtTail();
            break;
        case 6:
            cout << "Enter position to delete: ";
            cin >> position;
            obj.deletionAtPosition(position);
            break;
        case 7:
            obj.display();
            break;
        case 8:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 8);

    return 0;
}
