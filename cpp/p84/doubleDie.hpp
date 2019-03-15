#include "die.hpp"

class DoubleDie
:
    public IDie
{
private:
    Die mDie1;
    Die mDie2;

public:
    DoubleDie(int sides) : mDie1(sides), mDie2(sides) { }
    
    virtual boost::optional<int> Roll()
    {
        int count = 0;
        int sum = 0;
        
        while (count != 3)
        {
            int roll1 = *mDie1.Roll();
            int roll2 = *mDie2.Roll();
            
            sum += roll1 + roll2;
            
            if (roll1 != roll2)
                return sum;
            
            ++count;
        }
        
        return boost::none;
    }
};
