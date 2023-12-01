#include <iostream>
using namespace std;

class myDynamicString
{
    public:
    myDynamicString(int lenght)
    {
        _length = lenght;
        _myString = new char[lenght];
        for(int i = 0; i < lenght;i++)
        {
            _myString[i] = '0';
        }
    }
    ~myDynamicString()
    {
        delete []_myString;
    }
    char charAt(int index)
    {
        if(_length == 0)
            return '0';
        if(index >= 0 && index < _length )
        {
            return _myString[index];
        }
        else{
            return '0';
        }
    }
    char operator[](int index)
    {
        return charAt(index);
    }
    void appendStr(char c)
    {
        int newLength = _length + 1;
        char* newStr = new char[newLength];
        for(int i = 0; i < _length;i++)
        {
            newStr[i] = _myString[i];
        }   
        newStr[newLength - 1] = c;
        delete []_myString;
        _myString = newStr;
        _length = newLength;
        
    }
    void concatenate(char* concatenatedStr,int concatenatedStrLength)
    {
        int newLength = _length + concatenatedStrLength;
        char* newStr = new char[newLength];
        for(int i = 0; i < newLength;i++)
        {
            if(i < _length)
                newStr[i] = _myString[i];
            else
                newStr[i] = concatenatedStr[i - _length];
        }
        delete []_myString;
        _length = newLength;
        _myString = newStr;
        
    }
    myDynamicString& operator=(myDynamicString& assignedStr)
    {
        if(this != &assignedStr)
        {
            delete[]_myString;
            _length = assignedStr._length;
            _myString= new char[_length];
            for(int i = 0; i < _length;i++)
            {
                _myString[i] = assignedStr.charAt(i);
            }
        }
        return *this;
    }
    private:
        char* _myString;
        int _length;
};

int main()
{
    myDynamicString myStr(5);
    myStr.appendStr('T');
    char concatStr[]= {'e','s','t'};
    myStr.concatenate(concatStr,3);
    for(int i = 0; i < 9;i++)
    {
        cout << myStr.charAt(i);
    }
    cout << endl;
    myDynamicString myStr2(5);
    myStr2 = myStr;
    for(int i = 0; i < 9;i++)
    {
        cout << myStr2[i];
    }
     cout << endl;
    return 0;
}