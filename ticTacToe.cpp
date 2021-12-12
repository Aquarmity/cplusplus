#include <iostream>
#include <string>
using namespace std;

char xoro[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
bool on = true;

void board();
void checkWin();

int main()
{
    int input1;
    int input2;
    
    for (int i = 1; i <= 5; i++)
    {
        board();
        if (i >= 3)
        {
        checkWin();
        }
        if (on == false)
        {
            return 0;
        }
        cin >> input1;
        while (cin.fail() || input1 > 9 || xoro[input1 - 1] != ' ')
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Input was invalid, choose a space not taken." << endl;
            cin >> input1;
        }
        xoro[input1 - 1] = 'X';
        board();
        if (i >= 3)
        {
            checkWin();
        }
        if (on == false)
        {
          return 0;
        }
        if (i == 5)
        {
            break;
        }
        
        cin >> input2;
        while (cin.fail() || input2 > 9 || xoro[input2 - 1] != ' ')
        {
            cin.clear();
            cin.ignore();
            cout << "Input was invalid, choose a space not taken." << endl;
            cin >> input2;
        }
        xoro[input2 - 1] = 'O';
    }
    cout << "It's a tie!";
    return 0;
}

void board()
{
    cout << "  1  |  2  |  3  " << endl;
    cout << "  " << xoro[0] << "  |  " << xoro[1] << "  |  " << xoro[2] << "    " << endl;
    cout << "     |     |     " << endl;
    cout << "-----------------" << endl;
    cout << "  4  |  5  |  6  " << endl;
    cout << "  " << xoro[3] << "  |  " << xoro[4] << "  |  " << xoro[5] << "    " << endl;
    cout << "     |     |     " << endl;
    cout << "-----------------" << endl;
    cout << "  7  |  8  |  9  " << endl;
    cout << "  " << xoro[6] << "  |  " << xoro[7] << "  |  " << xoro[8] << "    " << endl;
    cout << "     |     |     " << endl;
}

void checkWin()
{
    int choice;
    
    for (int i = 0; i < 7; i++)
    {
        if (xoro[0 + i] == xoro[1 + i] && xoro[0 + i] == xoro[2 + i] && xoro[0 + i] != ' ')
        {
            if (xoro[0 + i] == 'X')
            {
                cout << "Player 1 Wins!" << endl;
            }
            else
            {
                cout << "Player 2 Wins!" << endl;
            }
        on = false;
        }
        i = i + 2;
    }
    for (int i = 0; i < 3; i++)
    {
        if (xoro[0 + i] == xoro[3 + i] && xoro[0 + i] == xoro[6 + i] && xoro[0 + i] != ' ')
        {
            if (xoro[0 + i] == 'X')
            {
                cout << "Player 1 Wins!" << endl;
            }
            else
            {
                cout << "Player 2 Wins!" << endl;
            }
        on = false;
        }
    }
    if (xoro[0] == xoro[4] && xoro[0] == xoro[8] && xoro[0] != ' ')
    {
        if (xoro[0] == 'X')
        {
            cout << "Player 1 Wins!" << endl;
        }
        else
        {
            cout << "Player 2 Wins!" << endl;
        }
        on = false;
    }
    if (xoro[2] == xoro[4] && xoro[2] == xoro[6] && xoro[2] != ' ')
    {
        if (xoro[2] == 'X')
        {
            cout << "Player 1 Wins!" << endl;
        }
        else
        {
            cout << "Player 2 Wins!" << endl;
        }
        on = false;
    }
}


