// WAP to implement Call by Value and Call by Reference in C++. Use Call by Reference to swap two integer values. (C++).
#include<iostream>
using namespace std; 
void callByValue(int n1, int n2){
    n1 = n1 + 10;
    n2 = n2 + 10;
    cout<<"\n\nCall By Value, first number = "<< n1<<" "<< "second number = " << n2;
}
void callByReference(int& n1, int& n2){
    n1 = n1 + 10;
    n2 = n2 + 10;
}
void swap(int& n1, int& n2){
    int temp = n1;
    n1 = n2;
    n2 = temp;
}
int main(){
    int first;
    int second;
    cout<<"\n\nProvide first and second number: "; cin>>first>>second;
    callByValue(first, second);
    cout<<"\n\n(Inside main function)No change in real values after call by value, first =  "<<first<<" second = "<<second<<endl;
    callByReference(first, second);
    cout<<"\nCall by reference, first  = "<<first<<" second = "<<second<<endl;
    cout<<"Values Changed"<<endl;
    cout<<"\n\n............................Swapping...................................\n\n";
    cout<<"\nBefore Swapping: "<<first<<" "<< second;
    swap(first, second);
    cout<<"\nAfter Swapping: "<< first << " "<< second; 
    cout<<"\n\n\n";
    return 0;
}