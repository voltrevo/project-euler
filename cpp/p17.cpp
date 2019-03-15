#include <cassert>
#include <iostream>
using namespace std;

int NumToCharLen(int x)
{
    static const int DIG_LENS[10] =
    {
        0, // (zero)
        3, // one
        3, // two
        5, // three
        4, // four
        4, // five
        3, // six
        5, // seven
        5, // eight
        4  // nine
    };
    
    static const int BUNCH_LENS[10] =
    {
        0,
        0,
        6, // twenty
        6, // thirty
        5, // forty
        5, // fifty
        5, // sixty
        7, // seventy
        6, // eighty
        6, // ninety
    };
    
    static const int TEEN_LENS[10] =
    {
        3, // ten
        6, // eleven
        6, // twelve
        8, // thirteen
        8, // fourteen
        7, // fifteen
        7, // sixteen
        9, // seventeen
        8, // eighteen
        8, // nineteen
    };
    
    assert(1 <= x && x <= 1000);
    if (x == 1000)
        return 11;
    
    int sum = 0;
    
    int dig1 = x / 100;
    int dig2 = (x / 10) % 10;
    int dig3 = x % 10;
    
    if (dig1 != 0)
    {
        sum += DIG_LENS[dig1] + 7; // 7: hundred
        if (dig2 != 0 || dig3 != 0)
            sum += 3; // and
    }
    
    if (dig2 > 1)
        sum += BUNCH_LENS[dig2];
    
    if (dig2 == 1)
    {
        sum += TEEN_LENS[dig3];
    }
    else
    {
        sum += DIG_LENS[dig3];
    }
    
    return sum;
}

int main()
{
    assert(NumToCharLen(3) == 5);
    assert(NumToCharLen(123) == 24);
    assert(NumToCharLen(304) == 19);
    assert(NumToCharLen(342) == 23);
    assert(NumToCharLen(115) == 20);
    assert(NumToCharLen(411) == 20);
    assert(NumToCharLen(1000) == 11);
    
    int sum = 0;
    for (int i = 1; i != 1001; ++i)
        sum += NumToCharLen(i);
    
    cout << sum << endl;
    
    return 0;
}
