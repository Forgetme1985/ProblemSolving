#include <iostream>


using namespace std;
string convertDecToBi(int number,string s)
{
	if(number / 2 == 0)
	{
		return  s + to_string((number % 2));
	}
	else{
		 s += to_string((number % 2));
		return convertDecToBi(number / 2,s);
	}
}

string revertString(string s)
{
	string revertString = "";
	for(int i = s.length() - 1; i >= 0;i--)
	{
		revertString += s[i];
	}
	return revertString;
}
int main()
{
    int number;
    cout << "Input a decimal number \n";
    cin >> number;
    string s = "";
    cout << revertString(convertDecToBi(number,s));
    return 0;
}
