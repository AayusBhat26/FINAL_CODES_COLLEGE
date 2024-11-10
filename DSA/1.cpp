#include <iostream>
using namespace std;
const int SENTINEL_VALUE = -1;
void printArray(int arr[], int size) {
    cout << "\n";
    if (size <= 0) {
        cout << "Array is empty.\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isArrayEmpty(int size) {
    return size <= 0;
}
void addAtStart(int arr[], int &size, int element) {
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = element;
    size++;
    printArray(arr, size);
}
void addAtEnd(int arr[], int &size, int element) {
    arr[size] = element;
    size++;
    printArray(arr, size);
}
void addAtPosition(int arr[], int &size, int element, int position) {
    if (position < 0 || position > size) {
        cout << "Invalid Position!\n";
        return;
    }
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
    printArray(arr, size);
}
void deleteFromStart(int arr[], int &size) {
    if (isArrayEmpty(size)) {
        cout << "Array is empty, first add an element.\n";
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printArray(arr, size);
}
void deleteFromPosition(int arr[], int &size, int position) {
    if (position < 0 || position >= size) {
        cout << "Invalid Position.\n";
        return;
    }
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printArray(arr, size);
}
void deleteFromEnd(int arr[], int &size) {
    if (isArrayEmpty(size)) {
        cout << "\nArray is empty.\n";
        return;
    }
    size--;
    printArray(arr, size);
}
void deleteFromRange(int arr[], int &size, int start, int end) {
    if (start < 0 || end >= size || start > end) {
        cout << "Invalid Range.\n";
        return;
    }
    for (int i = end + 1; i < size; i++) {
        arr[start + i - (end - start + 1)] = arr[i];
    }
    size -= (end - start + 1);
    printArray(arr, size);
}
void addMultipleAtEnd(int arr[], int &size) {
    int noelements;
    cout << "\nProvide number of elements you want to add: ";  
    cin >> noelements;
    cout << "\nProvide the elements: ";
    int tempArr[noelements];
    for (int i = 0; i < noelements; i++) {
        cin >> tempArr[i];
    }
    for (int i = 0; i < noelements; i++) {
        arr[size] = tempArr[i];
        size++;
    }
    printArray(arr, size);
}
void addMultipleAtStart(int arr[], int &size) {
    int noelements;
    cout << "\nProvide number of elements you want to add: ";  
    cin >> noelements;
    cout << "\nProvide the elements: ";
    int tempArr[noelements];
    for (int i = 0; i < noelements; i++) {
        cin >> tempArr[i];
    }
    for (int i = size + noelements - 1; i >= noelements; i--) {
        arr[i] = arr[i - noelements];
    }
    for (int i = 0; i < noelements; i++) {
        arr[i] = tempArr[i];
    }
    size = size + noelements;
    printArray(arr, size);
}

void addMultipleAtPosition(int arr[], int &size) {
    int noelements;
    int position; 
    cout << "\nProvide the position to add to: "; 
    cin >> position;
    if (position < 0 || position > size) {
        cout << "\nInvalid Position\n";
        return;
    }
    cout << "\nProvide number of elements you want to add: ";  
    cin >> noelements;
    cout << "\nProvide the elements: ";
    int tempArr[noelements];
    for (int i = 0; i < noelements; i++) {
        cin >> tempArr[i];
    }
    for (int i = size + noelements - 1; i >= position + noelements; i--) {
        arr[i] = arr[i - noelements];
    }
    for (int i = 0; i < noelements; i++) {
        arr[position + i] = tempArr[i];
    }
    size = size + noelements;
    printArray(arr, size);
}

void deleteMultipleFromStart(int arr[], int &size) {
    int noelements; 
    cout << "Provide the number of elements to delete: ";
    cin >> noelements;
    if (noelements > size) {
        cout << "\nNumber of elements to delete is greater than the size of array\n";
        return;
    }
    for (int i = 0; i < size - noelements; i++) {
        arr[i] = arr[i + noelements];
    }
    size = size - noelements;
    printArray(arr, size);
}

void deleteMultipleFromEnd(int arr[], int &size) {
    int noelements; 
    cout << "Provide the number of elements to delete: ";
    cin >> noelements;
    if (noelements > size) {
        cout << "\nNumber of elements to delete is greater than the size of array\n";
        return;
    }
    for (int i = size - noelements; i < size; i++) {
        arr[i] = SENTINEL_VALUE;
    }
    size = size - noelements;
    printArray(arr, size);
}

void deleteMultipleFromPosition(int arr[], int &size) {
    int position;
    int noelement; // Number of elements to delete from position
    cout << "\nProvide number of elements to delete: "; 
    cin >> noelement;
    cout << "\nProvide the position: "; 
    cin >> position;
    if (position < 0 || position >= size) {
        cout << "Invalid Position";
        return;
    }
    if (position + noelement > size) {
        cout << "\nOut of bounds\n";
        return;
    }
    for (int i = position; i < size - noelement; i++) {
        arr[i] = arr[i + noelement];
    }
    for (int i = size - noelement; i < size; i++) {
        arr[i] = SENTINEL_VALUE;
    }
    size = size - noelement;
    printArray(arr, size);
}

void searchElement(int arr[], int size, int element) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            cout << "\nElement " << element << " found at index " << i << ".\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\nElement " << element << " not found.\n";
    }
}

void updateElement(int arr[], int size, int position, int newElement) {
    if (position < 0 || position >= size) {
        cout << "Invalid Position.\n";
        return;
    }
    arr[position] = newElement;
    cout << "Element at position " << position << " updated to " << newElement << ".\n";
    printArray(arr, size);
}

int main() {
    int size = 0;
    int flag = 0, element, position, start, end, arr[10];
    
    do {
        cout << "\nMenu: \n";
        cout << "1. Add element at start\n";
        cout << "2. Add element at end\n";
        cout << "3. Add element at a given position\n";
        cout << "4. Delete element from start\n";
        cout << "5. Delete element from end\n";
        cout << "6. Delete element from a given position\n";
        cout << "7. Delete elements from a given range\n";
        cout << "8. Display Array\n";
        cout << "9. Add Multiple Elements at end\n";
        cout << "10. Add Multiple Elements at start\n";
        cout << "11. Add Multiple Elements at a given position\n";
        cout << "12. Delete Multiple from start\n";
        cout << "13. Delete Multiple from end\n";
        cout << "14. Delete Multiple from position\n";
        cout << "15. Search for an element\n";
        cout << "16. Update an element\n";
        cout << "20. BYE BYE\n";
        cout << "\nEnter your choice: ";
        cin >> flag;

        switch (flag) {
            case 1

:
                cout << "\nEnter element to add at start: ";
                cin >> element;
                addAtStart(arr, size, element);
                break;
            case 2:
                cout << "\nEnter element to add at end: ";
                cin >> element;
                addAtEnd(arr, size, element);
                break;
            case 3:
                cout << "\nEnter element to add: ";
                cin >> element;
                cout << "\nEnter position: ";
                cin >> position;
                addAtPosition(arr, size, element, position);
                break;
            case 4:
                deleteFromStart(arr, size);
                break;
            case 5:
                deleteFromEnd(arr, size);
                break;
            case 6:
                cout << "\nEnter position to delete: ";
                cin >> position;
                deleteFromPosition(arr, size, position);
                break;
            case 7:
                cout << "\nEnter start position: ";
                cin >> start;
                cout << "\nEnter end position: ";
                cin >> end;
                deleteFromRange(arr, size, start, end);
                break;
            case 8:
                printArray(arr, size);
                break;
            case 9:
                addMultipleAtEnd(arr, size);
                break;
            case 10:
                addMultipleAtStart(arr, size);
                break;
            case 11:
                addMultipleAtPosition(arr, size);
                break;
            case 12:
                deleteMultipleFromStart(arr, size);
                break;
            case 13:
                deleteMultipleFromEnd(arr, size);
                break;
            case 14:
                deleteMultipleFromPosition(arr, size);
                break;
            case 15:
                cout << "Enter element to search: ";
                cin >> element;
                searchElement(arr, size, element);
                break;
            case 16:
                cout << "\nProvide the position to update: "; 
                cin >> position;
                cout << "\nProvide the new element: ";
                cin >> element;
                updateElement(arr, size, position, element);
                break;
            case 20:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (flag != 20);
    return 0;
}