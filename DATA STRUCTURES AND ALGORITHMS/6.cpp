#include <bits/stdc++.h>
using namespace std;

bool isValidNumber(const string &str)
{
    if (str.empty())
        return false;
    int start = (str[0] == '-') ? 1 : 0;
    for (int i = start; i < str.length(); i++)
    { // Fixed: skip the sign at the start
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
        else
        {
            cout << "\nInvalid input, please enter a valid integer.";
        }
    }
}

struct Node
{
    int data;
    Node *next;
    Node *prev;
};
Node *head = nullptr;

void display()
{
    if (head == nullptr)
    {
        cout << "\nLinked List is empty\n";
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void addAtStart(int value)
{
    Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode;
    newNode->prev = newNode;
    if (head == nullptr)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    display();
}

void addAtEnd(int value)
{
    if (head == nullptr)
    {
        addAtStart(value); // If list is empty, addAtEnd works the same as addAtStart
        return;
    }
    Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev= head->prev; 
    head->prev->next = newNode;
    head -> prev = newNode;
    // Node *temp = head;

    display();
}

void addAfterAGivenValue(int target)
{
    if (head == nullptr)
    {
        cout << "\n\nList is empty\n\n";
        return;
    }
    int value;
    cout << "Provide the element you want to add: ";
    value = getValidInteger();
    Node *temp = head;
    bool found = false;
    do
    {
        if (temp->data == target)
        {
            found = true;
            Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (!found)
    {
        cout << "\nTarget value not found.\n";
        display();
        return;
    }

    display();
}

// Delete from the start
void deleteFromStart()
{
    if (head == nullptr)
    {
        cout << "\nList is empty, nothing to delete.\n";
        return;
    }
    Node *temp = head;
    if (head->next == head)
    { // Only one node in the list
        head = nullptr;
        free(temp);
    }
    else
    {
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        free(temp);
    }
    display();
}

// Delete from the end
void deleteFromEnd()
{
    if (head == nullptr)
    {
        cout << "\nList is empty, nothing to delete.\n";
        return;
    }
    Node *temp = head->prev;
    if (head->next == head)
    { // Only one node in the list
        head = nullptr;
        free(temp);
    }
    else
    {
        temp->prev->next = head;
        head->prev = temp->prev;
        free(temp);
    }
    display();
}

// Delete a node with a given value
void deleteValue()
{
    if (head == nullptr)
    {
        cout << "\nList is empty, nothing to delete.\n";
        return;
    }
    Node *temp = head;
    bool found = false;
    int target;
    cout << "\nEnter the value to delete: ";
    target = getValidInteger();
    do
    {
        if (temp->data == target)
        {
            found = true;
            if (temp == head && head->next == head)
            { // Single node in the list
                head = nullptr;
                free(temp);
            }
            else if (temp == head)
            { // Delete the head node
                head->prev->next = head->next;
                head->next->prev = head->prev;
                head = head->next;
                free(temp);
            }
            else
            { // Delete any other node
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
            }
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (!found)
    {
        cout << "\nTarget value not found.\n";
    }
    display();
}
int main()
{
    int choice, value, target;

    while (true)
    {
        cout << "\n";
        cout << "\n1. Add at Start";
        cout << "\n2. Add at End";
        cout << "\n3. Add after a Given Value";
        cout << "\n4. Delete from Start";
        cout << "\n5. Delete from End";
        cout << "\n6. Delete a Given Value";
        cout << "\n7. Display List";
        cout << "\n8. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n\nProvide an integer to add at start: ";
            value = getValidInteger();
            addAtStart(value);
            break;
        case 2:
            cout << "\n\nProvide an integer to add at end: ";
            value = getValidInteger();
            addAtEnd(value);
            break;
        case 3:
            cout << "\nEnter the target value after which to insert: ";
            target = getValidInteger();
            addAfterAGivenValue(target);
            break;
        case 4:
            deleteFromStart();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:

            deleteValue();
            break;
        case 7:
            display();
            break;
        case 8:
            cout << "\nExiting program.\n";
            exit(0);
            break;
        default:
            cout << "\nInvalid choice, please try again.";
        }
    }
    return 0;
}
