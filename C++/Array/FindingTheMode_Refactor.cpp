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
	//qsort(surveyData,ARRAY_SIZE,sizeof(int),compareFunc);

	// finding the mode
	const int MAX_RESPONSE = 10;
	int histogram[MAX_RESPONSE];
	for(int i = 0; i < MAX_RESPONSE;i++)
	{
		histogram[i] = 0;
	}
	for(int i = 0; i < ARRAY_SIZE;i++)
	{
		histogram[surveyData[i] - 1]++;
	}
	int mostFreq = 0;
	for(int i = 0; i < MAX_RESPONSE;i++)
	{
		if(histogram[i] > histogram[mostFreq])mostFreq = i;
	}
	mostFreq++;
	cout << "The most Freq: " << mostFreq;
    return 0;
}
