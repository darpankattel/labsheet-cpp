// Write a program that has a class with a dynamically allocated character array as its data member. One object should contain "Engineers are" and another should contain " Creatures of logic". Member function join() should concatenate two strings by passing two objects as arguments. Display the concatenated string through a member function. Use constructors to allocate and initialize the data member. Also, write a destructor to free the allocated memory for the character array. Make your own function for the concatenation of two strings.

#include <iostream>
#include <string>
using namespace std;
class String
{
    private:
        char *str;
    public:
        String(char *s = "")
        {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
        ~String()
        {
            delete [] str;
        }
        void join(String s1, String s2)
        {
            str = new char[strlen(s1.str) + strlen(s2.str) + 1];
            strcpy(str, s1.str);
            strcat(str, s2.str);
        }
        void display()
        {
            cout << str << endl;
        }
};

int main()
{
    String s1("Engineers are");
    String s2("Creatures of logic");
    s1.join(s1, s2);
    s1.display();
    return 0;
}