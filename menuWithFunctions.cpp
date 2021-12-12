#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <tgmath.h>
#include <algorithm>
using namespace std;

const vector<char> vowels{'a', 'e', 'i', 'o', 'u', 'I'};
const vector<char> consonants{'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};

void showMenu();
void uppercase();
void lowercase();
void alternatingCaps();
void reverse();
void pigLatin();

int main()
{
    int menuChoice = 99;
    while (menuChoice != 6)
    {
        showMenu();
        cin >> menuChoice;
        
        if (cin.fail()) //error checks - won't take input besides numbers
        {
            cin.clear();
            cin.ignore(256, '\n');
        }
        
        switch (menuChoice)
        {
            case 1:
                uppercase();
                break;
            case 2:
                lowercase();
                break;
            case 3:
                alternatingCaps();
                break;
            case 4:
                reverse();
                break;
            case 5:
                pigLatin();
                break;
            case 6:
                cout << "Farewell!";
                break;
            default:
                cout << "Invalid input, please enter a number 1 - 6\n";
                break;
        }
    }
    return 0;
}

void showMenu ()
{
    cout << "*****************************************\n";
    cout << "*****************************************\n";
    cout << "**       How would you like your       **\n";
    cout << "**         sentence modified?          **\n";
    cout << "**                                     **\n";
    cout << "** 1) UPPERCASE          (HELLO WORLD) **\n";
    cout << "**                                     **\n";
    cout << "** 2) lowercase          (hello world) **\n";
    cout << "**                                     **\n";
    cout << "** 3) AlTeRnAtInG CaPs   (HeLlO wOrLd) **\n";
    cout << "**                                     **\n";
    cout << "** 4) Reverse            (dlroW olleH) **\n";
    cout << "**                                     **\n";
    cout << "** 5) Pig Latin      (ellohay orldway) **\n";
    cout << "**                                     **\n";
    cout << "** 6) Quit        (no please don't go) **\n";
    cout << "**                                     **\n";
    cout << "*****************************************\n";
    cout << "*****************************************\n";
}

void uppercase() //code I made for a friend's challenge
{
    string upper;
    cout << "Input a phrase, and it will be outputted in uppercase." << endl;
    
    cin.ignore(); //program doesn't stop for user input unless this is here
    getline (cin, upper);
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    cout << upper << endl << endl;
}

void lowercase()
{
    string lower;
    cout << "Input a phrase, and it will be outputted in lowercase." << endl;
    
    cin.ignore();
    getline (cin, lower);
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    cout << lower << endl << endl;
}

void alternatingCaps()
{
    string alt;
    int i = 0;
    cout << "Input a phrase, and it will be outputted in alternating caps." << endl;
    
    cin.ignore();
    getline (cin, alt);
    char sep[alt.length()]; //sep = "separated". String is separated into an array of chars
    
    for (int i = 0; i <= alt.length(); i++)
    {
        sep[i] = alt[i];
    }
    while (i <= alt.length())
    {
        alt[i] = toupper(alt[i]);
        cout << alt[i];
        i++;
        alt[i] = tolower(alt[i]);
        cout << alt[i];
        i++;
    }
    cout << endl << endl;
}

void reverse()
{
    string esrever;
    cout << "Input a phrase, and it will be outputted in reverse." << endl;
    
    cin.ignore();
    getline(cin, esrever);
    char sep[esrever.length()];
    for (int i = 0; i <= esrever.length(); i++)
    {
        sep[i] = esrever[i];
    }
    for (int i = esrever.length(); i >= 0; i--) //outputs the array from last to first
    {
        cout << sep[i];
    }
    cout << endl << endl;
}

void pigLatin() //code I made for another challenge
{
    int s = 0;
    int x;
    string notPig;
    
    cout << "Input a phrase (no numbers, uppercase, or special characters) and it will be translated into Pig Latin" << endl;
    cin.ignore();
    getline(cin, notPig);
    notPig = notPig + ' '; //space added for staying in array range

    int length = notPig.length();
    char sep[length];
    vector<int> spacePos{-1}; //need to add a "fake space" in the front of the string for detecting the first word

    for (int i = 0; i < length; i++)
    {
        sep[i] = notPig[i]; //converts the string to char array
        if (sep[i] == ' ')
        {
           spacePos.push_back(i); //stores position in array of the spaces
        }
    }

    for (int i = 0; i < length; i++)
    {
        x = 1;
        if (find(spacePos.begin(), spacePos.end(), i - 1) != spacePos.end()) //checks if start of new word
        {
            if (find(vowels.begin(), vowels.end(), sep[i]) != vowels.end())
            {
                for (int k = i; k < spacePos[s + 1]; k++) //just outputs the word
                {
                    cout << sep[k];
                }
                cout << "ay ";
                s++;
            }
            else if (find(consonants.begin(), consonants.end(), sep[i]) != consonants.end())
                {
                    for (int k = i + 1; k < spacePos[s + 1] && find(consonants.begin(), consonants.end(), sep[k]) != consonants.end(); k++) //finds consonant clusters at the beginning of words
                    {
                        if (find(consonants.begin(), consonants.end(), sep[k]) != consonants.end())
                        {
                            x++;
                        }
                    }
                    for (int m = i + x; m < spacePos[s + 1]; m++) //outputs the words after the first consonant(s)
                    {
                        cout << sep[m];
                    }
                    for (int n = i; n < i + x; n++) //outputs the first consonant(s)
                    {
                        cout << sep[n];
                    }
                    cout << "ay ";
                    s++;
                }
        }
    }
    cout << endl << endl;
}
