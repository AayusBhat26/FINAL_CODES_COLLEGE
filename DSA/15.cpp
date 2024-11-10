#include<iostream>
using namespace std; 

struct Node{
    int data, height;
    Node* left;
    Node* right; 
};

int getHeight(Node* node){
    if(node == nullptr) return 0;
    return node->height;
}
Node* createNode(int data){
    Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->height = 1; // jo bhi new node hoga vo leaf node hoga
    newNode->right = nullptr;
    newNode->left = nullptr;
    return newNode;
}

int getBalanceFactro(Node* node){
    if(node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right); 
}

int maxHeight(int h1, int h2){
    return h1 > h2 ? h1 : h2;
}
Node* rightRotate(Node* mainNode){
    // Left Left insertion hua hai 
    //                  mainNode
    //          left               T1
    //    T2          T3

    // AFTER ROTATION 
    //                  left 
    //          T2                mainNode
    //                       T3               T1                                    

    Node* leftNode = mainNode->left;
    // agar right node hai left child of mainNode k toh vo aayega nhi toh nullptr aayega
    Node* rightChildOfLN = leftNode->right; 
    // left ko handle isliye nhi kr rhe hai kyuki vo already left side hi hoga toh usko handle krne ki need nhi rhegi 


    // rotation krenge 
    leftNode->right = mainNode;
    mainNode->left = rightChildOfLN; 

    // changing height.
    mainNode ->height = 1 + maxHeight(getHeight(mainNode->left), getHeight(mainNode->right));
    leftNode -> height = 1 + maxHeight(getHeight(leftNode->left), getHeight(leftNode->right));

    return leftNode; // left node jo hai vo root baan chuka hai.
}
Node* leftRotate(Node* mainNode){
    // right right insert hua hai 
    // left rotate 
    Node* rightNode = mainNode -> right;
    // handling left child here.
    Node* leftChildOfRN = rightNode->left;

    // rotation 
    rightNode -> left = mainNode;
    mainNode->right = leftChildOfRN; 

    // changing height

    mainNode->height = 1 + maxHeight(getHeight(mainNode->left), getHeight(mainNode->right));
    rightNode -> height = 1 + maxHeight(getHeight(rightNode->left), getHeight(rightNode->right));
    return rightNode;
}

Node* insertNode(Node* node, int data){
    // normal bst
    if(node == nullptr) return createNode(data);
    if(data < node->data) node -> left = insertNode(node->left, data);
    else if(data > node->data) node -> right = insertNode(node->right, data);
    else{
        cout<<"Provide Unique elements only";
        return node;
    }
    // since node is inserted till here.
    node->height = 1 + maxHeight(getHeight(node->left), getHeight(node->right));
    int balanceFactor = getBalanceFactro(node);
    // Balancing the tree.
    if(balanceFactor > 1  && data < node->left->data){
        // left mai insertion ho rha hai 
        // LL case banega toh right rotation 
        return rightRotate(node);
    }
    if(balanceFactor < -1 && data > node->right->data){
        // right mai insertion ho rha hai
        // RR case banega toh left rotation 
        return leftRotate(node);
    }
    if(balanceFactor > 1 && data > node->left->data){
        // since balance factor 1 se greater hai toh Left heavy tree hai 
        // but new data is greater than current node ka data, toh right mai save hoga
        // left right 
        // first left rotate around mid node
        // then right rotate around top node
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(balanceFactor < -1 && data < node->right->data){
        // since balance factor -1 se lesser hai toh right heavy tree hai 
        // but new data is less than current node ka data, toh left mai save hoga
        // right left 
        // first right rotate around mid node
        // then left rotate around top node
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
struct nodeQueue{
    Node* ptrtotree;
    nodeQueue* next;
};
void enqueue(nodeQueue *& front, nodeQueue*& rear, Node* treeNode){
    nodeQueue * newNode = (nodeQueue *)malloc(sizeof(nodeQueue));
    newNode->ptrtotree = treeNode;
    newNode->next = nullptr;
    if(rear == nullptr){
        front = rear = newNode;
    }else{
        rear->next = newNode;
        rear = newNode;
    }
}
Node* dequeue(nodeQueue *& front, nodeQueue *& rear){
    if(front == nullptr){
        return  nullptr;
    }
    nodeQueue * temp = front;
    Node* treenode  = front->ptrtotree;
    front = front -> next;
    if(front == nullptr){
        rear = nullptr;
    }
    delete(temp);
    return treenode;
}
void levelOrderTraversal(Node* root){
    if(root == nullptr){
        cout<<"Tree is empty";
        return;
    }
    nodeQueue* front = nullptr;
    nodeQueue* rear = nullptr;
    enqueue(front, rear, root); // inserting root to the queue.
    int level = 0; // to maintain the level
    while(front != nullptr){
        cout<<"Level "<<level<<": ";
        int levelNode = 0; // to count the number of nodes in a level.
        nodeQueue * tempFront = front;
        while(tempFront!=nullptr){
            levelNode++;
            tempFront = tempFront -> next;
        }
        for(int i = 0 ; i < levelNode; i++){
            Node* currentNode = dequeue(front, rear);
            cout<<currentNode->data<<" ";
            if(currentNode->left != nullptr){
                enqueue(front, rear, currentNode->left);
            }
             if(currentNode->right != nullptr){
                enqueue(front, rear, currentNode->right );
            }
        }
        cout<<endl;
        level++;
    }
}
Node* deleteNode(Node* root, int data){
    if(root == nullptr)return nullptr;
    if(data < root->data) {
        // left side
        root->left= deleteNode(root->left, data);
    }else if(data > root->data){
        // right st
        root->right = deleteNode(root -> right, data);
    }else{
        // delete wala node mil gya
        // cases: 1. leaf , one child, 2 child
        // leaf node 
        if(root->left == nullptr && root->right == nullptr){
            delete(root);
            return nullptr;
        }
        // one child 
        else if(root->right == nullptr && root->left != nullptr){
            // left child exists
            Node* temp = root->left;
            delete(root);
            return temp;
        }
        else if(root->right != nullptr && root->left == nullptr){
            Node* temp = root->right; 
            delete(root);
            return temp;
        }
        // both children exists 
        else{
            // right side ka smallest element 
            Node* current = root->right; 
            while(current->left != nullptr){
                current = current -> left; 
            }
            // replacing the data in the node which i have to delete. 
            root->data = current->data;
            root -> right = deleteNode(root->right, root->data);
        }
    }
    // height updating 
    root -> height = 1 + maxHeight(getHeight(root->left), getHeight(root->right));
    // balance checking.
    int balanceFactor = getBalanceFactro(root);
    // left left case 
    if(balanceFactor > 1 && getBalanceFactro(root->left) >= 0){
        return rightRotate(root);
        // left nodes k bhi check krna hota hai kyuki vo bhi matter krega when we are calcualting the height
        // Left Left mai delete hua hai 
    }
    // right right case 
    if(balanceFactor < -1 && getBalanceFactro(root->right) <= 0){
        return leftRotate(root); 
        // right right mai delete hua hai 
    }
    if(balanceFactor > 1 && getBalanceFactro(root->left) < 0){
        // left then right ja k delete hua hai 
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // right left case hai
    if(balanceFactor < -1 && getBalanceFactro(root->right) > 0){
        // right then left, therefore balancefactor -1 se less hoga agar imbalance hua and left mai hai toh greater hoga
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;    

}
int main(){
   Node* root = nullptr;
    int choice, data;

    while(true) {
        cout << "Menu:\n1. Insert a node\n2. Delete a node\n3. Level Order Traversal\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> data;
                root = insertNode(root, data);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> data;
                root = deleteNode(root, data);
                break;
            case 3:
                levelOrderTraversal(root);
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }
    return 0;
}