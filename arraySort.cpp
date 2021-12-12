#include <iostream>
#include <string>
#include <array>
using namespace std;

int main()
{
    int numbers[] = {86, 72, 15, 25, 100, 88, 82, 86};
    int outputLow = numbers[0];
    int outputHigh = numbers[0];
    int sort = numbers[0];
    int buffer;
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] > outputHigh)
        {
            outputHigh = numbers[i];
        }
        if (numbers[i] < outputLow)
        {
            outputLow = numbers[i];
        }
    }
    
    for (int i = 0; i < size; i++)
    {
        for (int i = 1; i < size; i++)
        {
            if (numbers[i] < numbers [i - 1])
            {
                buffer = numbers[i];
                numbers[i] = numbers[i - 1];
                numbers [i - 1] = buffer;
            }
        }
    }
    cout << "The lowest value in the array is " << outputLow << endl;
    cout << "The highest value in the array is " << outputHigh << endl;
    cout << "The numbers sorted lowest to highest: ";
    for (int i = 0; i <= 7; i++)
    {
        cout << numbers[i] << " ";
    }
}
