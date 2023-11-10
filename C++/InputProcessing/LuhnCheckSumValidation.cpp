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
    /*while(true)
    {
        digit = cin.get();
        cout << int(digit) << " ";
    }*/
    digit = cin.get();
    while(digit != 10)
    {
        if(position % 2 == 0)
        {
            oddSum += doubleValue(digit - '0');
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
        digit = cin.get();
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
    //1: know number to double
    //int sum = digit;
    
    //cout << "Sum: " << sum;
    //2: treating double number as individual numbers
    //3: reach the end
    //4: reading each number separately 

    return 0;
}
