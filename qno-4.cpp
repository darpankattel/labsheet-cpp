// Write a function that passes two temperatures by reference and sets the larger of the two numbers to a value entered by user by using return by reference.

#include <iostream>
using namespace std;

void intendedFunction(int &temp1, int &temp2) {
    int temp3;
    cout << "Enter the value you want to replace the larger number with: ";
    cin >> temp3;
    if (temp1 > temp2) {
        temp1 = temp3;
    } else {
        temp2 = temp3;
    }
}

int main()
{
    int temp1, temp2;
    cout << "Enter the first temperature: ";
    cin >> temp1;
    cout << "Enter the second temperature: ";
    cin >> temp2;
    intendedFunction(temp1, temp2);
    return 0;
}