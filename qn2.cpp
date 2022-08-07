// Write a class template for queue class. Assume the programmer using the queue won't make mistakes, like exceeding the capacity of the queue or trying to remove an item when the queue is empty. Define several queues of different data types and insert and remove data from them.

#include <iostream>
using namespace std;

template <class T>
class Queue
{
    private:
        T *arr;
        int size;
        int rear;
    public:
        Queue(int size = 0)
        {
            this->size = size;
            this->rear = -1;
            this->arr = new T[size];
        }
        ~Queue()
        {
            delete [] arr;
        }
        void insert(T data)
        {
            arr[++rear] = data;
        }
        T remove()
        {
            T data = arr[0];
            for (int i = 0; i < rear; i++)
            {
                arr[i] = arr[i + 1];
            }
            rear--;
            return data;
        }
        void display()
        {
            for (int i = 0; i <= rear; i++)
            {
                if (i == rear)
                {
                    cout << arr[i] << endl;
                }
                else
                {
                    cout << arr[i] << ", ";
                }
            }
            cout << endl;
        }
};

int main ()
{
    Queue<int> q1(5);
    q1.insert(1);
    q1.insert(2);
    q1.insert(3);
    q1.insert(4);
    q1.insert(5);
    q1.display();
    q1.remove();
    q1.display();
    Queue<double> q2(5);
    q2.insert(1.1);
    q2.insert(2.2);
    q2.insert(3.3);
    q2.insert(4.4);
    q2.insert(5.5);
    q2.display();
    q2.remove();
    q2.display();
    return 0;
}