#include <iostream>
using namespace std;

void dispGame();
void attack(int i, int j);
bool split(int i);

int hands[4] = {1, 1, 1, 1};
int turn = 0;
int on = 1;
 
int main()
{
    int choices[4];
    
    cout << "CONTROLS:\nInput 1 to use your left hand, 2 to use your right.\nHit enter, then type 1 to attack your opponent's left hand, and 2 to attack their right hand. Type 3 to split\n\n";
    while (on == 1)
    {
        turn = 0;
        dispGame();
        cout << "1: ";
        cin >> choices[0];
        cin >> choices[1];
        while (cin.fail() || choices[0] < 1 || choices[0] > 2 || choices[1] < 1 || choices[1] > 3 || hands[choices[0] - 1] == 0 || hands[choices[1] + 1] == 0 && choices[1] != 3 || choices[1] == 3 && !split(choices[0] - 1))
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Input(s) was invalid, please reenter both inputs." << endl;
            cin >> choices[0];
            cin >> choices[1];
        }
        choices[0]--;
        choices[1]++;
        attack(choices[0], choices[1]);
        
        if (on == 0)
        {
            break;
        }
        
        turn = 2;
        dispGame();
        cout << "2: ";
        cin >> choices[2];
        cin >> choices[3];
        while (cin.fail() || choices[2] < 1 || choices[2] > 2 || choices[3] < 1 || choices[3] > 3 || hands[choices[2] + 1] == 0 || hands[choices[3] - 1] == 0 && choices[3] != 3 || choices[3] == 3 && !split(choices[2] - 1))
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Input(s) was invalid, please reenter both inputs." << endl;
            cin >> choices[2];
            cin >> choices[3];
        }
        choices[2]++;
        choices[3]--;
        attack(choices[2], choices[3]);
    }
    
    
    return 0;
}

void dispGame()
{
    cout << "Player 1: " << hands[0] << "   " << hands[1] << endl;
    cout << "Player 2: " << hands[2] << "   " << hands[3] << endl;
}

void attack(int i, int j)
{
    if (turn == 0 && j == 4 || turn == 2 && j == 2)
    {
        hands[i] /= 2;
        
        if (i % 2 == 0)
        {
            hands[i + 1] = hands[i];
        }
        else
        {
            hands[i - 1] = hands[i];
        }
    }
    else
    {
        hands[j] = (hands[j] + hands[i]) % 5;
    }
    
    switch (turn)
    {
        case 0:
            if (hands[2] == 0 && hands[3] == 0)
            {
                dispGame();
                cout << "Player 1 Wins!";
                on = 0;
            }
            break;
        case 2:
            if (hands[0] == 0 && hands[1] == 0)
            {
                dispGame();
                cout << "Player 2 Wins!";
                on = 0;
            }
            break;
    }
}

bool split(int i)
{
    if (i == 0) //if the hand is even
    {
        if (hands[i + turn] % 2 == 0 && hands[i + 1] == 0)
        {
            return true;
        }
    }
    else if (i == 1) //if hand is odd
    {
        if (hands[i + turn] % 2 == 0 && hands[i + turn - 1] == 0)
        {
            return true;
        }
    }
    return false;
}



