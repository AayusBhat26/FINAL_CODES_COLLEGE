#include <bits/stdc++.h>
using namespace std;

// Function to validate if the input is a valid integer
bool isValidNumber(string &str) {
    if (str.empty())
        return false;
    int start = (str[0] == '-') ? 1 : 0;
    for (int i = start; i < str.length(); i++) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

// Function to get valid integer input
int getValidInteger() {
    string input;
    while (true) {
        cin >> input;
        if (isValidNumber(input)) {
            return stoi(input);
        } else {
            cout << "Invalid input. Please enter a valid integer: ";
        }
    }
}

// Node structure for doubly linked list
struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node *head = nullptr;

// Function to display the list
void display() {
    if (head == nullptr) {
        cout << "\n\n List is empty, need to add new elements\n";
        return;
    }
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// Function to add a node at the start
void addAtStart(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    if (head == nullptr) {
        cout << "\nLinked list is empty, creating a list \n";
        head = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
    } else {
        newNode->next = head;
        newNode->prev = nullptr;
        head->prev = newNode;
        head = newNode;
    }
    display();
}

// Function to add a node at the end
void addAtEnd(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        cout << "\nList is empty\n";
        head = newNode;
        newNode->prev = nullptr;
    } else {
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    display();
}

// Function to add a node after a given target value
void addAtGivenPosition(int target, int value) {
    if (head == nullptr) {
        cout << "\nList is empty\n";
        return;
    }

    Node *temp = head;

    // Traverse the list to find the target node
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }

    // If target node is not found
    if (temp == nullptr) {
        cout << "Target value not found in the list.\n";
        return;
    }

    // Create the new node
    Node *newNode = new Node();
    newNode->data = value;

    // Inserting at the end if the target node is the last node
    if (temp->next == nullptr) {
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = nullptr;
    } else {
        // Inserting in between
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    display();
}

// Function to delete a node from the start
void deleteFromStart() {
    if (head == nullptr) {
        cout << "\n\n List is empty\n";
        return;
    } else {
        Node *temp = head;
        // If it's the only node
        if (head->next == nullptr) {
            head = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }
    display();
}

// Function to delete a node from the end
void deleteFromEnd() {
    if (head == nullptr) {
        cout << "\n\n List is empty\n";
        return;
    } else {
        // If there's only one node
        if (head->next == nullptr) {
            head = nullptr;
        } else {
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->prev->next = nullptr;
            delete temp;
        }
    }
    display();
}

// Function to delete a node with a target value
void deleteTarget(int target) {
    if (head == nullptr) {
        cout << "\n\nLinked list is empty\n";
        return;
    }

    // If the head node is the target
    if (head->data == target) {
        deleteFromStart();
        return;
    }

    Node *temp = head;

    // Traverse the list to find the target node
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }

    // If target not found in the list
    if (temp == nullptr) {
        cout << "\nTarget value not found in the list\n";
        return;
    }

    // If the target is the last node
    if (temp->next == nullptr) {
        deleteFromEnd();
    } else {
        // Unlink the node from the list
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
    display();
}


int main() {
    int choice, value, target;
    do {
        cout << "\nDoubly Linked List Operations Menu:\n";
        cout << "1. Add at Start\n";
        cout << "2. Add at End\n";
        cout << "3. Add after a Target Node\n";
        cout << "4. Delete from Start\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete Target Node\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        choice = getValidInteger();

        switch (choice) {
        case 1:
            cout << "Enter value to add at start: ";
            value = getValidInteger();
            addAtStart(value);
            break;
        case 2:
            cout << "Enter value to add at end: ";
            value = getValidInteger();
            addAtEnd(value);
            break;
        case 3:
            cout << "Enter target node value: ";
            target = getValidInteger();
            cout << "Enter value to add after " << target << ": ";
            value = getValidInteger();
            addAtGivenPosition(target, value);
            break;
        case 4:
            deleteFromStart();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            cout << "Enter target value to delete: ";
            target = getValidInteger();
            deleteTarget(target);
            break;
        case 7:
            display();
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);
    return 0;
}
