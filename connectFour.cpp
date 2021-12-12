#include <iostream>
#include <string>
using namespace std;

char spaces[6][7];
int jrow[7] = {5, 5, 5, 5, 5, 5, 5};
bool on = true;

void init();
void board();
void checkWin(int row, int col);

int main()
{
    int i = 0;
    init();
    
    cout << "Connect 4" << endl;
    
    for (int loop = 0; loop < 21; loop++)
    {
        board();
        if (loop > 3)
        {
            checkWin(jrow[i] + 1, i);
        }
        if (on == false)
        {
            return 0;
        }
        cin >> i;
        i--;
        while (cin.fail() || i > 6 || jrow[i] < 0)
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Input was invalid, choose a different row." << endl;
            cin >> i;
            i--;
        }
        if (jrow[i] >= 0)
        {
            spaces[jrow[i]][i] = 'x';
            jrow[i]--;
        }
        
        board();
        if (loop > 2)
        {
            checkWin(jrow[i] + 1, i);
        }
        if (on == false)
        {
            return 0;
        }
        
        cin >> i;
        i--;
        while (cin.fail() || i > 6 || jrow[i] < 0)
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Input was invalid, choose a different row." << endl;
            cin >> i;
            i--;
        }
        if (jrow[i] >= 0)
        {
            spaces[jrow[i]][i] = 'o';
            jrow[i]--;
        }
    }
    cout << "It's a tie!";
}

void init()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            spaces[j][i] = ' ';
        }
    }
}

void board()
{
    cout
    << "  1   2   3   4   5   6   7" << endl
    << "| " << spaces[0][0] << " | " << spaces[0][1] << " | " << spaces[0][2] << " | " << spaces[0][3] << " | " << spaces[0][4] << " | " << spaces[0][5] << " | " << spaces[0][6] << " | " << endl
    << "-----------------------------" << endl
    << "| " << spaces[1][0] << " | " << spaces[1][1] << " | " << spaces[1][2] << " | " << spaces[1][3] << " | " << spaces[1][4] << " | " << spaces[1][5] << " | " << spaces[1][6] << " | " << endl
    << "-----------------------------" << endl
    << "| " << spaces[2][0] << " | " << spaces[2][1] << " | " << spaces[2][2] << " | " << spaces[2][3] << " | " << spaces[2][4] << " | " << spaces[2][5] << " | " << spaces[2][6] << " | " << endl
    << "-----------------------------" << endl
    << "| " << spaces[3][0] << " | " << spaces[3][1] << " | " << spaces[3][2] << " | " << spaces[3][3] << " | " << spaces[3][4] << " | " << spaces[3][5] << " | " << spaces[3][6] << " | " << endl
    << "-----------------------------" << endl
    << "| " << spaces[4][0] << " | " << spaces[4][1] << " | " << spaces[4][2] << " | " << spaces[4][3] << " | " << spaces[4][4] << " | " << spaces[4][5] << " | " << spaces[4][6] << " | " << endl
    << "-----------------------------" << endl
    << "| " << spaces[5][0] << " | " << spaces[5][1] << " | " << spaces[5][2] << " | " << spaces[5][3] << " | " << spaces[5][4] << " | " << spaces[5][5] << " | " << spaces[5][6] << " | " << endl
    << "-----------------------------" << endl;
}

void checkWin(int row, int col)
{
    int count = 0;
    for (int j = 3; j >= -3; j--)
    {
        if (spaces[row][col + j] == spaces[row][col])
        {
            count++;
        }
    }
    if (count >= 4)
    {
        count = 0;
        
        for (int k = -3; k <= 0; k++)
        {
            for (int j = k; j <= k + 3; j++)
            {
                if (spaces[row][col + j] == spaces[row][col] && col + j < 6 && col + j > -1)
                {
                    count++;
                }
            }
            if (count == 4)
            {
                if (spaces[row][col] == 'x')
                {
                    cout << "Player 1 Wins!";
                }
                else
                {
                    cout << "Player 2 Wins!";
                }
                on = false;
                break;
            }
            count = 0;
        }
    }
    
    count = 0;
    for (int j = 0; j <= 3; j++)
    {
        if (spaces[row + j][col] == spaces[row][col] && row + j < 7 && row + j > -1)
        {
            count++;
        }
        if (count == 4)
        {
            if (spaces[row][col] == 'x')
            {
                cout << "Player 1 Wins!";
            }
            else
            {
                cout << "Player 2 Wins!";
            }
            on = false;
            break;
        }
    }
    
    count = 0;
    for (int j = 3; j >= -3; j--)
    {
        if (spaces[row + j][col + j] == spaces[row][col])
        {
            count++;
        }
    }
    if (count >= 4)
    {
        count = 0;
        
        for (int k = -3; k <= 0; k++)
        {
            for (int j = k; j <= k + 3; j++)
            {
                if (spaces[row + j][col + j] == spaces[row][col] && row + j < 7 && row + j > -1 && col + j < 6 && col + j > -1)
                {
                    count++;
                }
            }
            if (count == 4)
            {
                if (spaces[row][col] == 'x')
                {
                    cout << "Player 1 Wins!";
                }
                else
                {
                    cout << "Player 2 Wins!";
                }
                on = false;
                break;
            }
            count = 0;
        }
    }
    
    count = 0;
    for (int j = 3; j >= -3; j--)
    {
        if (spaces[row + j][col - j] == spaces[row][col])
        {
            count++;
        }
    }
    if (count >= 4)
    {
        count = 0;
        
        for (int k = -3; k <= 0; k++)
        {
            for (int j = k; j <= k + 3; j++)
            {
                if (spaces[row + j][col - j] == spaces[row][col] && row + j  < 7 && row + j > -1 && col - j < 6 && col - j > -1)
                {
                    count++;
                }
            }
            if (count == 4)
            {
                if (spaces[row][col] == 'x')
                {
                    cout << "Player 1 Wins!";
                }
                else
                {
                    cout << "Player 2 Wins!";
                }
                on = false;
                break;
            }
            count = 0;
        }
    }
}

