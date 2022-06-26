// Write a program that has a class to represent time. The class should have constructors to initialize data members hour, minute, and second to 0 and to initialize them to values passed as arguments. The class should have a member function to add time objects and return the result as a time object. There should be functions to display time in 12-hour and 24-hour format.

#include <iostream>
#include <string>

class Time
{
    private:
    int hour;
    int minute;
    int second;
    public:
    Time(int h = 0, int m = 0, int s = 0)
    {
        hour = h;
        minute = m;
        second = s;
    }
    void setTime(int h = 0, int m = 0, int s = 0)
    {
        hour = h;
        minute = m;
        second = s;
    }
    std::string addTime(Time t, int format = 12)
    {
        int totalSeconds = second + t.second;
        int totalMinutes = minute + t.minute;
        int totalHours = hour + t.hour;
        if(totalSeconds >= 60)
        {
            totalMinutes++;
            totalSeconds -= 60;
        }
        if(totalMinutes >= 60)
        {
            totalHours++;
            totalMinutes -= 60;
        }
        if(totalHours >= 24)
        {
            totalHours -= 24;
        }
        if(format == 12)
        {
            if(totalHours > 12)
            {
                totalHours -= 12;
            }
            if(totalHours == 0)
            {
                totalHours = 12;
            }
        }
        return std::to_string(totalHours) + ":" + std::to_string(totalMinutes) + ":" + std::to_string(totalSeconds);
    }
    void displayTime(int format = 12)
    {
        if(format == 12)
        {
            int tempHour = hour;
            if(tempHour > 12)
            {
                tempHour -= 12;
            }
            if(tempHour == 0)
            {
                tempHour = 12;
            }
            std::cout << tempHour << ":" << minute << ":" << second << std::endl;
        }
        else{
            std::cout << hour << ":" << minute << ":" << second << std::endl;
        }
    }
};

int main()
{
    Time t1(1, 2, 3);
    Time t2(4, 5, 6);
    std::cout << t1.addTime(t2, 12) << std::endl;
    t1.displayTime(12);
    t2.displayTime();
    Time t3(14, 8, 9);
    t3.displayTime(24);
    t3.displayTime(12);
    return 0;
}