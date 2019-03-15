#include <cassert>
#include <cmath>
#include <iostream>
#include <list>

struct PolyFinder
{
    virtual int Transform(int n) const = 0;
    virtual int Invert(int n) const = 0;
    
    int GetMatch(int n) const
    {
        assert(Invert(Transform(13)) == 13);
        int i = Invert(n);
        ++i;
        int candidate = Transform(i);
        
        if (candidate > n)
            return candidate;
        
        ++i;
        candidate = Transform(i);
        assert(candidate > n);
        return candidate;
    }
};

struct TriFinder
:
    public PolyFinder
{
    virtual int Transform(int n) const { return n * (n + 1) / 2; }
    virtual int Invert(int n) const { return (-1 + std::sqrt(1 + 8 * n)) / 2; }
};

struct SqFinder
:
    public PolyFinder
{
    virtual int Transform(int n) const { return n * n; }
    virtual int Invert(int n) const { return std::sqrt(n); }
};

struct PentFinder
:
    public PolyFinder
{
    virtual int Transform(int n) const { return n * (3 * n - 1) / 2; }
    virtual int Invert(int n) const { return (1 + std::sqrt(1 + 24 * n)) / 6; }
};

struct HexFinder
:
    public PolyFinder
{
    virtual int Transform(int n) const { return n * (2 * n - 1); }
    virtual int Invert(int n) const { return (1 + std::sqrt(1 + 8 * n)) / 4; }
};

struct SeptFinder
:
    public PolyFinder
{
    virtual int Transform(int n) const { return n * (5 * n - 3) / 2; }
    virtual int Invert(int n) const { return (3 + std::sqrt(9 + 40 * n)) / 10; }
};

struct OctFinder
:
    public PolyFinder
{
    virtual int Transform(int n) const { return n * (3 * n - 2); }
    virtual int Invert(int n) const { return (2 + std::sqrt(4 + 12 * n)) / 6; }
};

void FindCycle(std::list<int> series, std::list<PolyFinder*> finders)
{
    if (!finders.empty())
    {
        int lower = (series.back() % 100) * 100;
        int upper = lower + 100;
        
        if (lower < 1000)
            return;
        
        for (std::list<PolyFinder*>::iterator it = finders.begin(); it != finders.end(); ++it)
        {
            int next = (**it).GetMatch(lower);
            while (next < upper)
            {
                std::list<int> newSeries = series;
                newSeries.push_back(next);
                
                std::list<PolyFinder*> newFinders;
                for (
                    std::list<PolyFinder*>::iterator jt = finders.begin();
                    jt != finders.end();
                    ++jt)
                {
                    if (jt != it)
                        newFinders.push_back(*jt);
                }
                
                FindCycle(newSeries, newFinders);
                
                next = (**it).GetMatch(next);
            }
        }
    }
    else
    {
        if (series.back() % 100 == series.front() / 100)
        {
            int sum = 0;
            for (std::list<int>::iterator it = series.begin(); it != series.end(); ++it)
            {
                sum += *it;
                std::cout << *it << ' ';
            }
            
            std::cout << ", sum: " << sum << std::endl;
        }
    }
}

int main()
{
    std::list<PolyFinder*> finders;
    
    finders.push_back(new SqFinder);
    finders.push_back(new PentFinder);
    finders.push_back(new HexFinder);
    finders.push_back(new SeptFinder);
    finders.push_back(new OctFinder);
    
    int sum = 0;
    for (std::size_t i = 0; sum < 10000; ++i)
    {
        sum += i;
        if (sum > 999)
        {
            std::list<int> series;
            series.push_back(sum);
            FindCycle(series, finders);
        }
    }
    
    for (std::list<PolyFinder*>::iterator it = finders.begin(); it != finders.end(); ++it)
        delete *it;
    
    return 0;
}
