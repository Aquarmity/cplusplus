#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void manHanging();
char body[6] = {' ', ' ', ' ', ' ', ' ', ' '};
bool on = true;
string guessedLetters;

int main()
{
    string secretWord;
    char guess;
    int count = 0;
    int lastCount;
    int bodyPart = 0;
    
    cout << "Word to be guessed: ";
    getline(cin, secretWord);
    
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Input was invalid, input a string." << endl;
        cin >> secretWord;
    }
    transform(secretWord.begin(), secretWord.end(), secretWord.begin(), ::toupper);
    
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    
    int length = secretWord.length();
    char underscores[length];
    char sep[length];
    
    for (int i = 0; i < length; i++)
    {
        underscores[i] = '_';
        sep[i] = secretWord[i];
        
        if (sep[i] == ' ')
        {
           underscores[i] = ' ';
           count++;
        }
    }
    
    while (on == true)
    {
        lastCount = count;
        manHanging();
        for (int i = 0; i < length; i++)
        {
            cout << underscores[i] << ' ';
        }
        cout << endl << endl;
        if (bodyPart == 6)
        {
            cout << "Guesser loses! The word was " << secretWord;
            return 0;
        }
        if (count == length)
        {
            cout << "Word guessed! The word was " << secretWord;
            return 0;
        }
        
        
        cin >> guess;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Input was invalid, input a character." << endl;
            cin >> guess;
        }
        
        guess = toupper(guess);
        
        for (int i = 0; i < length; i++)
        {
            if (guess == sep[i])
            {
                underscores[i] = sep[i];
                sep[i] = ' ';
                count++;
            }
        }
        if (lastCount == count)
        {
            switch (bodyPart)
            {
                case 0:
                    body[0] = 'O';
                    break;
                case 1:
                    body[1] = '|';
                    break;
                case 2:
                    body[2] = '/';
                    break;
                case 3:
                    body[3] = '\\';
                    break;
                case 4:
                    body[4] = '-';
                    break;
                case 5:
                    body[5] = '-';
                    break;
            }
            guessedLetters.push_back(guess);
            bodyPart++;
        }
    }
}

void manHanging()
{
    cout
    << "         ----------" << "  Wrong Guesses: "<<  endl
    << "         |        |" << endl
    << "         " << body[0] << "        |" << endl
    << "       " << body[4] << body[4] << body[1] << body[5] << body[5] << "      |  " << guessedLetters << endl
    << "         " << body[1] << "        |" << endl
    << "        " << body[2] << " " << body[3] << "       |" << endl
    << "                  |   " << endl
    << "               -------" << endl;
}





