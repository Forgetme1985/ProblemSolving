#include <iostream>
using namespace std;


int arraySumRecursive(int values[], int size)
{
    if(size == 0) return 0;
    int lastNumber = values[size - 1];
    int sum = arraySumRecursive(values,size - 1);
    return lastNumber + sum;
}
int zeroCount(int values[],int size)
{
    if(size == 0) return 0;
    int count = zeroCount(values,size - 1);
    if(values[size - 1] == 0)count++;
    return count;
}
int main()
{
    int arr[] = {1,3,3,5,6};
    cout << arraySumRecursive(arr,5) << endl;
    int arrZero[]= {0,1,0,4,0};
    cout << zeroCount(arrZero,5) << endl;

    return 0;
}