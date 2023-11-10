#include <iostream>

using std::cin;
using std::cout;
int main()
{
    for(int row = 0; row < 8;row++)
    {
        for(int numHash = 0; numHash < 14; numHash++)
        {
            if(row <=3)
            {
               if((numHash >= row &&  numHash <= row * 2) || 
               (numHash >= 13 - row * 2 && numHash <= 13 - row))
                    cout << "#";
                else
                    cout << " ";
            }
            else
            {
                int row2 = row -4;
                if((numHash >= 13/2 - row2 * 2 -(3 - row2) && numHash <= 13 / 2 - row2 * 2) ||
                (numHash >= 13/2 + row2 * 2 + 1 &&  numHash <= 13 - 3 + row2))
                    cout << "#";
                else
                    cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}