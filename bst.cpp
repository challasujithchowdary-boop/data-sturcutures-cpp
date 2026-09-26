
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node
Node* createNode(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a value into BST
Node* insert(Node* root, int value) {

    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Search for a value
bool search(Node* root, int value) {

    if (root == NULL) {
        return false;
    }

    if (root->data == value) {
        return true;
    }

    if (value < root->data) {
        return search(root->left, value);
    }

    return search(root->right, value);
}

// Find minimum value
Node* findMin(Node* root) {

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

// Delete a value
Node* deleteNode(Node* root, int value) {

    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {

        // No left child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // No right child
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Two children
        Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Inorder traversal
void inorder(Node* root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/*
Complexity Analysis:

Average case:
Insert  : O(log n)
Search  : O(log n)
Delete  : O(log n)

Worst case:
Insert  : O(n)
Search  : O(n)
Delete  : O(n)

Inorder Traversal: O(n)

Space Complexity: O(n)
*/

int main() {

    Node* root = NULL;

    int choice;
    int value;

    while (true) {

        cout << "\n===== BINARY SEARCH TREE =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;

                root = insert(root, value);

                cout << value << " inserted successfully.\n";
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;

                if (search(root, value)) {
                    root = deleteNode(root, value);
                    cout << value << " deleted successfully.\n";
                }
                else {
                    cout << value << " not found.\n";
                }

                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;

                if (search(root, value)) {
                    cout << value << " found in BST.\n";
                }
                else {
                    cout << value << " not found.\n";
                }

                break;

            case 4:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Program ended.\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }
}
