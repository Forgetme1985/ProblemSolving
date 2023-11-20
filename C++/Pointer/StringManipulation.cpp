#include <iostream>

using namespace std;


typedef char* arrayStr;
char characterAt( arrayStr str,int position)
{
    return str[position];
}
int length(arrayStr str)
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
    int oldLen = length(str);
   
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
    int oldLen1 = length(str1);
    int oldLen2 = length(str2);
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
    delete[] str2;
    str1 = newStr;
}
void removeString(arrayStr& str,int startPos, int len)
{

    int oldLen = length(str);
    int newLen = oldLen - len;
    arrayStr newStr = new char[newLen + 1];
    int offSet = startPos + len;
    for(int i = 0; i < oldLen;i++)
    {
        if(i < startPos)
        {
            cout << "i: " << i << endl;
            newStr[i] = str[i];
        }
        else if(i >= offSet)
        {
            cout << "i: " << i << endl;
            newStr[i - len] = str[i];
        }
    }
    newStr[newLen + 1] = 0;
    delete[] str;
    str = newStr;
}
void subString(arrayStr& str,int startPos, int len)
{

    int oldLen = length(str);
    int newLen = oldLen - len;
    arrayStr newStr = new char[newLen + 1];
    int offSet = startPos + len;
    for(int i = 0; i < oldLen;i++)
    {
        if(i >= startPos)
        {
            cout << "i: " << i << endl;
            newStr[i] = str[i];
        }
        else if(i < offSet)
        {
            cout << "i: " << i << endl;
            newStr[i - len] = str[i];
        }
    }
    newStr[newLen + 1] = 0;
    delete[] str;
    str = newStr;
}
void replaceString(arrayStr& source,arrayStr target, arrayStr replaceText)
{
    int targetLen = length(target);
    int sourceLen = length(source);
    int startPos = -1;
    int endPos  = -1;
    for(int i = 0; i < sourceLen;i++)
    {
        for(int j = 0; j < targetLen;j++)
        {
            if(source[i + j] == target[j])
            {
                if(startPos == -1)
                {
                    startPos = endPos = (i + j);
                }
                else{
                    endPos++;
                }
            }
        }
        if((endPos - startPos + 1) == targetLen)
        {
            break;
        }
        else
        {
            startPos = endPos = -1;
        }
    }
   
    if((endPos - startPos + 1) == targetLen)
    {
        int replaceLen = length(replaceText);
        int newLen = replaceLen + sourceLen;
        arrayStr newStr = new char[newLen + 1];
        for(int i = 0; i < startPos;i++)
        {
            newStr[i] = source[i];
        }
        for(int i = startPos; i < startPos + replaceLen;i++)
        {
            newStr[i] = replaceText[ i - startPos];
        }
        for(int i = endPos + 1; i < sourceLen;i++)
        {
            newStr[i] = source[i];
        }
        
        newStr[newLen + 1] = 0;
        delete[] source;
        source = newStr;
    }
}
int main()
{
    arrayStr a = new char[5];
    a[0] = 't';a[1] = 'e';a[2] = 's';a[3] = 't';a[4] = 0;
    arrayStr b = new char[4];
    b[0] = 'b';b[1] = 'e';b[2] = 'd';b[3] = 0;
    arrayStr d = new char[5];
     d[0] = 't';d[1] = 'e';d[2] = 's';d[3] = 't';d[4] = 0;
    arrayStr c = new char[5];
     c[0] = 'r';c[1] = 'o';c[2] = 'o';c[3] = 'm';c[4] = 0;
    concatenate(a,b);
    cout << a << "\n" << b << "\n";
    replaceString(a,d,c);
    cout << a << "\n";
    return 0;
}