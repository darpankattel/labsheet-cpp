// Assume that employee will have to pay 10 percent income tax to the government. Ask user to enter the employee salary. Use inline function to display the net payment to the employee by the company.
#include <iostream>
using namespace std;

inline void display(int salary)
{
    float netPatment = salary - (salary * 10 / 100);
    cout << "Net salary is: " << netPatment << endl;
}

int main() {
    int salary;
    cout << "Enter the salary: ";
    cin >> salary;
    display(salary);
    return 0;
}