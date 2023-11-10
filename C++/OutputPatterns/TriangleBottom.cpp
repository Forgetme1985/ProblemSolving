#include <iostream>

using std::cin;
using std::cout;
int main()
{
    for(int row = 0; row < 5;row++)
    {
        for(int numHash = 0; numHash < 8; numHash++)
        {
            if(numHash >= row && numHash < 8 - row)
                cout << "#";
            else
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}