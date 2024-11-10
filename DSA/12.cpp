#include <iostream>
#include <cstdlib> 
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* top = nullptr;
int isStackEmpty() {
    return top == nullptr;
}
void push(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}
int pop() {
    if (isStackEmpty()) return 0;
    Node* poppedNode = top;
    int poppedData = poppedNode->data;
    top = top->next;
    free(poppedNode); 
    return poppedData;
}
int peekStack() {
    if (isStackEmpty()) return 0; 
    return top->data;
}
// Queue 
Node* front = nullptr;
Node* rear = nullptr;
int isQueueEmpty() {
    return front == nullptr;
}
void enqueue(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = nullptr;
    if (rear == nullptr) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}
int dequeue() {
    if (isQueueEmpty()) return 0; 
    Node* dequeuedNode = front;
    int dequeuedData = dequeuedNode->data;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr; 
    }
    free(dequeuedNode);
    return dequeuedData;
}
int peekQueue() {
    if (isQueueEmpty()) {
        return 0;
    }
    return front->data;
}

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Stack Operations" << endl;
    cout << "2. Queue Operations" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose an option: ";
}
void stackMenu() {
    int choice, data;
    do {
        cout << "\nStack Operations Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        // cout << "4. Display" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the data to push: ";
                cin >> data;
                push(data);
                break;
            case 2:
                data = pop();
                if (data == 0) {
                    cout << "Stack underflow." << endl;
                } else {
                    cout << "Popped: " << data << endl;
                }
                break;
            case 3:
                data = peekStack();
                if (data == 0) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Top element: " << data << endl;
                }
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);
}
void queueMenu() {
    int choice, data;
    do {
        cout << "\nQueue Operations Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        // cout << "4. Display" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the data to enqueue: ";
                cin >> data;
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                if (data == 0) {
                    cout << "Queue underflow." << endl;
                } else {
                    cout << "Dequeued: " << data << endl;
                }
                break;
            case 3:
                data = peekQueue();
                if (data == 0) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Front element: " << data << endl;
                }
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                stackMenu();
                break;
            case 2:
                queueMenu();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
