#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class stack
{
private:
    node *head;

public:
    stack()
    {
        head = NULL;
    }
    void push(int);
    void pop();
    bool isEmpty();
    int top();
};

void stack::push(int val)
{
    if (isEmpty())
    {
        head = new node(val);
    }
    else
    {
        node *temp = new node(val);
        temp->next = head;
        head = temp;
    }
}

void stack::pop()
{
    if (!isEmpty())
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
    else
        cout << "stack underflow" << endl;
}

bool stack::isEmpty()
{
    if (head != NULL)
    {
        return false;
    }
    return true;
}

int stack::top()
{
    if (isEmpty())
        return -1;
    return head->data;
}

int main()
{
    stack st;
    while (1)
    {
        cout << "1 : push" << endl;
        cout << "2 : pop" << endl;
        cout << "3 : isEmpty" << endl;
        cout << "4 : top" << endl;
        cout << "press any key to exit accept above" << endl;
        char operation;
        cin >> operation;
        switch (operation)
        {
        case '1':
        {
            int val;
            cout << "Enter the value" << endl;
            cin >> val;
            st.push(val);
        }
        break;
        case '2':
            st.pop();
            break;
        case '3':
            cout << st.isEmpty() << endl;
            break;
        case '4':
            cout << st.top() << endl;
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}
