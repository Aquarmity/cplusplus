#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    char slash;
    int year;
    int month;
    int day;
    int date;
    int leap;
    int anchor; //the day the doomsday lands on
    int century;
    bool leapYear;

    cout << "Enter the date in mm/dd/yyyy format: ";
    cin >> month >> slash >> day >> slash >> year;
    while (cin.fail() || month > 12 || day > 31) //error checks - won't take input besides numbers
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Invalid input, please enter the date in mm/dd/yyyy format: ";
        cin >> month >> slash >> day >> slash >> year;
    }

    century = floor(year / 100);
    leap = floor(year - (century * 100)) / 4;
    anchor = (((5 * (century % 4)) % 7 + 2) + (year - (century * 100)) + leap) % 7; //First half finds the anchor for the first of the century, second half adjusts for the specific year of the century.

    if (year % 4 == 0 && year % 100 != 0)
    {
        leapYear = true;
    }
    else if (year % 400 == 0)
    {
        leapYear = true;
    }
    else
    {
        leapYear = false;
    }

    switch (month) //finds distance from a doomsday
    {
        case 1:
            if (leapYear == true)
            {
                day -= 3;
            }
            else
            {
                day -= 4;
            }
            break;
        case 2:
            if (leapYear == true)
            {
                day -= 28;
            }
            else
            {
                day -= 29;
            }
            break;
        case 3:
            day -= 14;
            break;
        case 4:
            day -= 4;
            break;
        case 5:
            day -= 9;
            break;
        case 6:
            day -= 6;
            break;
        case 7:
            day -= 11;
            break;
        case 8:
            day -= 8;
            break;
        case 9:
            day -= 5;
            break;
        case 10:
            day -= 10;
            break;
        case 11:
            day -= 7;
            break;
        case 12:
            day -= 12;
            break;
    }

    day = anchor + (day % 7);

    cout << "The date was a ";
    switch (day)
    {
        case 0:
            cout << "Sunday";
            break;
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout << "Wednesday";
            break;
        case 4:
            cout << "Thursday";
            break;
        case 5:
            cout << "Friday";
            break;
        case 6:
            cout << "Saturday";
            break;
        default:
            cout << "Error " << day;
            break;
    }

    return 0;
}