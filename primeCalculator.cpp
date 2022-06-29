#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    
    cout << "How many primes do you want to generate? ";
    cin >> n;
    
    while (cin.fail() || n < 1)
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Error: enter a positive number: ";
        cin >> n;
    }
    
    int i = 1;
    int comp = 0;
    
    cout << "2" << endl;
    float j = 1;

    while (i < n)
    {
        j += 2;
        for (int k = 3; k < j / 2; k = k + 2)
        {
            if (j / k == floor(j / k))
            {
                comp = 1;
            }
            if (comp == 1)
            {
                break;
            }
        }
        if (comp == 0)
        {
            cout << j << endl;
            i++;
        }
        comp = 0;
    }
    
    return 0;
}



