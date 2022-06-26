// Create a class with a data member to hold a "serial number" for each object created from the class. That is, the first object created will be numbered 1, the second 2, and so on by using the basic concept of static data members. Use static member function if it is useful in the program. Otherwise, make a separate program that demonstrates the use of static member function.
#include <iostream>

class Product
{
    private:
        int serialNumber;
        double price;
    public:
        static int count;
        Product(double p = 0.0)
        {
            serialNumber = count;
            count++;
            price = p;
        }
        ~Product()
        {
            count--;
        }
        void setPrice(double p)
        {
            price = p;
        }
        void display()
        {
            std::cout << "Serial Number: " << serialNumber << std::endl;
            std::cout << "Price: " << price << std::endl;
        }

};

int Product::count = 0;
int main()
{
    Product p1(10.00);
    Product p2(20.00);
    Product p3(30.00);
    p1.display();
    p2.display();
    p3.display();
    return 0;
}