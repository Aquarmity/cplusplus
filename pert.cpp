#include <iostream>
#include <cmath>
using namespace std;

void ASolve();
void PSolve();
void rSolve();
void tSolve();
float A, P, r, t;

int main()
{
    int choice;
    
    cout << "Solve for" << endl << "1: A" << endl << "2: P" << endl << "3: r" << endl << "4: t" << endl;
    cin >> choice;
    
    switch (choice)
    {
        case 1:
            ASolve();
            break;
            
        case 2:
            PSolve();
            break;
            
        case 3:
            rSolve();
            break;
            
        case 4:
            tSolve();
            break;
        
        default:
            break;
    }
    
    return 0;
}

void ASolve()
{
    cout << "P = ";
    cin >> P;
    
    cout << "r = ";
    cin >> r;
    
    cout << "t = ";
    cin >> t;
    
    A = P * exp(r * t);
    cout << "A = " << A;
}

void PSolve()
{
    cout << "A = ";
    cin >> A;
    
    cout << "r = ";
    cin >> r;
    
    cout << "t = ";
    cin >> t;
    
    P = A / exp(r * t);
    cout << "P = " << P;
}

void rSolve()
{
    cout << "A = ";
    cin >> A;
    
    cout << "P = ";
    cin >> P;
    
    cout << "t = ";
    cin >> t;
    
    r = (log(A / P)) / t;
    cout << "r = " << r;
}

void tSolve()
{
    cout << "A = ";
    cin >> A;
    
    cout << "P = ";
    cin >> P;
    
    cout << "r = ";
    cin >> r;
    
    t = (log(A / P)) / r;
    cout << "t = " << t;
}

