#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int v;
    float rX = 0;
    float rY = 0;
    float rM, rD;
    while (true)
    {
        cout << "How many vectors? ";
        cin >> v;
        
        float m[v], d[v], x[v], y[v];
        for (int i = 0; i < v; i++)
        {
            cout << "Magnitude and direction of vector " << i + 1 << ": ";
            cin >> m[i] >> d[i];
            x[i] = m[i] * cos(d[i] * (M_PI / 180));
            y[i] = m[i] * sin(d[i] * (M_PI / 180));
            rX += x[i];
            rY += y[i];
        }
        for (int i = 0; i < v; i++)
        {
            cout << "Vector " << i + 1 << ": <" << x[i] << ", " << y[i] << ">" << endl;
        }
        cout << "Resultant vector: <" << rX << ", " << rY << ">" << endl;
        rM = sqrt(pow(rX, 2) + pow(rY, 2));
        rD = atan(rY / rX) * (180 / M_PI);
        cout << "Resultant magnitude: " << rM << endl << "Resultant direction: " << rD << " or " << rD + 180 << endl;
    }
}


