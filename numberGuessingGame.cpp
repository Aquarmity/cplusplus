#include <iostream> //input and output
#include <cstdlib> //for rng
#include <time.h> //time
using namespace std; //Needed for cout and cin


int main()
{
    
    int n = 0; //for my while loop
    int cont = 99; //for continuing
    int ans = rand() % 100 + 1; //for rng
    int guess; //what the player guesses
    bool on = true; //for play again and not
    int inefficient = 1; //to regenerate a number to guess
    int guessCount = 1;
    int guessLimit = 7;
    
    while (on == true) //makes sure play again works correctly
    {
        
        while (n == 0) //== means to check, = means to set to
        {
            if (inefficient == 1)
            {
            srand ((unsigned) time(NULL));
            ans = rand() % 100 + 1;
            
            cout << "I'm thinking of a number 1 - 100. What is it?\n";
            
            inefficient = 0;
            }
            
            cin >> guess;
            
            if (guess == ans)
            {
                cout << "Congratulations, you won in " << guessCount << " guesses!\n";
                n = 1;
            }
            
            if (guess > ans and guess < 101)
            {
                guessLimit--;
                cout << "Your guess is too high! You have " << guessLimit << " guesses left, guess again. " << endl;
                guessCount++;
            }
            
            if (guess < ans and guess > 0)
            {
                guessLimit--;
                cout << "Your guess is too low! You have " << guessLimit << " guesses left, guess again. " << endl;
                guessCount++;
            }
            
            if (guess == 69420)
            {
                cout << "nice. " << endl;
            }
            
            if (guess > 100 or guess < 1)
            {
                cout << "Invalid guess, try again. " << endl;
            }
            
            if (guessLimit == 0)
            {
                cout << "Sorry! Out of guesses.\n";
                n = 1;
            }
        }
        
        cout << "Would you like to continue? If yes, enter 1, if no, enter 0 --- ";
        cin >> cont; //get user input
        cout << endl;
        
        if (cont == 1)
        {
            cont = 1;
            cout << "Okay, let's do this again. \n";
            inefficient = 1;
            n = 0;
            guessCount = 1;
            guessLimit = 7;
        }
    
        if (cont == 0)
        {
            cont = 0;
            cout << "Thanks for playing!";
            on = false;
        }
    } //ends the while loop
    return 0;
}






