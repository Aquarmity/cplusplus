#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

int main()
{
    float x1, x2, y1, y2, m, b;
    
    cout << "x-value of point 1: ";
    cin >> x1;
    
    cout << "y-value of point 1: ";
    cin >> y1;
    
    cout << "x-value of point 2: ";
    cin >> x2;
    
    cout << "y-value of point 2: ";
    cin >> y2;
    
    if (cin.fail())
    {
        cout << "input was invalid, try again.";
        return 0;
    }
    
    m = (y2 - y1) / (x2 - x1);
    b = y1 - (m * x1);
    
    cout << "y = ";
    
    if (m == 0)
    {
        cout << b;
        return 0;
    }
    else if (m == 1)
    {
        cout << "x";
    }
    else
    {
        cout << m << "x";
    }
    if (b > 0)
    {
        cout << " + " << b;
    }
    else if (b < 0)
    {
        cout << " - " << abs(b);
    }
    
    return 0;
}