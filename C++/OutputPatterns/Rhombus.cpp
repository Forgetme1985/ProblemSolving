#include <iostream>

using std::cin;
using std::cout;
int main()
{
    for(int row = 0; row < 8;row++)
    {
        for(int numHash = 0; numHash < 8; numHash++)
        {
            if(row <=3)
            {
               if(numHash >= (4 - row - 1) && numHash <= 8 - (4 - row))
                    cout << "#";
                else
                    cout << " ";
            }
            else
            {
                if(numHash >= (row - 4) && numHash < 8 - (row - 4))
                    cout << "#";
                else
                    cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}