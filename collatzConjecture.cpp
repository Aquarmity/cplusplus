/*This program follows the Collatz conjecture: Take a positive integer; if it is **
**even, divide it by two. If it is odd, do 3n + 1. The conjecture is that all    **
**numbers eventually lead to 1. While this program is not designed to find values**
**that don't lead to 1, it does show the paths to 1 and how many cycles it takes **
**to get there. The amount of cycles seems to be entirely random, and vary wildly**
**even between two sequential integers. No numbers are known to not lead to 1.   **
**Every number up to 2^68 has been proven to fit into this conjecture.           */

#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n;
    vector<int> path;
    
    while (true)
    {
        int k = 0;
        path.clear();
        
        cin >> n;
        
        if (n <= 0)
        {
            cout << "Please enter a valid positive integer." << endl;
        }
        else
        {
            while (n != 1)
            {
                if (n % 2 == 0)
                {
                    n = n / 2;
                    path.push_back(n);
                }
                else
                {
                    n = 3 * n + 1;
                    path.push_back(n);
                }
                k++;
            }
            
            cout << k << " cycles: ";
            
            for (auto i = path.begin(); i != path.end(); ++i)
            {
                cout << *i << " ";
            }
            
            cout << endl;
        }
    }
}
