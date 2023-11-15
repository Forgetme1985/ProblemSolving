#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	const int ARRAY_SIZE = 5;
	char cipher[ARRAY_SIZE] = {'a','b','c','d','e'};
	cout << "Plain text: \n";
	for(int i = 0; i < ARRAY_SIZE;i++)
	{
		cout << cipher[i] << " ";
	}
	cout << endl;
	cout << "Cipher text: \n";
	for(int i = 0; i < ARRAY_SIZE;i++)
	{
		cout << char(cipher[i] + ARRAY_SIZE) << " ";
	}
	cout << endl;
    return 0;
}
