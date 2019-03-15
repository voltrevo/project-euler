#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    
    for (int p200 = 0; 200 * p200 <= 200; ++p200)
    {
        int s200 = 200 * p200;
        for (int p100 = 0; s200 + 100 * p100 <= 200; ++p100)
        {
            int s100 = s200 + 100 * p100;
            for (int p50 = 0; s100 + 50 * p50 <= 200; ++p50)
            {
                int s50 = s100 + 50 * p50;
                for (int p20 = 0; s50 + 20 * p20 <= 200; ++p20)
                {
                    int s20 = s50 + 20 * p20;
                    for (int p10 = 0; s20 + 10 * p10 <= 200; ++p10)
                    {
                        int s10 = s20 + 10 * p10;
                        for (int p5 = 0; s10 + 5 * p5 <= 200; ++p5)
                        {
                            int s5 = s10 + 5 * p5;
                            for (int p2 = 0; s5 + 2 * p2 <= 200; ++p2)
                            {
                                int s2 = s5 + 2 * p2;
                                for (int p1 = 0; s2 + 1 * p1 <= 200; ++p1)
                                {
                                    if (s2 + p1 == 200)
                                        ++count;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}
