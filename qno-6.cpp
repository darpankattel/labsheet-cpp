//Write a program that displays the current monthly salary of chief
// executive officer, information officer, and system analyst, 
// programmer that has been increased by 9, 10, 12, and 12 
// percentages respectively in year 2010. Let us assume that the
// salaries in year 2009 are
// Chief executive officer Rs. 35000/m
// Information officer Rs. 25000/m
// System analyst Rs. 24000/m
// Programmer Rs. 18000/m
// Make a function that takes two arguments; one salary and the 
//other increment. Use proper default argument.

#include<iostream>
using namespace std;

float getPresentSalary(float previousSalary, float increment)
{
    return previousSalary + (previousSalary * increment / 100);
}

int main()
{
    float ceoSalary = 35000;
    float ioSalary = 25000;
    float saSalary = 24000;
    float pSalary = 18000;
    float ceoSalary2010 = getPresentSalary(ceoSalary, 9);
    float ioSalary2010 = getPresentSalary(ioSalary, 10);
    float saSalary2010 = getPresentSalary(saSalary, 12);
    float pSalary2010 = getPresentSalary(pSalary, 12);
    cout << "Chief executive officer salary in year 2010 is Rs. " << ceoSalary2010 << "/m" << endl;
    cout << "Information officer salary in year 2010 is Rs. " << ioSalary2010 << "/m" << endl;
    cout << "System analyst salary in year 2010 is Rs. " << saSalary2010 << "/m" << endl;
    cout << "Programmer salary in year 2010 is Rs. " << pSalary2010 << "/m" << endl;
    return 0;
}

