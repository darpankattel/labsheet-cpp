// Create a class Person and two derived classes Employee and Student, inherited from class Person. Now create a class Manager which is derived from two base classes Employee and Student. Show the use of the virtual base class.

#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "Person constructor called" << endl;
    }
    virtual ~Person()
    {
        cout << "Person destructor called" << endl;
    }
    virtual void display() = 0;
};

class Employee : public Person
{
    private:
        float salary;
    public:
        Employee(float s = 0)
        {
            salary = s;
        }
        void display()
        {
            cout << "Employee" << endl;
        }
};

class Student : public Person
{
    private:
        float marks;
    public:
        Student(float m = 0)
        {
            marks = m;
        }
        void display()
        {
            cout << "Student" << endl;
        }
};

class Manager : public Employee, public Student
{
    public:
        Manager(float s = 0, float m = 0) : Employee(s), Student(m)
        {
        }
        void display()
        {
            cout << "Manager" << endl;
        }
};

int main ()
{
    Manager m(10000, 90);
    m.display();
    return 0;
}