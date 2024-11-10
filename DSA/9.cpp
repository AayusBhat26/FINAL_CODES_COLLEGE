#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;
#define MAX 50

char st[MAX];
int top = -1;

// for evaluation of postfix.
int evalStack[MAX];
int evalTop = -1;
void pushInt(int n)
{
    if (evalTop == MAX - 1)
    {
        cout << "\nOverflow in evaluation stack.";
    }
    else
    {
        evalStack[++evalTop] = n;
    }
}
int popInt()
{
    if (evalTop == -1)
    {
        cout << "\nUnderflow in evaluation stack.";
        return 0;
    }
    else
    {
        return evalStack[evalTop--];
    }
}
int isEmpty()
{
    return (top == -1);
}
int isFull()
{
    return (top == MAX - 1);
}
void push(char c)
{
    if (isFull())
    {
        cout << "\nOverflow, cannot push more into the stack.";
    }
    else
    {
        st[++top] = c;
    }
}
char pop()
{
    if (isEmpty())
    {
        cout << "\nUnderflow, cannot pop more" << endl;
        return '\0';
    }
    else
    {
        return st[top--];
        // returing the top most element and decreasing the top.
    }
}
char peek()
{
    if (isEmpty())
    {
        return '\0';
    }
    else
    {
        return st[top];
    }
}
// helper function for conversion.
int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
bool isOperand(char c)
{
    return isalnum(c);
    // it is the c function which is defined in cctype
    // cctype is the header file which contains the code which is return in c language.
}

string infixToPostfixConversion(string infix)
{
    string postfix = "";
    for (char c : infix)
    {
        if (isOperand(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                postfix += pop();
            }
            if (!isEmpty() && peek() == '(')
            {
                pop();
            }
        }
        else
        {
            // when lower precedence operator is encountered, tabhi chalega while loop. top of the stack k operator se chota hona cahiye current operator ka preecdenance
            while (!isEmpty() &&
                   ((c != '^' && precedence(peek()) >= precedence(c)) ||
                    (c == '^' && precedence(peek()) > precedence(c))))
            {
                postfix += pop();
            }
            push(c);
        }
    }
    while (!isEmpty())
    {
        postfix += pop();
    }
    return postfix;
}
void printPostfix(string postfix)
{
    cout << "Postfix expression: " << postfix << endl;
}
void printInfix(string infix)
{
    cout << "Infix expression: " << infix << endl;
}

int evalutePostfix(string postfix)
{
    int countOfVariables = 0; // to track the number of variables
    bool used[26] = {false};  // assuming only a to z (small letters)
    for (char ch : postfix)
    {
        if (isalpha(ch) && !used[ch - 'a'])
        {                          // a, b, c, d .... hai and vo use nhi hua hai
            used[ch - 'a'] = true; // update that specific index to true
            countOfVariables++;    // increase the count of number of variables
        }
    }
    int values[26]; // since each index in used variable is representing the use of a to z characters, we have taken assuming the same.
    for (int i = 0; i < 26; i++)
    {
        if (used[i])
        {
            cout << "Provide the value for '" << char(i + 'a') << "': ";
            cin >> values[i];
        }
    }
    for (char ch : postfix)
    {
        if (isalpha(ch))
        {
            pushInt(values[ch - 'a']);
        }
        else if (isdigit(ch))
        {
            pushInt(ch - '0');
        }
        else
        {
            int b = popInt();
            int a = popInt();
            // alphabet k alwa buss operator ho skta hai isliye directly check kr rhe hai switch case mai konsa operation hai.
            switch (ch)
            {
            case '+':
                pushInt(a + b);
                break;
            case '-':
                pushInt(a - b);
                break;
            case '*':
                pushInt(a * b);
                break;
            case '/':
                pushInt(a / b);
                break;
            case '^':
                pushInt(pow(a, b));
                break;
            }
        }
    }
    return popInt();
}
int main()
{
    string infixExpression;
    int choice; 
    do{
        cout << "\nProvide an infix expression(provide lower case): ";
        cin >> infixExpression;
        cout << endl<< "Infix Expression: " << infixExpression << endl;
        
        string postfixExpression = infixToPostfixConversion(infixExpression);
        cout << endl<< "Postfix Expression: " << postfixExpression << endl;
        cout << endl<< evalutePostfix(postfixExpression);
        cout<<"\nAnother infix expression ? (1/0) "; cin>> choice;
    }while(choice != 0);
    
    // k+l-m*n+(o^p)*w/u/v*t+q
    return 0;
}
