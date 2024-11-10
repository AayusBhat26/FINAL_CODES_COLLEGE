#include<iostream>
using namespace std; 
struct tree{
    int data; 
    tree* left; 
    tree* right; 
};
struct node{
    tree* ptrtotree;
    int data;
    node* next;
};
node* top = nullptr;
int isStackEmpty(){
    return top == nullptr;
}
void push(tree* ptrtotree){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->ptrtotree = ptrtotree;
    newNode->next = top;
    top = newNode;
}
tree* pop() {
    if (isStackEmpty()) return nullptr;
    node* poppedNode = top;
    tree* poppedTreeNode = poppedNode->ptrtotree;
    top = top->next;
    free(poppedNode);
    return poppedTreeNode;
}
tree* peekStack() {
    if (isStackEmpty()) return nullptr; 
    return top->ptrtotree;
}

void inordertraversal(tree* root){
    tree* temp = root;
    // left left jayenge jab tk leaf node nhi aata 
    // stack mai jata jayega 
    // phir stack k top ka data print krwa k pop krdenge
    while(temp != nullptr || !isStackEmpty()){
        // ye logg isliye hai kyuki hume left left jana hai
        while(temp != nullptr){
            push(temp);
            temp = temp -> left;
        }
        // stack mai nodes daal rhe hai 
        // aur idhar ek ek krke pop ho rha hai when we have reached nullptr
        temp = pop(); // last left node
        if(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp -> right;
        }
    }
}
void preordertraversal(tree* root){
    // root left right 
    // root print krwaya phir left left gye
    if(root == nullptr) return; 
    tree* temp = root;
    while(temp != nullptr || !isStackEmpty()){
        while(temp != nullptr){
            cout<<temp->data<<" ";
            push(temp);
            temp = temp->left;
        }
        temp = pop();
        temp = temp -> right;
    }
}
void postordertraversal(tree* root){
    if(root == nullptr) return ;
    // Left right root
    tree* lastVisited = nullptr; // right node humne visit toh nhi kra
    while(root != nullptr || !isStackEmpty()){
        if(root!= nullptr){
            push(root);
            root = root->left;// left mai jate jao jb tk left end nhi ho jata hai
        }else{
            // jaise hi last mai reach krey then hume right wala right krna padega
            // abhi k liye peeknode mai left most node hoga
            tree* peekNode = peekStack();
            if(peekNode->right != nullptr && lastVisited != peekNode->right){
                root = peekNode->right;
            }else{
                cout<<peekNode->data<<" ";
                lastVisited = pop();
            }
        }
    }
}
tree* insert(tree* root, int data){
    if(root == nullptr){
        root = (tree*)malloc(sizeof(tree));
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    if(data < root -> data){
        root->left = insert(root->left, data);
    }else if(data > root -> data){
        root->right = insert(root->right, data);
    }
    else{
        cout<<"Unique elements only"<<endl;
    }
    return root;
}
int main(){
     tree* root = nullptr;
    int choice, data;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert node\n";
        cout << "2. Display inorder traversal\n";
        cout << "3. Display preorder traversal\n";
        cout << "4. Display postorder traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> data;
                root = insert(root, data);
                break;

            case 2:
                cout << "Inorder Traversal of BST: ";
                inordertraversal(root);
                cout << endl;
                break;

            case 3:
                cout << "Preorder Traversal of BST: ";
                preordertraversal(root);
                cout << endl;
                break;

            case 4:
                cout << "Postorder Traversal of BST: ";
                postordertraversal(root);
                cout << endl;
                break;

            case 5:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
} 