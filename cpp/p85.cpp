#include <cmath>
#include <iostream>

int main()
{
    struct Candidate
    {
        int m;
        int n;
        
        int RectCount() const { return m * (m + 1) * n * (n + 1) / 4; }
        
        bool operator>(const Candidate& rhs) const
        {
            return std::abs(2e6 - RectCount()) < std::abs(2e6 - rhs.RectCount());
        }
    };
    
    Candidate best = {1, 1};
    
    for (int m = 1; m != 2000; ++m)
    {
        int n = static_cast<int>(0.5 * (-1 + std::sqrt(1 + 32e6 / (m * (m + 1)))) + 0.5);
        Candidate curr = {m, n};
        if (curr > best)
            best = curr;
    }
    
    std::cout << best.m << ", " << best.n << ", " << best.RectCount() << std::endl;
    std::cout << "Area: " << best.m * best.n << std::endl;
    
    return 0;
}
