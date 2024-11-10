#include<iostream>
#include <cstdlib>
using namespace std;

// for array 
#define MAX 20
int front = -1;
int rear = -1;
int queue[MAX];

// for linked list
struct Node {
    int data;
    Node* next;
};
Node* frontList = nullptr;
Node* rearList = nullptr;

// ----------------------------- Linked List Queue Functions ------------------------------

int isEmptyList() {
    return (frontList == nullptr);
}
void displayList() {
    if (isEmptyList()) {
        cout << "\nQueue is empty, nothing to display\n";
        return;
    }
    cout << "\nQueue elements (using linked list): ";
    Node* temp = frontList;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != frontList);
    cout << endl;
}
int enqueueList(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = nullptr;
    
    if (isEmptyList()) {
        frontList = newNode;
        rearList = newNode;
        rearList->next = frontList; // Circular queue link
    } else {
        rearList->next = newNode;
        rearList = newNode;
        rearList->next = frontList;
    }
    displayList();
    return 1;
}

int dequeueList() {
    if (isEmptyList()) {
        cout << "\n\nQueue is empty";
        return 0;
    }
    int dequeuedValue;
    if (frontList == rearList) {
        dequeuedValue = frontList->data;
        free(frontList);
        frontList = nullptr;
        rearList = nullptr;
    } else {
        Node* temp = frontList;
        dequeuedValue = temp->data;
        frontList = frontList->next;
        rearList->next = frontList;
        free(temp);
    }
    cout << endl << "Dequeued: " << dequeuedValue;
    displayList();
    return dequeuedValue;
}



void circularQueueDemoList() {
    cout << "\nDemonstrating Circular Queue with Linked List.....\n";
    for (int i = 1; i <= 20; i++) {
        enqueueList(i);
    }
    cout << "\nDequeuing 10 elements:\n";
    for (int i = 0; i < 10; i++) {
        dequeueList();
    }
    for (int i = 21; i <= 30; i++) {
        enqueueList(i);
    }
    displayList();
}

// ----------------------------- Array Queue Functions ------------------------------

int isFull() {
    return (rear + 1) % MAX == front;
}

int isEmpty() {
    return front == -1;
}
void display() {
    if (isEmpty()) {
        cout << "\n\nQueue is empty, nothing to print\n\n";
        return;
    }
    cout << "\n\nQueue elements:\n\n";
    int i = front;
    while (i != rear) {
        cout << queue[i]<<" -> ";
        i = (i + 1) % MAX;
    }
    cout << queue[rear] << endl;
}

int enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full, cannot enqueue " << value << endl;
        return 0;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    cout << "\nEnqueued " << value << endl;
    display();
    return value;
}
int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty, cannot dequeue" << endl;
        return 0;
    }
    int toBeDequeued = queue[front];
    cout << "\nDequeued " << toBeDequeued << endl;
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    display();
    return toBeDequeued;
}
void circularQueueDemo() {
    cout << "\n\nDemonstrating Circular Queue:\n\n";
    for (int i = 1; i <= 20; i++) {
        enqueue(i);
    }
    display();
    cout << "\nDequeuing 10 elements:\n";
    for (int i = 0; i < 10; i++) {
        dequeue();
    }
    // Enqueue elements from 21 to 30 to show circular nature
    cout << "\nEnqueuing elements 21 to 30:\n";
    for (int i = 21; i <= 30; i++) {
        enqueue(i);
    }
    display();
}
// ----------------------------- Switch Functions ------------------------------
void switchToArrayFromList() {
    // Reset the array queue
    front = rear = -1;
    frontList = rearList = nullptr;
    // cout << "\n\nSwitched to Array-based Queue (new queue is initialized).\n";
}
void switchToListFromArray() {
    // Reset the linked list queue
    frontList = rearList = nullptr;
    front = rear = -1;
    // cout << "\n\nSwitched to Linked List-based Queue (new queue is initialized).\n";
}
// ----------------------------- Main Function ------------------------------
int main() {
    int choice, value;
    int choiceArL;
    bool stayInMenu;  // Flag to control the menu loop
    
    while (true) {
        cout << "\nArray or Linked List? (1 for Array / 2 for Linked List) or press 3 to exit: ";
        cin >> choiceArL;
        switch (choiceArL) {
            case 1:
                cout << "\n\n\n\n..... USING ARRAY .....";
                stayInMenu = true; // Reset flag for the array menu
                while (stayInMenu) {
                    cout << "\nMenu:\n";
                    cout << "1. Enqueue\n";
                    cout << "2. Dequeue\n";
                    cout << "3. Check if Full\n";
                    cout << "4. Check if Empty\n";
                    cout << "5. Circular Queue Demo (with 20 elements)\n";
                    cout << "6. Display Queue\n";
                    cout << "7. Main Menu\n";
                    cout << "8. Exit\n";
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            cout << "Enter value to enqueue: ";
                            cin >> value;
                            enqueue(value);
                            break;
                        case 2:
                            dequeue();
                            break;
                        case 3:
                            if (isFull())
                                cout << "Queue is full\n";
                            else
                                cout << "Queue is not full\n";
                            break;
                        case 4:
                            if (isEmpty())
                                cout << "Queue is empty\n";
                            else
                                cout << "Queue is not empty\n";
                            break;
                        case 5:
                            circularQueueDemo();
                            break;
                        case 6:
                            display();
                            break;
                        case 7:
                            switchToListFromArray();  // Switch to Linked List
                            stayInMenu = false;  // Exit the current loop
                            break;
                        case 8:
                            cout << "Exiting...\n";
                            return 0;
                        default:
                            cout << "Invalid choice! Please try again.\n";
                            break;
                    }
                }
                break;
            case 2:
                cout << "\n\n\n\n..... USING Linked List .....";
                stayInMenu = true;  // Reset flag for the linked list menu
                while (stayInMenu) {
                    cout << "\nMenu:\n";
                    cout << "1. Enqueue\n";
                    cout << "2. Dequeue\n";
                    cout << "3. Check if Empty\n";
                    cout << "4. Circular Queue Demo (with 20 elements)\n";
                    cout << "5. Display Queue\n";
                    cout << "6. Main Menu\n";
                    cout << "7. Exit\n";
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            cout << "Enter value to enqueue: ";
                            cin >> value;
                            enqueueList(value);
                            break;
                        case 2:
                            dequeueList();
                            break;
                        case 3:
                            if (isEmptyList())
                                cout << "Queue is empty\n";
                            else
                                cout << "Queue is not empty\n";
                            break;
                        case 4:
                            circularQueueDemoList();
                            break;
                        case 5:
                            displayList();
                            break;
                        case 6:
                            switchToArrayFromList();  // Switch to Array
                            stayInMenu = false;  // Exit the current loop
                            break;
                        case 7:
                            cout << "Exiting...\n";
                            return 0;
                        default:
                            cout << "Invalid choice! Please try again.\n";
                    }
                }
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
