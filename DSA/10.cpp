#include<iostream>
using namespace std;

#define MAX 20
int front = -1;
int rear = -1;
int queue[MAX];

// Check if the queue is full
int isFull() {
    return rear == MAX - 1;
}

// Check if the queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Enqueue operation to add an element
int enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full\n";
        return 0;
    }
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
    return 1;
}

// Dequeue operation to remove an element
int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return 0;
    }
    cout << "Dequeued: " << queue[front] << endl;
    front++;
    if (front > rear) {  // Reset the queue if empty
        front = -1;
        rear = -1;
    }
    return 1;
}

// Peek the first element in the queue
int peek() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return -1;
    }
    return queue[front];
}

// Get the last element in the queue
int lastElement() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return -1;
    }
    return queue[rear];
}

int main() {
    int choice = 0;
    int value, res;

    do {
        // Display the menu
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek (First Element)\n";
        cout << "4. Last Element\n";
        cout << "5. Is queue full?\n";
        cout << "6. Is queue empty?\n";
        cout << "10. Exit\n";
        cout << "Provide your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Provide the value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                res = peek();
                if (res != -1) cout << "First element: " << res << endl;
                break;

            case 4:
                res = lastElement();
                if (res != -1) cout << "Last element: " << res << endl;
                break;

            case 5:
                if (isFull())
                    cout << "Queue is full\n";
                else
                    cout << "Queue is not full\n";
                break;

            case 6:
                if (isEmpty())
                    cout << "Queue is empty\n";
                else
                    cout << "Queue is not empty\n";
                break;

            case 10:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Please provide a valid choice\n";
                break;
        }
    } while (choice != 10);

    return 0;
}
