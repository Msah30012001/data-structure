#include <iostream>
using namespace std;

class stack
{
private:
    int size, Top, *arr;

public:
    stack(int size)
    {
        this->size = size;
        Top = -1;
        arr = new int[this->size];
    }
    void push(int);
    void pop();
    bool isEmpty();
    bool isFull();
    int top();
};

void stack::push(int val)
{
    if (!isFull())
        arr[++Top] = val;
    else
        cout << "stack overflow" << endl;
}

void stack::pop()
{
    if (!isEmpty())
        Top--;
    else
        cout << "stack underflow" << endl;
}

bool stack::isEmpty()
{
    if (Top != -1)
    {
        return false;
    }
    return true;
}

bool stack::isFull()
{
    if (size - 1 != Top)
    {
        return false;
    }
    return true;
}

int stack::top()
{
    return arr[Top];
}

int main()
{
    int size;
    cout << "Enter the size of stack" << endl;
    cin >> size;
    stack st(size);
    while (1)
    {
        cout << "1 : push" << endl;
        cout << "2 : pop" << endl;
        cout << "3 : isEmpty" << endl;
        cout << "4 : isFull" << endl;
        cout << "5 : top" << endl;
        cout << "ESC : exit" << endl;
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
            cout << st.isFull() << endl;
            break;
        case '5':
            cout << st.top() << endl;
            break;
        default:
            exit(1);
            break;
        }
    }
    return 0;
}