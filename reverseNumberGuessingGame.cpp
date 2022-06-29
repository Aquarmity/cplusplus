#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int resp;
    int rounds = 0;
    float upper = 100;
    float lower = 0;
    cout << "Controls:" << endl
         << "1 = Greater than" << endl
         << "2 = Less than" << endl
         << "3 = Equal to (Guessed correctly)" << endl
         << "Think of a whole number between 1 - 100." << endl
         << "Is your number greater than, less than, or equal to 50?" << endl;
    while (rounds < 9 || resp == 3)
    {
        if (resp == 3)
        {
            cout << "It took me " << rounds << " guesses to guess your number!" << endl;
            return 0;
        }
        if (resp == 1)
        {
            lower = floor((upper + lower) / 2);
            if (lower == 99)
            {
                cout << "Hmm... How about 100? ";
            }
            else
            {
                cout << "Hmm... How about " << floor((upper + lower) / 2) << "? ";
            }
        }
        if (resp == 2)
        {
            upper = floor((upper + lower) / 2);
            if (upper == 1)
            {
                break;
            }
            cout << "Hmm... How about " << floor((upper + lower) / 2) << "? ";
        }
        rounds++;
        cin >> resp;
    }
    cout << "I think you're cheating, I should've guessed by now!";

    return 0;
}