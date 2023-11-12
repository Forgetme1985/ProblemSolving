#include <iostream>

using std::cin;
using std::cout;
int main()
{
    for(int row = 0; row <= 6;row++)
    {
        for(int numHash = 0; numHash <= 6; numHash++)
        {
            //if(row <= 3)
            {
                if(row == numHash || row == 6 - numHash)
                    cout << "#";
                else
                    cout << " ";
            }

        }
        cout << "\n";
    }
    return 0;
}