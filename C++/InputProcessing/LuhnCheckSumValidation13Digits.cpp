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
    cout << "Input ISBN number (13 digits) \n";
    int oddSum = 0;
    int position = 1;
    
    digit = cin.get();
    /*while(true)
    {
        cout << int (digit);
        digit = cin.get();
        cout << "end\n";
    }*/
    while(position < 14)//problem 1: reach the end of number
    {
        if(position % 2 == 0)//problem 3: know which number will be doubled
        {
            oddSum += doubleValue(digit - '0');//problem 4: double value using luhn-conver char to int
        }
        else
        {
            oddSum += digit - '0';
        }
        position++;
        cout << "oddSum: " << oddSum << "\n";
        digit = cin.get();//problem 2: read each number separately
    }
    int finalSum = oddSum;
    
    cout << "Sum: " << finalSum << "\n";
    if(finalSum % 10 == 0)
        cout << "Valid\n";
    else
        cout << "Invalid\n";
    return 0;
}