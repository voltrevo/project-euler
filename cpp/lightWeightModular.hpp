#ifndef LIGHT_WEIGHT_MODULAR_HPP
#define LIGHT_WEIGHT_MODULAR_HPP

typedef unsigned int uint;

class LightWeightModular
{
    private:
        uint mVal;
        const uint mUpperVal;
    
    public:
        LightWeightModular(uint val, uint upperVal);
        
        uint Get() const;
        uint operator++();
        uint operator++(int);
};

#endif // LIGHT_WEIGHT_MODULAR_HPP
