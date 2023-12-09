#include <iostream>
using namespace std;

bool isOddNumberOfBit1(int arr[],int size,int count)
{
    if(size == 0)
        return (count % 2 == 0? false:true);
    if(arr[size - 1] > 0)
        count++;
    return isOddNumberOfBit1(arr,size - 1,count);
}


int main()
{
    int arr[] = {1,1,1,0,1};
    cout << isOddNumberOfBit1(arr,5,0) << endl;
    return 0;
}