
//UNFINISHED

#include <iostream>
using namespace std;

//board
char spaces[8][8];

//file as a character
char fileInit;
//file converted to an integer to be used on the board
int fileInitInt;
//rank is already an integer
int rankInit;
//target space
char fileTarg;
int fileTargInt;
int rankTarg;

//white or black's turn
int turn;

//for converting files to integer
int intForm;

void setBoard();
void displayBoard();
void move();
void moveCheck();
void fileConvert(char file);

int main()
{
    setBoard();
    
    while (true)
    {
        displayBoard();
        turn = 1;
        
        cin >> fileInit >> rankInit;
        cin >> fileTarg >> rankTarg;
        
        fileConvert(fileInit);
        fileInitInt = intForm;
        fileConvert(fileTarg);
        fileTargInt = intForm;
        //if input is less than 0 or higher than 8 or yadda yadda then retake the input
        
        
        rankInit -= 1;
        rankTarg -= 1;
        
        moveCheck();
    }
    
    
    return 0;
}

void displayBoard()
{
    cout
    << "  a   b   c   d   e   f   g   h" << endl
    << "--------------------------------" << endl
    << "| " << spaces[7][0] << " | " << spaces[7][1] << " | " << spaces[7][2] << " | " << spaces[7][3] << " | " << spaces[7][4] << " | " << spaces[7][5] << " | " << spaces[7][6] << " | " << spaces [7][7] << " | 8" << endl
    << "--------------------------------" << endl
    << "| " << spaces[6][0] << " | " << spaces[6][1] << " | " << spaces[6][2] << " | " << spaces[6][3] << " | " << spaces[6][4] << " | " << spaces[6][5] << " | " << spaces[6][6] << " | " << spaces [6][7] << " | 7" << endl
    << "--------------------------------" << endl
    << "| " << spaces[5][0] << " | " << spaces[5][1] << " | " << spaces[5][2] << " | " << spaces[5][3] << " | " << spaces[5][4] << " | " << spaces[5][5] << " | " << spaces[5][6] << " | " << spaces [5][7] << " | 6" << endl
    << "--------------------------------" << endl
    << "| " << spaces[4][0] << " | " << spaces[4][1] << " | " << spaces[4][2] << " | " << spaces[4][3] << " | " << spaces[4][4] << " | " << spaces[4][5] << " | " << spaces[4][6] << " | " << spaces [4][7] << " | 5" << endl
    << "--------------------------------" << endl
    << "| " << spaces[3][0] << " | " << spaces[3][1] << " | " << spaces[3][2] << " | " << spaces[3][3] << " | " << spaces[3][4] << " | " << spaces[3][5] << " | " << spaces[3][6] << " | " << spaces [3][7] << " | 4" << endl
    << "--------------------------------" << endl
    << "| " << spaces[2][0] << " | " << spaces[2][1] << " | " << spaces[2][2] << " | " << spaces[2][3] << " | " << spaces[2][4] << " | " << spaces[2][5] << " | " << spaces[2][6] << " | " << spaces [2][7] << " | 3" << endl
    << "--------------------------------" << endl
    << "| " << spaces[1][0] << " | " << spaces[1][1] << " | " << spaces[1][2] << " | " << spaces[1][3] << " | " << spaces[1][4] << " | " << spaces[1][5] << " | " << spaces[1][6] << " | " << spaces [1][7] << " | 2" << endl
    << "--------------------------------" << endl
    << "| " << spaces[0][0] << " | " << spaces[0][1] << " | " << spaces[0][2] << " | " << spaces[0][3] << " | " << spaces[0][4] << " | " << spaces[0][5] << " | " << spaces[0][6] << " | " << spaces [0][7] << " | 1" << endl
    << "--------------------------------" << endl;
}

void moveCheck()
{
    if (spaces[rankInit][fileInitInt] == 'P')
    {
        if (rankInit == 1)
        {
            if (rankTarg == 3 && fileInitInt == fileTargInt && spaces[rankTarg][fileTargInt] == ' ')
            {
                move();
            }
            else if (rankTarg == 2 && fileInitInt == fileTargInt && spaces[rankTarg][fileTargInt] == ' ')
            {
                move();
            }
            else if (rankTarg == 2 && spaces[rankTarg][fileTargInt] != ' ' && fileTargInt == fileInitInt + 1 || fileTargInt == fileInitInt - 1)
            {
                move();
            }
            else
            {
                //invalid move, retake input
            }
        }
        else if (rankTarg == rankInit + 1 && fileInitInt == fileTargInt && spaces[rankTarg][fileTargInt] == ' ')
        {
            move();
        }
        else if (rankTarg == rankInit + 1 && spaces[rankTarg][fileTargInt] != ' ' && fileTargInt == fileInitInt + 1 || fileTargInt == fileInitInt - 1)
        {
            move();
        }
        else
        {
            //invalid move, retake input
        }
    }

    if (spaces[rankInit][fileInitInt] == 'N' || spaces[rankInit][fileInitInt] == 'n')
    {
        for (int i = -1; i < 2; i += 2)
        {
            if (spaces[rankTarg][fileTargInt] == spaces[rankInit + i][fileInitInt + 2] || spaces[rankTarg][fileTargInt] == spaces[rankInit + i][fileInitInt - 2])
            {
                move();
                break;
            }
            if (spaces[rankTarg][fileTargInt] == spaces[rankInit - 2][fileInitInt + i] || spaces[rankTarg][fileTargInt] == spaces[rankInit + 2][fileInitInt + i])
            {
                move();
                break;
            }
        }
    }
}

void move()
{
    spaces[rankTarg][fileTargInt] = spaces[rankInit][fileInitInt];
    spaces[rankInit][fileInitInt] = ' ';
}

void fileConvert(char file)
{
    switch (file)
    {
        case 'a':
            intForm = 0;
            break;
        case 'b':
            intForm = 1;
            break;
        case 'c':
            intForm = 2;
            break;
        case 'd':
            intForm = 3;
            break;
        case 'e':
            intForm = 4;
            break;
        case 'f':
            intForm = 5;
            break;
        case 'g':
            intForm = 6;
            break;
        case 'h':
            intForm = 7;
            break;
        default:
            //error, take a new input
            break;
    }
}

void setBoard()
{
    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            spaces[i][j] = ' ';
        }
    }
    //white pieces
    spaces[0][0] = 'R';
    spaces[0][1] = 'N';
    spaces[0][2] = 'B';
    spaces[0][3] = 'Q';
    spaces[0][4] = 'K';
    spaces[0][5] = 'B';
    spaces[0][6] = 'N';
    spaces[0][7] = 'R';
    
    //black pieces
    spaces[7][0] = 'r';
    spaces[7][1] = 'n';
    spaces[7][2] = 'b';
    spaces[7][3] = 'q';
    spaces[7][4] = 'k';
    spaces[7][5] = 'b';
    spaces[7][6] = 'n';
    spaces[7][7] = 'r';
    
    //pawns
    for (int i = 0; i < 8; i++)
    {
        spaces[1][i] = 'P';
        spaces[6][i] = 'p';
    }
}