#ifndef DIE_HPP
#define DIE_HPP

#include <cstdlib>

#include "IDie.hpp"

class Die
:
    public IDie
{
private:
    int mSides;

public:
    Die(int sides) : mSides(sides) { }
    
    virtual boost::optional<int> Roll() { return 1 + std::rand() % mSides; }
};

#endif // DIE_HPP
