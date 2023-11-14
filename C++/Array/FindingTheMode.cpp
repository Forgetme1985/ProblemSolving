#include <iostream>
#include <cmath>

using namespace std;

int compareFunc(const void* a, const void* b)
{
	int * intA = (int*)(a);
	int * intB = (int*)(b);
	return *intA - *intB;
}

int main()
{
	const int ARRAY_SIZE = 12;
	int surveyData[ARRAY_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};

	//step 1 sort the array
	qsort(surveyData,ARRAY_SIZE,sizeof(int),compareFunc);

	//step 2 finding the mode
	int mostFreq;
	int highestFreq;
	int currentFreq;

	for(int i = 0; i < ARRAY_SIZE;i++)
	{
		currentFreq++;
		if(i == ARRAY_SIZE - 1 || surveyData[i] != surveyData[i + 1])
		{
			if(currentFreq > highestFreq)
			{
				highestFreq = currentFreq;
				mostFreq = surveyData[i];
			}
			currentFreq = 0;
		}
	}
	cout << "the mode is: " << mostFreq;
    return 0;
}