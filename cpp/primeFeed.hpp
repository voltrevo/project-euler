#ifndef PRIME_FEED_HPP
#define PRIME_FEED_HPP

#include <deque>
#include <list>
using namespace std;

typedef unsigned int uint;

class PrimeFeed
{
private:
    deque<unsigned char*> mMemBlocks;
    list<uint> mPrimes;
    list<uint>::iterator mCurrPrime;
    
    static const uint M_BLOCK_SIZE;
    
    void AddBlock();
    void CrossOffInLastBlock(uint p);
    uint FindNextPrime();

public:
    PrimeFeed();
    
    bool CheckPrime(uint x);
    uint Next();
    void Restart();
};

#endif // PRIME_FEED_HPP
