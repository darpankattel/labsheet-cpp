// Write a program with an abstract class Student and create derive classes Engineering, Medicine and Science from base class Student. Create the objects of the derived classes and process them and access them using an array of pointers of type base class Student.

#include <iostream>
using namespace std;

class Student
{
public:
    Student()
    {
        cout << "Student constructor called" << endl;
    }
    virtual ~Student()
    {
        cout << "Student destructor called" << endl;
    }
    virtual void display() = 0;
};

class Engineering : public Student
{
    private:
        float marks;
    public:
        Engineering(float m = 0)
        {
            marks = m;
        }
        void display()
        {
            cout << "Engineering" << endl;
        }
};

class Medicine : public Student
{
    private:
        float marks;
    public:
        Medicine(float m = 0)
        {
            marks = m;
        }
        void display()
        {
            cout << "Medicine" << endl;
        }
};

class Science : public Student
{
    private:
        float marks;
    public:
        Science(float m = 0)
        {
            marks = m;
        }
        void display()
        {
            cout << "Science" << endl;
        }
};

int main ()
{
    Student *s[3];
    s[0] = new Engineering(90);
    s[1] = new Medicine(80);
    s[2] = new Science(70);
    for (int i = 0; i < 3; i++)
    {
        s[i]->display();
    }
    return 0;
}