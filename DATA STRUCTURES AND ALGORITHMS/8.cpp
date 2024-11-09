#include <iostream>
using namespace std;
#define MAX 20
int st[MAX];
int top = -1;
int isEmpty() {
    return (top == -1);
}
int isFull() {
    return (top == MAX - 1);
}
void push() {
    int element; 
    cout << "\nProvide an integer to push: ";
    cin >> element;
    if (isFull()) {
        cout << "\nOverflow, cannot push more elements." << endl;
    } else {
        st[++top] = element;
        cout << element << " pushed to stack." << endl;
    }
}
int peek() {
    if (isEmpty()) {
        cout << "\n Underflow, cannot pop the Stack!" << endl;
        return -1; // Return a sentinel value to indicate stack is empty
    } else {
        return st[top];
    }
}
int pop() {
    if (isEmpty()) {
        cout << "Underflow, stack is empty, cannot pop." << endl;
        return -1; 
    } else {
        int poppedElement = st[top--]; 
        cout << "Popped element: " << poppedElement << endl;
        if (isEmpty()) {
            cout << "Stack is now empty." << endl;
        } else {
            cout << "New top element is: " << peek() << endl;
        }
        return poppedElement;
    }
}

int main() {
    int choice;

    do {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek (Top element)\n";
        cout << "4. Check if Stack is empty\n";
        cout << "5. Check if Stack is full\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        switch (choice) {
            case 1:
                push();cout<<endl;
                break;
            case 2:
                pop(); cout<<endl;
                break;
            case 3:
                cout << "Top element is: " << peek() << endl;cout<<endl;
                break;
            case 4:
                cout << "Is stack empty? " << (isEmpty() ? "Yes" : "No") << endl;cout<<endl;
                break;
            case 5:
                cout << "Is stack full? " << (isFull() ? "Yes" : "No") << endl; cout<<endl;
                break;
            case 6:
                cout << "Exiting the program..." << endl;cout<<endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 6." << endl;cout<<endl;
        }
    } while (choice != 6);  // Repeat until the user selects "Exit"

    return 0;
}
