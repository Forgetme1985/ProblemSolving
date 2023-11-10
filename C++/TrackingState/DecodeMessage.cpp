#include <iostream>

using std::cin;
using std::cout;



int main()
{
    char outputCharacter;
    enum mode{PUN,LOWER,UPPER};
    mode m = UPPER;
    char digiChar;
    do{
        digiChar = cin.get();
        int number = (digiChar - '0');
        digiChar = cin.get();
        while(digiChar != 10 && digiChar != ',')
        {
            number = number * 10 + (digiChar - '0');
            digiChar = cin.get();
        }
        switch (m)
        {
            case PUN:
               number = number % 9;
               switch (number)
               {
                case 1: outputCharacter = '!'; break;
                case 2: outputCharacter = '?'; break;
                case 3: outputCharacter = ','; break;
                case 4: outputCharacter = '.'; break;
                case 5: outputCharacter = ' '; break;
                case 6: outputCharacter = ';'; break;
                case 7: outputCharacter = '"'; break;
                case 8: outputCharacter = '\''; break;
               }
               if(number == 0)
                {
                    m = UPPER;
                    continue;
                }
            break;
            case UPPER:
                number = number % 27;
                outputCharacter = number + 'A' - 1;
                if(number == 0)
                {
                    m = LOWER;
                    continue;
                }
            break;
            case LOWER:
                number = number % 27;
                outputCharacter = number + 'a' - 1;
                if(number == 0)
                {
                    m = PUN;
                    continue;
                }
            break;
            default:
                break;
        }
        cout << outputCharacter;
    }while(digiChar != 10);
    cout << "\n";
    return 0;
}