#include <iostream>
#include <cmath>

using namespace std;

int compareFunc(const void* a, const void* b)
{
	int * intA = (int*)(a);
	int * intB = (int*)(b);
	return *intA - *intB;
}

bool isArraySort(int array[],int numElements)
{
	int highestNumber = array[0];
	for(int i = 0; i < numElements; i++)
	{
		if(highestNumber <= array[i])
		{
			highestNumber = array[i];
		}
		else
		{
			return false;
		}
	}
	return true;
}


int main()
{
	const int ARRAY_SIZE = 12;
	int array[ARRAY_SIZE] = {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434};
	
	for(int i = 0; i < ARRAY_SIZE;i++)
	{
		cout << array[i] << " ";
	}
	cout << "\nIs the array sorted? " << isArraySort(array,ARRAY_SIZE) << endl;
	
	//sort array
	qsort(array,ARRAY_SIZE,sizeof(int),compareFunc);
	for(int i = 0; i < ARRAY_SIZE;i++)
	{
		cout << array[i] << " ";
	}
	cout << "\nIs the array sorted? " << isArraySort(array,ARRAY_SIZE) << endl;


    return 0;
}
