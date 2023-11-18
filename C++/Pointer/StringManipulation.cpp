#include <iostream>

using namespace std;


typedef char* arrayStr;
char characterAt( arrayStr str,int position)
{
    return str[position];
}
int lenght(arrayStr str)
{
    int count = 0;
     while(str[count] != 0)
    {
        count++;
    }
    return count;
}
void append(arrayStr& str,char c)
{
    int oldLen = lenght(str);
   
    arrayStr newStr = new char[oldLen + 2];
    for(int i = 0; i < oldLen;i++)
    {
        newStr[i] = str[i];
    }
    newStr[oldLen] = c;
    newStr[oldLen + 1] = 0;
    delete []str;
    str = newStr;
}
void concatenate(arrayStr& str1,arrayStr& str2)
{
    int oldLen1 = lenght(str1);
    int oldLen2 = lenght(str2);
    int newLen = oldLen1 + oldLen2;
    arrayStr newStr = new char[newLen + 1];
    for(int i = 0; i < oldLen1;i++)
    {
        newStr[i] = str1[i];
    }
    for(int i = 0; i < oldLen2;i++)
    {
        newStr[oldLen1 + i] = str2[i];
    }
    newStr[newLen + 1] = 0;
    delete[] str1;
    str1 = newStr;
}
int main()
{
    arrayStr a = new char[5];
    a[0] = 't';a[1] = 'e';a[2] = 's';a[3] = 't';a[4] = 0;
    arrayStr b = new char[4];
    b[0] = 'b';b[1] = 'e';b[2] = 'd';b[3] = 0;
    concatenate(a,b);
    cout << a << "\n" << b << "\n";
    cout << (void *) a << "\n" << (void *)b << "\n";

    return 0;
}