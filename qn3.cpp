// Modify the stack class given in the previous lab to add the exception when a user tries to add an item while the stack is full and when the user tries to add the item while the stack is empty. Throw exceptions in both of the cases and handle these exceptions.

#include <iostream>
using namespace std;

template <class T>
class Stack
{
    private:
        T *arr;
        int size;
        int top;
    public:
        class StackFullException {
            public:
                string message = "Stack Exception: Stack is full";
        };
        class StackEmptyException {
            public:
                string message = "Stack Exception: Stack is empty";
        };
        Stack(int size = 0)
        {
            this->size = size;
            this->top = -1;
            this->arr = new T[size];
        }
        void insert(T data)
        {
            if (top == size - 1)
            {
                throw StackFullException();
            }
            arr[++top] = data;
        }
        T pop()
        {
            if (top == -1)
            {
                throw StackEmptyException();
            }
            return arr[top--];
        }
        void display()
        {
            for (int i = 0; i <= top; i++)
            {
                if (i == top)
                {
                    cout << arr[top-i] << endl;
                }
                else
                {
                    cout << arr[top-i] << ", ";
                }
            }
        }
};

int main ()
{
    Stack<int> q1(3);
    try{
        q1.insert(1);
        q1.insert(2);
        q1.insert(3);
        q1.display();
        q1.pop();
        q1.display();
        q1.insert(6);
        q1.insert(7);
    }
    catch (Stack<int>::StackFullException e)
    {
        cout << e.message << endl;
    }
    catch (Stack<int>::StackEmptyException e)
    {
        cout << e.message << endl;
    }
    catch (...)
    {
        cout << "Unknown exception" << endl;
    }

    Stack<double> q2(3);
    try{
        q2.insert(1.1);
        q2.insert(2.2);
        q2.insert(3.3);
        q2.display();
        q2.pop();
        q2.display();
        q2.insert(6.6);
        q2.insert(7.7);
    }
    catch (Stack<double>::StackFullException e)
    {
        cout << e.message << endl;
    }
    catch (Stack<double>::StackEmptyException e)
    {
        cout << e.message << endl;
    }
    catch (...)
    {
        cout << "Unknown exception" << endl;
    }
    return 0;
}