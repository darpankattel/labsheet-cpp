// Create a function called sum() that returns the sum of the elements of an array. Make this function into a template so it will work with any numerical type. Write a program that applies this function to data of various types.

#include <iostream>
using namespace std;


template <class T>
T sum(T *arr, int size)
{
    T sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    double arr2[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << sum(arr, 5) << endl;
    cout << sum(arr2, 5) << endl;
    return 0;
}