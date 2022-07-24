// Write a program to create a class shape with functions to find the area of the shapes and display the names of the shapes and other essential components of the class. Create derived classes circle, rectangle, and trapezoid each having overriding functions area() and display(). Write a suitable program to illustrate virtual functions and virtual destructors.

#include <iostream>
using namespace std;

class Shape
{
public:
    Shape()
    {
        cout << "Shape constructor called" << endl;
    }
    virtual ~Shape()
    {
        cout << "Shape destructor called" << endl;
    }
    virtual void area() = 0;
    virtual void display() = 0;
};

class Circle : public Shape
{
    private:
        float radius;
    public:
        Circle(float r = 0)
        {
            radius = r;
        }
        void area()
        {
            cout << "Area of Circle: " << 3.14 * radius * radius << endl;
        }
        void display()
        {
            cout << "Circle" << endl;
        }
};

class Rectangle : public Shape
{
    private:
        float length;
        float breadth;
    public:
        Rectangle(float l = 0, float b = 0)
        {
            length = l;
            breadth = b;
        }
        void area()
        {
            cout << "Area of Rectangle: " << length * breadth << endl;
        }
        void display()
        {
            cout << "Rectangle" << endl;
        }
};

class Trapezoid : public Shape
{
    private:
        float base1;
        float base2;
        float height;
    public:
        Trapezoid(float b1 = 0, float b2 = 0, float h = 0)
        {
            base1 = b1;
            base2 = b2;
            height = h;
        }
        void area()
        {
            cout << "Area of Trapezoid: " << (base1 + base2) * height / 2 << endl;
        }
        void display()
        {
            cout << "Trapezoid" << endl;
        }
};

int main ()
{
    Shape *s;
    Circle c(5);
    Rectangle r(5, 6);
    Trapezoid t(5, 6, 7);
    s = &c;
    s->area();
    s->display();
    s = &r;
    s->area();
    s->display();
    s = &t;
    s->area();
    s->display();
    return 0;
}