// Create a polymorphic class Vehicle and create other derived classes Bus, Car, and Bike from Vehicle. Illustrate RTTI by the use of dynamic_cast and typeid operators in this program.

#include <iostream>
using namespace std;

class Vehicle
{
public:
    Vehicle()
    {
        cout << "Vehicle constructor called" << endl;
    }
    virtual ~Vehicle()
    {
        cout << "Vehicle destructor called" << endl;
    }
    virtual void display() = 0;
};

class Bus : public Vehicle
{
    private:
        float speed;
    public:
        Bus(float s = 0)
        {
            speed = s;
        }
        void display()
        {
            cout << "Bus" << endl;
        }
};

class Car : public Vehicle
{
    private:
        float speed;
    public:
        Car(float s = 0)
        {
            speed = s;
        }
        void display()
        {
            cout << "Car" << endl;
        }
};

class Bike : public Vehicle
{
    private:
        float speed;
    public:
        Bike(float s = 0)
        {
            speed = s;
        }
        void display()
        {
            cout << "Bike" << endl;
        }
};

int main ()
{
    Vehicle *v;
    Bus b(100);
    Car c(200);
    Bike b1(300);
    v = &b;
    v->display();
    v = &c;
    v->display();
    v = &b1;
    v->display();
    return 0;
}