// Assume that one constructor initializes data member say num_vehicle, hour, and rate. There should be a 10% discount if num_vehicle exceeds 10. Display the total charge. Use two objects and show a bit-by-bit copy of one object to another (make your own copy constructor).
#include <iostream>
using namespace std;
class Vehicle
{
    private:
        int num_vehicle;
        int hour;
        double rate;
    public:
        Vehicle(int n = 0, int h = 0, double r = 0.0)
        {
            num_vehicle = n;
            hour = h;
            rate = r;
        }
        ~Vehicle()
        {
        }
        void setVehicle(int n = 0, int h = 0, double r = 0.0)
        {
            num_vehicle = n;
            hour = h;
            rate = r;
        }
        double totalCharge()
        {
            double total = hour * rate;
            if(num_vehicle > 10)
            {
                total *= 0.9;
            }
            return total;
        }
        void display()
        {
            cout << "Number of Vehicle: " << num_vehicle << endl;
            cout << "Hour: " << hour << endl;
            cout << "Rate: " << rate << endl;
            cout << "Total Charge: " << totalCharge() << endl;
        }
};

int main()
{
    Vehicle v1(10, 2, 10.0);
    Vehicle v2(20, 3, 20.0);
    v1.display();
    v2.display();
    Vehicle v3(v1);
    v3.display();
    return 0;
}