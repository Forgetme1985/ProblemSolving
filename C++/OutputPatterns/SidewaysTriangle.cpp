#include <iostream>

using std::cin;
using std::cout;
int main()
{
    for(int row = 0; row < 7;row++)
    {
        if(row < 4)
        {
            for(int numHash = 0; numHash <= row; numHash++)
            {
                cout << "#";
            }
        }
        else
        {
            for(int numHash = 0; numHash < 7 - row; numHash++)
            {
                cout << "#";
            }
        }
        
        cout << "\n";
    }
    return 0;
}