#include <iostream>
using namespace std;

int countingOccurences(int arr[],int size,int number)
{
    if(size == 0)
        return 0;
    int count = countingOccurences(arr,size - 1,number);
    if(arr[size - 1] == number)count++;
    return count;
}


int main()
{
    int arr[] = {1,2,1,2,1};
    cout << countingOccurences(arr,5,2) << endl;
    return 0;
}