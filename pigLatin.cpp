#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const vector<char> vowels{'a', 'e', 'i', 'o', 'u', 'I'};
const vector<char> consonants{'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};

int main()
{
    int s = 0;
    int x;
    string notPig;
    
    cout << "Input a phrase, only lowercase and no numbers or special characters." << endl;
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
}




