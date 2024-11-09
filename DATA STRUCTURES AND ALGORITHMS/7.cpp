#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

void insertAtEnd(Node *&head)
{
    cout << "Provide the value: ";
    int value;
    cin >> value;
    Node *newNode = new Node(value);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

Node *mergeSortedLinkedList(Node *first, Node *second)
{
    if (first == nullptr)
        return second;
    if (second == nullptr)
        return first;
    
    Node *mergedHead = nullptr;
    if (first->data < second->data)
    {
        mergedHead = new Node(first->data); // Create a new node
        mergedHead->next = mergeSortedLinkedList(first->next, second);
    }
    else
    {
        mergedHead = new Node(second->data); // Create a new node
        mergedHead->next = mergeSortedLinkedList(first, second->next);
    }
    return mergedHead;
}

void displayUnique(Node *head)
{
    if (head == nullptr)
        return;

    Node *temp = head;
    cout << temp->data << " "; // Print the first node's data
    int last = temp->data;
    temp = temp->next;

    while (temp != nullptr)
    {
        if (temp->data != last)
        {
            cout << temp->data << " ";
            last = temp->data;
        }
        temp = temp->next;
    }
    cout << endl;
}

void display(Node *head)
{
    if (head == nullptr)
    {
        cout << "\n\nLinked list empty";
        return;
    }

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node *list1 = nullptr;
    Node *list2 = nullptr;
    Node *mergedList = nullptr; // Store the merged list persistently
    int choice = 0; // Initialize the choice variable

    while (true) // Infinite loop with option to exit
    {
        cout << "\n 1. Add the element in first list";
        cout << "\n 2. Add the element in second list";
        cout << "\n 3. Print the first list ";
        cout << "\n 4. Print the second list ";
        cout << "\n 5. Merge Lists with duplicates";
        cout << "\n 6. Merge Lists without duplicates";
        cout << "\n 7. EXIT";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Insert into first list
            insertAtEnd(list1);
            display(list1);
            break;
        case 2:
            // Insert into second list
            insertAtEnd(list2);
            display(list2);
            break;
        case 3:
            // Display first list
            cout << "\nList 1: ";
            display(list1);
            break;
        case 4:
            // Display second list
            cout << "List 2: ";
            display(list2);
            break;
        case 5:
            // Merge and display with duplicates
            mergedList = mergeSortedLinkedList(list1, list2); // Store merged list
            cout << "\n\nMerged Sorted List (with duplicates): ";
            display(mergedList);
            break;
        case 6:
            // Merge and display without duplicates
            if (mergedList == nullptr) // Ensure the lists are merged before removing duplicates
            {
                mergedList = mergeSortedLinkedList(list1, list2); // Merge first
            }
            cout << "\nMerged Sorted List (without duplicates): ";
            displayUnique(mergedList);
            break;
        case 7:
            // Exit program
            cout << "\n\nEXIT";
            return 0;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }
    }
    return 0;
}
