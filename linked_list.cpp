
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at the end
void insertNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << value << " inserted successfully.\n";
}

// Delete a node
void deleteNode(int value) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;

        cout << value << " deleted successfully.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << value << " not found.\n";
    } else {
        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;

        cout << value << " deleted successfully.\n";
    }
}

// Search for a node
void searchNode(int value) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == value) {
            cout << value << " found in the list.\n";
            return;
        }

        temp = temp->next;
    }

    cout << value << " not found.\n";
}

// Display the list
void display() {
    Node* temp = head;

    if (temp == NULL) {
        cout << "List is empty.\n";
        return;
    }

    cout << "Linked List: ";

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

/*
Complexity Analysis:

Insert: O(n)
Delete: O(n)
Search: O(n)
Display: O(n)

Space Complexity: O(n)
*/

int main() {

    int choice, value;

    while (true) {

        cout << "\n===== LINKED LIST =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertNode(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(value);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                searchNode(value);
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Program ended.\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }
}
