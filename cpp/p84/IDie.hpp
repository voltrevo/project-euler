#ifndef IDIE_HPP
#define IDIE_HPP

#include "boost/optional.hpp"

class IDie
{
public:
    virtual boost::optional<int> Roll() = 0;
};

#endif // IDIE_HPP
