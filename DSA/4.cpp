#include <bits/stdc++.h>
using namespace std;
bool isValidNumber(const string &str)
{
    if (str.empty())
        return false;
    int start = (str[0] == '-') ? 1 : 0;
    for (int i = start; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}
int getValidInteger()
{
    string input;
    while (true)
    {
        cin >> input;
        if (isValidNumber(input))
{
            return stoi(input);
        }
        else{
            cout << "Invalid input. Please enter a valid integer: ";
        }
    }
}

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr;

// Display the circular linked list
void display()
{
    if (head == nullptr)
    {
        cout << "\n\nList is empty, add some elements first\n";
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << "\n";
}

// Add a node at the start of the circular linked list
void addAtStart(int value)
{
    Node *newNode = new Node();
    newNode->data = value;

    if (head == nullptr){
        head = newNode;
        newNode->next = head; 
        // since circular linked list, therefore pointing to itself 
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    display();
}

// Add a node at the end of the circular linked list
void addAtEnd(int value)
{
    Node *newNode = new Node();
    newNode->data = value;

    if (head == nullptr)
    {
        cout << "\n\nList is empty, adding at start\n";
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; // Maintain circular structure
    }
    display();
}

// Add a node after a given value in the circular linked list
void addAfterGivenValue(int value, int target)
{
    if (head == nullptr)
    {
        cout << "\nList is empty\n";
        return;
    }
    Node *newNode = new Node();
    newNode->data = value;
    Node *temp = head;
    do
    {
        if (temp->data == target)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Target value " << target << " not found in the list.\n";
}

// Delete the node at the start of the circular linked list
void deletionFromStart()
{
    if (head == nullptr)
    {
        cout << "\n\nList is empty\n\n";
        return;
    }
    if (head->next == head)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node *temp = head;
        Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        delete temp;
    }
}

// Delete the node at the end of the circular linked list
void deleteFromEnd()
{
    if (head == nullptr)
    {
        cout << "\n\nList is empty\n\n";
        return;
    }
    if (head->next == head)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node *temp = head;
        Node *secondLast = nullptr;
        while (temp->next != head)
        {
            secondLast = temp;
            temp = temp->next;
        }
        secondLast->next = head;
        delete (temp);
    }
}

// Delete a node with a specific target value from the circular linked list
void deleteTarget()
{
    if (head == nullptr)
    {
        cout << "\n\nList is empty\n\n";
        return;
    }

    cout << "Provide the number you want to delete: ";
    int target = getValidInteger();

    Node *temp = head;
    Node *prev = nullptr;

    // Case 1: Target is at the head
    if (head->data == target)
    {
        if (head->next == head)
        { // If there's only one node
            delete head;
            head = nullptr;
        }
        else
        {
            Node *last = head;
            // Find the last node to maintain the circular structure
            while (last->next != head)
            {
                last = last->next;
            }
            last->next = head->next; // Last node points to new head
            temp = head;
            head = head->next; // Update head
            delete temp;
        }
        return;
    }

    // Case 2: Traverse the list to find the target node
    do
    {
        prev = temp; // second last node
        temp = temp->next;
    } while (temp != head && temp->data != target);

    // If the target node is found
    if (temp->data == target)
    {
        prev->next = temp->next; // Remove the target node from the list
        delete temp;
        cout << "Node with value " << target << " deleted.\n";
    }
    else
    {
        cout << "Node with value " << target << " not found in the list.\n";
    }
}

// Menu-driven program
int main()
{
    int choice, value, target;

    do
    {
        cout << endl;
        cout << "1. Add at Start\n";
        cout << "2. Add at End\n";
        cout << "3. Add After a Given Value\n";
        cout << "4. Delete from Start\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete a Specific Target\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        choice = getValidInteger();

        switch (choice)
        {
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
            cout << "Enter value to add: ";
            value = getValidInteger();
            cout << "Enter the target value after which to insert: ";
            target = getValidInteger();
            addAfterGivenValue(value, target);
            display();

            break;
        case 4:
            deletionFromStart();
            display();

            break;
        case 5:
            deleteFromEnd();
            display();

            break;
        case 6:
            deleteTarget();
            display();

            break;
        case 7:
            display();
            display();

            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
