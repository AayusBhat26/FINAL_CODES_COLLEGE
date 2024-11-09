#include <bits/stdc++.h>
using namespace std;

// Check if the input string is a valid number
bool isValidNumber(const string &str) {
    if (str.empty()) return false;
    int start = (str[0] == '-') ? 1 : 0;
    for (int i = start; i < str.length(); i++) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}

// Get valid integer input from the user
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

// Singly linked list node
struct Node {
    int data;
    struct Node *next;
};

Node *head = nullptr;

// Display the linked list
void display() {
    Node *temp = head;
    if (temp == nullptr) {
        cout << "\nNothing to print, list is empty\n";
        return;
    }
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Insert a new node at the start
void insertAtStart(int value) {
    Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert a new node at the end
void insertAtEnd(int value) {
    if (head == nullptr) {
        cout << "\nLinked List is empty, inserting at start\n";
        insertAtStart(value);
        return;
    }
    Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    newNode->data = value;
    temp->next = newNode;
    newNode->next = nullptr;
}

// Insert a node after a given number
void insertAfterGivenNumber(int value, int target) {
    if (head == nullptr) {
        cout << "\nLinked list is currently empty, inserting at start\n";
        insertAtStart(value);
        return;
    }
    Node *temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "\nValue inserted: " << value << "\n";
    } else {
        cout << "\nTarget value " << target << " is not present in the linked list\n";
    }
}

// Insert multiple nodes after a given number
void insertMultipleAfterGivenNumber(int target) {
    if (head == nullptr) {
        cout << "\nThe linked list is currently empty, cannot insert after a target\n";
        return;
    }
    Node *temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        int numberOfNodes, value;
        cout << "\nTarget value found. Provide the number of nodes to insert: ";
        numberOfNodes = getValidInteger();
        if (numberOfNodes <= 0) {
            cout << "\nProvide a number of nodes greater than 0\n";
            return;
        }
        for (int i = 0; i < numberOfNodes; i++) {
            cout << "\nProvide the value for the new node: ";
            value = getValidInteger();
            Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode;
        }
    } else {
        cout << "\nTarget value " << target << " is not present in the linked list\n";
    }
}

// Insert multiple nodes at the start
void insertMultipleAtStart() {
    int numberOfNodes, value;
    cout << "\nProvide the number of nodes: ";
    numberOfNodes = getValidInteger();
    if (numberOfNodes <= 0) {
        cout << "Provide number of nodes greater than 0";
        return;
    }
    for (int i = 0; i < numberOfNodes; i++) {
        cout << "\nProvide the value for the new node: ";
        value = getValidInteger();
        insertAtStart(value);
    }
}

// Insert multiple nodes at the end
void insertMultipleAtEnd() {
    int numberOfNodes, value;
    cout << "\nProvide the number of nodes: ";
    numberOfNodes = getValidInteger();
    if (numberOfNodes <= 0) {
        cout << "\nProvide a number greater than 0\n";
        return;
    }
    for (int i = 0; i < numberOfNodes; i++) {
        cout << "\nProvide the value for the new node: ";
        value = getValidInteger();
        insertAtEnd(value);
    }
    display();
}

// Delete node from the start
void deleteFromStart() {
    if (head == nullptr) {
        cout << "\nList is empty\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    cout << "\nDeleted element: " << temp->data << endl;
    delete temp;
}

// Delete node from the end
void deleteFromEnd() {
    if (head == nullptr) {
        cout << "\nList is already empty\n";
        return;
    }
    if (head->next == nullptr) {
        cout << "Deleted Element: " << head->data << endl;
        delete head;
        head = nullptr;
        return;
    }
    Node *temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    cout << "\nDeleted Element: " << temp->next->data << endl;
    delete temp->next;
    temp->next = nullptr;
}

// Delete a given number
void deleteGivenNumber() {
    cout << "\nProvide the number you want to delete: ";
    int value = getValidInteger();
    if (head == nullptr) {
        cout << "\nList is empty\n";
        return;
    }
    if (head->data == value) {
        Node *temp = head;
        head = head->next;
        cout << "\nDeleted Element: " << temp->data << endl;
        delete temp;
        display();
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next != nullptr) {
        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        cout << "\nDeleted Element: " << toDelete->data << endl;
        delete toDelete;
    } else {
        cout << "\nValue not found\n";
    }
    display();
}

// Delete multiple nodes between two numbers
void deleteMultipleBetweenTwoGivenNumbers() {
    cout << "\nProvide the first number: ";
    int firstNumber = getValidInteger();
    cout << "\nProvide the second number: ";
    int secondNumber = getValidInteger();

    // Swap the numbers if the first is greater than the second
    if (firstNumber > secondNumber) {
        cout << "\nFirst number is greater than the second. Swapping the numbers.\n";
        swap(firstNumber, secondNumber);
    }

    if (head == nullptr) {
        cout << "\nLinked list is empty\n";
        return;
    }

    if (head->next == nullptr) {
        cout << "\nLinked list contains only one element\n";
        cout << "\nDo you want to delete that node only (1 for Yes / 0 for No)? ";
        int choice = getValidInteger();
        if (choice == 1) {
            Node *temp = head;
            head = nullptr;
            cout << "\nDeleted the only node: " << temp->data << "\n";
            delete temp;
        } else {
            cout << "\nYou selected not to delete the only element.\n";
        }
        return;
    }
    Node *temp = head;
    Node *firstNode = nullptr, *secondNode = nullptr;
    Node *prevFirst = nullptr, *prevSecond = nullptr;
    while (temp != nullptr) {
        if (temp->next != nullptr && temp->next->data == firstNumber) {
            prevFirst = temp;
            firstNode = temp->next;
        }
        if (temp->next != nullptr && temp->next->data == secondNumber) {
            prevSecond = temp;
            secondNode = temp->next;
        }
        temp = temp->next;
    }
    if (firstNode == nullptr || secondNode == nullptr) {
        cout << "\nEither first number or second number is not found in the list.\n";
        return;
    }
    Node *current = firstNode;
    Node *toDelete = nullptr;
    while (current != nullptr && current != secondNode->next) {
        toDelete = current;
        current = current->next;
        cout << "\nDeleted element: " << toDelete->data << endl;
        delete toDelete;
    }
    if (prevFirst != nullptr) {
        prevFirst->next = secondNode->next; 
    } else {
        head = secondNode->next; 
    }
    display(); 
}
void reverseLinkedList(){
    if(head == nullptr){
        cout<<"\nLinked list is empty\n";
        return; 
    }
    if(head->next==nullptr){
        cout<<"\n Linked list have only one node \n";
        display();
        return;
    }
    // more than 1 node.
    Node* current = head; 
    Node* previous  = nullptr;
    Node* next = nullptr;
    while(current != nullptr){
        next = current->next;
        current->next  = previous;
        previous = current; 
        current = next;
    }
    head = previous;
    display();
}
void countNodes(){
    if(head == nullptr){
        cout<<"\n\nZero Nodes \n";
        return; 
    }
    Node* temp = head; 
    int count = 0;
    while(temp != nullptr){
        count++;
        temp = temp -> next;
    }
    display();
    cout<<"\n\nNumber of nodes: "<<count<<endl;
}
void menu() {
    int choice, value, target;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at start\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a given number\n";
        cout << "4. Insert multiple at start\n";
        cout << "5. Insert multiple at end\n";
        cout << "6. Delete from start\n";
        cout << "7. Delete from end\n";
        cout << "8. Delete a given number\n";
        cout << "9. Delete multiple between two given numbers\n";
        cout << "10. Display list\n";
        cout << "11. Reverse the linked list\n";
        cout << "12. Number of nodes\n";
        cout << "13. Exit\n";
        cout << "\nEnter your choice: ";
        choice = getValidInteger();
        switch (choice) {
            case 1:
                cout << "\nEnter the value to insert at start: ";
                value = getValidInteger();
                insertAtStart(value);
                display();
                break;
            case 2:
                cout << "\nEnter the value to insert at end: ";
                value = getValidInteger();
                insertAtEnd(value);
                display();
                break;
            case 3:
                cout << "\nEnter the value to insert: ";
                value = getValidInteger();
                cout << "\nEnter the target number after which to insert: ";
                target = getValidInteger();
                insertAfterGivenNumber(value, target);
                display();
                break;
            case 4:
                insertMultipleAtStart();
                display();
                break;
            case 5:
                insertMultipleAtEnd();
                break;
            case 6:
                deleteFromStart();
                display();
                break;
            case 7:
                deleteFromEnd();
                display();
                break;
            case 8:
                deleteGivenNumber();
                break;
            case 9:
                deleteMultipleBetweenTwoGivenNumbers();
                break;
            case 10:
                display();
                break;
            case 11:
                cout << "\n Reversing the linked list\n";
                reverseLinkedList();
                break;
            case 12:
                // cout << "\n \n";
                countNodes();
                break;
            case 13:
                cout << "\nExiting program...\n";
                exit(0);
            default:
                cout << "\nInvalid choice. Please select a valid option.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}
