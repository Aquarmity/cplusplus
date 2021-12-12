#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

void AAS();
void ASA();
void SSA();
void SAS();
void SSS();
void dumb();
float A, B, C, a, b, c, area;

int main()
{
    int choice;
    while (true)
    {
        cout << "\n1: AAS, 2: ASA, 3: SSA, 4: SAS, 5: SSS, 6: Angle with Area\n";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                AAS();
                break;
            case 2:
                ASA();
                break;
            case 3:
                SSA();
                break;
            case 4:
                SAS();
                break;
            case 5:
                SSS();
                break;
            case 6:
                dumb();
                break;
        }
            
    }
}

void AAS()
{
    cout << "Enter angle A, angle B, side a\n";
    cin >> A >> B >> a;
    
    b = (a * sin(B * (M_PI / 180))) / sin(A * (M_PI / 180));
    C = 180 - (A + B);
    c = (a * sin(C * (M_PI / 180))) / sin(A * (M_PI / 180));
    area = 0.5 * a * b * sin(C * (M_PI / 180));
    cout << "A: " << A << " B: " << B << " C: " << C << " a: " << a << " b: " << b << " c: " << c << endl << "Area: " << area;
}

void ASA()
{
    cout << "Enter angle A, angle B, side c\n";
    cin >> A >> B >> c;
    C = 180 - (A + B);
    a = (c * sin(A * (M_PI / 180))) / sin(C * (M_PI / 180));
    b = (c * sin(B * (M_PI / 180))) / sin(C * (M_PI / 180));
    area = 0.5 * a * b * sin(C * (M_PI / 180));
    cout << "A: " << A << " B: " << B << " C: " << C << " a: " << a << " b: " << b << " c: " << c << endl << "Area: " << area;
}

void SSA()
{
    cout << "Enter side a, side b, angle A\n";
    cin >> a >> b >> A;
    B = asin((sin(A * (M_PI / 180)) * b) / a) * (180 / M_PI);
    cout << "B = " << B << " or " << (180 - B);
}

void SAS()
{
    cout << "Enter side a, angle C, side b\n";
    cin >> a >> C >> b;
    c = sqrt(pow(a, 2) + pow(b, 2) - (2 * a * b * cos(C * (M_PI / 180))));
    A = acos((pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c)) * (180 / M_PI);
    B = acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a * c)) * (180 / M_PI);
    area = 0.5 * a * b * sin(C * (M_PI / 180));
    cout << "A: " << A << " B: " << B << " C: " << C << " a: " << a << " b: " << b << " c: " << c << endl << "Area: " << area;
}

void SSS()
{
    cout << "Enter side a, side b, side c\n";
    cin >> a >> b >> c;
    A = acos((pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c)) * (180 / M_PI);
    B = acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a * c)) * (180 / M_PI);
    C = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b)) * (180 / M_PI);
    area = 0.5 * a * b * sin(C * (M_PI / 180));
    cout << "A: " << A << " B: " << B << " C: " << C << " a: " << a << " b: " << b << " c: " << c << endl << "Area: " << area;
}

void dumb()
{
    cout << "Enter side a, side b, and area\n";
    cin >> a >> b >> area;
    C = asin(area / (0.5 * a * b)) * (180 / M_PI);
    cout << "C: " << C << " or " << 180 - C;
}

