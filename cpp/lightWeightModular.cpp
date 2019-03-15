#include <cassert>
#include "lightWeightModular.hpp"

LightWeightModular::LightWeightModular(uint val, uint upperVal)
:
    mVal(val),
    mUpperVal(upperVal)
{
    assert(val < upperVal);
}

uint LightWeightModular::Get() const
{
    return mVal;
}

uint LightWeightModular::operator++()
{
    mVal = (mVal + 1) % mUpperVal;
    return mVal;
}

uint LightWeightModular::operator++(int)
{
    uint oldVal = mVal;
    mVal = (mVal + 1) % mUpperVal;
    return oldVal;
}
