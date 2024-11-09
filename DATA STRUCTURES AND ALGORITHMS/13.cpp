#include <iostream>
#include <cstdlib> 
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
struct nodeQueue{
    node *ptrToTreeNode;
    nodeQueue *next;
};
void enqueue(nodeQueue *&front, nodeQueue *&rear, node *treeNode){
    nodeQueue *newNode = (nodeQueue *)malloc(sizeof(nodeQueue));
    newNode->ptrToTreeNode = treeNode;
    newNode->next = nullptr;
    if (rear == nullptr){
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}
node *dequeue(nodeQueue *&front, nodeQueue *&rear){
    if (front == nullptr){
        return nullptr;
    }
    nodeQueue *temp = front;
    node *treeNode = front->ptrToTreeNode;
    front = front->next;
    if (front == nullptr){
        rear = nullptr;
    }
    free(temp);
    return treeNode;
}

void levelOrderTraversal(node *root)
{
    if (root == nullptr)
    {
        cout << "Tree is empty" << endl;
        return;
    }

    nodeQueue *front = nullptr;
    nodeQueue *rear = nullptr;
    enqueue(front, rear, root);

    int level = 0;
    while (front != nullptr)
    {
        cout << "Level " << level << ": ";
        int levelNodeCount = 0;

        nodeQueue *tempFront = front;
        while (tempFront != nullptr)
        {
            levelNodeCount++;
            tempFront = tempFront->next;
        }

        for (int i = 0; i < levelNodeCount; i++)
        {
            node *currentNode = dequeue(front, rear);
            cout << currentNode->data << " ";

            if (currentNode->left != nullptr)
            {
                enqueue(front, rear, currentNode->left);
            }
            if (currentNode->right != nullptr)
            {
                enqueue(front, rear, currentNode->right);
            }
        }
        cout << endl;
        level++;
    }
}

void inorderTraversal(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

node *insert(node *root, int data)
{
    if (data == -1)
        return root;

    if (root == nullptr){
        root = (node *)malloc(sizeof(node));
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }

    if (data < root->data){
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        cout << "Unique elements only" << endl;
    }
    return root;
}

void insertMultiple(node *&root)
{
    int value;
    cout << "Enter values to insert (-1 to stop): ";
    
    while (true)
    {
        cin >> value;
        if (value == -1)
            break;
        root = insert(root, value);
    }
}
void searchRecursive(node*&root, int key){
    if(root == nullptr){
        cout<<"\nTree is empty or key not present"<<endl;
        return;
    }
    if(root->data == key){
        cout<<"\nKey found\n";
        return;
    }
    if(root->data > key){
        return searchRecursive(root->left, key);
    }
    if(root->data < key){
        return searchRecursive(root->right, key);
    }
    return;
}
void searchIteratively(node*& root, int key){
    node* temp = root; 
    while(temp!=nullptr){
        if(temp->data == key){
            cout<<"\nKey found\n";
            return ;
        }
        if(temp->data > key ){
            temp = temp -> left;
        }
        else{
            temp = temp -> right;
        }
    }
    return;
}
node* minimumvalue(node* root){
    if(root == nullptr){
        cout<<"Tree is empty, cannot find minimum value";
        return nullptr;
    }
    node* temp = root;
    while(temp != nullptr){
        temp = temp -> left ;
    }
    return temp;
}
int maximumvalue(node* root){
    if(root == nullptr){
        cout<<"Tree is empty, cannot find maximum value";
        return 0;
    }
    node* temp = root;
    while(temp != nullptr){
        temp = temp -> right ;
    }
    return temp -> data;
}
// deletion of node
//  3 cases baan skte hai 
// 1. leaf node
// 2. 1 child only => left or right child
// 3. 2 children
node* deleteFromBST(node* root, int val) {
    // here root node is not the real root, is the root of 0, 1 or 2 children
    // Base case: if the tree is empty
    if (root == nullptr) {
        cout << "Value " << val << " not found in the BST." << endl; // Inform the user
        return root;
    }

    // If the value to be deleted is smaller than the root's value
    if (val < root->data) {
        root->left = deleteFromBST(root->left, val);
    }
    // If the value to be deleted is greater than the root's value
    else if (val > root->data) {
        root->right = deleteFromBST(root->right, val);
    }
    // The value is found (root->data == val)
    else {
        
        if (root->left == nullptr) {
            node* temp = root->right;
            delete root; 
            return temp;
        }
        else if (root->right == nullptr) {
            node* temp = root->left;
            delete root; // Free memory
            return temp; // Return the left child
        }
        // 2 cases htoe hai generally, either we take right mai ja k sabse smallest node ya phir hum left mai ja k sabse greatest node lete hai
        // idhar hum lenge, right wale mtlb ki right mai ja k smallest value node k sath replace krenge.
        int minval = minimumvalue(root->right)->data;
        root->data = minval; // Replace root's data with inorder successor's data
        root->right = deleteFromBST(root->right, minval); // Delete 






    }   
    return root; 
}
int main(){
    node *root = nullptr;
    int choice, data;
    while (true){
    cout << "\nMenu:\n";
    cout << "1. Insert single node\n";
    cout << "2. Display in-order traversal\n";
    cout << "3. Display pre-order traversal\n";
    cout << "4. Display post-order traversal\n";
    cout << "5. Display level-order traversal\n";
    cout << "6. Insert multiple nodes\n";
    cout << "7. Search recursively\n";
    cout << "8. Search iteratively\n";
    cout << "9. Find minimum value\n";
    cout << "10. Find maximum value\n";
    cout << "11. Delete node from BST\n";
    cout << "12. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
        case 1:
            cout << "Enter value to insert (-1 to skip): ";
            cin >> data;
            if (data != -1)
                root = insert(root, data);
            else
                cout << "Skipping insertion." << endl;
            break;
        case 2:
            cout << "In-order Traversal of BST: ";
            inorderTraversal(root);
            cout << endl;
            break;
        case 3:
            cout << "Pre-order Traversal of BST: ";
            preorderTraversal(root);
            cout << endl;
            break;
        case 4:
            cout << "Post-order Traversal of BST: ";
            postorderTraversal(root);
            cout << endl;
            break;
        case 5:
            cout << "Level-order Traversal of BST: " << endl;
            levelOrderTraversal(root);
            break;
        case 6:
            cout << "Insert multiple nodes: " << endl;
            insertMultiple(root);
            break;
        case 7:
            cout << "Search recursively" << endl;
            int key;
            cout << "What value do you want to search? : ";
            cin >> key;
            if (key == -1){
                cout << "Moving back to main menu" << endl;
                break;
            }
            searchRecursive(root, key);
            break;
        case 8:
            cout << "Search iteratively" << endl;
            int key2;
            cout << "What value do you want to search? : ";
            cin >> key2;
            if (key2 == -1){
                cout << "Moving back to main menu" << endl;
                break;
            }
            searchIteratively(root, key2);
            break;
        case 9:{
                node* minNode = minimumvalue(root);
                if (minNode != nullptr)cout << "Minimum value in the BST: " << minNode->data << endl;
                break;
            }
        case 10:
            {
                int maxValue = maximumvalue(root);
                if (maxValue != 0) cout << "Maximum value in the BST: " << maxValue << endl;
                break;
            }
        case 11:
                int val;
                cout << "Enter value to delete: ";
                cin >> val;
                root = deleteFromBST(root, val);
                // cout << "Node with value " << val << " deleted from BST." << endl;
                break;
        case 12:
            cout << "Exiting program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}
}
// time complexity for insertion => O(h), O(n) for worst case, left or right skewed trees
// time complexity for searching => O(h), O(n) for worst case
// time complexity for deletion
// inorder traversal of bst is sorted