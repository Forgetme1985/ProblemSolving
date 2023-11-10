#include <iostream>

using std::cin;
using std::cout;
int main()
{
    for(int row = 0; row < 5;row++)
    {
        for(int numHash = 0; numHash < 5 - row; numHash++)
        {
            cout << "#";
        }
        cout << "\n";
    }
    return 0;
}