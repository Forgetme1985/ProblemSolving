#include <iostream>

using std::cin;
using std::cout;

int doubleValue(int value)
{
    value = value * 2;
    if(value >= 10) return (1 + value % 10);
    return value;
}

int main()
{
    char digit;
    cout << "Input number \n";
    int evenSum = 0;
    int oddSum = 0;
    int position = 1;
    
    digit = cin.get();
    while(digit != 10)//problem 1: reach the end of number
    {
        if(position % 2 == 0)//problem 3: know which number will be doubled
        {
            oddSum += doubleValue(digit - '0');//problem 4: double value using luhn-conver char to int
            evenSum += digit - '0';
        }
        else
        {
            evenSum += doubleValue(digit - '0');
            oddSum += digit - '0';
        }
        position++;
        cout << "oddSum: " << oddSum << "\n";
        cout << "evenSum: " << evenSum << "\n";
        digit = cin.get();//problem 2: read each number separately
    }
    int finalSum = 0;
    if((position -1) % 2 == 0)
    {
        finalSum = evenSum;
    }
    else
        finalSum = oddSum;
    cout << "Sum: " << finalSum << "\n";
    if(finalSum % 10 == 0)
        cout << "Valid\n";
    else
        cout << "Invalid\n";
    return 0;
}
