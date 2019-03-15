#include <iostream>
using namespace std;

int main()
{
    int t = 1;
    int p = 1;
    int h = 1;
    
    int dt = 2;
    int dp = 4;
    int dh = 5;
    
    for (int i = 0; i != 2; ++i)
    {
        do
        {
            if (t < p)
            {
                if (t < h)
                {
                    t += dt;
                    dt += 1;
                }
                else
                {
                    h += dh;
                    dh += 4;
                }
            }
            else
            {
                if (p < h)
                {
                    p += dp;
                    dp += 3;
                }
                else
                {
                    h += dh;
                    dh += 4;
                }
            }
        }
        while (t != p || t != h);
    }
    
    cout << t << endl;
    
    return 0;
}
