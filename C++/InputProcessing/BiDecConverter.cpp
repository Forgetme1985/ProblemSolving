#include <iostream>
#include <cmath>

using namespace std;


string revertString(string s)
{
	string revertString = "";
	for(int i = s.length() - 1; i >= 0;i--)
	{
		revertString += s[i];
	}
	return revertString;
}
int convertBiToDec(int number)
{
	int sum = 0;
	string revertStr = revertString(to_string(number));
	for(int i = 0; i < revertStr.length();i ++)
	{
		string s = "";
		s +=revertStr[i];
		if(s == "1")
		{
			sum += pow(2,i);
		}
	}
	return sum;
}
int main()
{
    int number;
    cout << "Input a binary number \n";
    cin >> number;

   cout << convertBiToDec(number);

    return 0;
}
