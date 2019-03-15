#include <cassert>
#include <iostream>
using namespace std;

#include "primeFeed.hpp"

const uint PrimeFeed::M_BLOCK_SIZE = 1024 * 1024; // Megabyte blocks

PrimeFeed::PrimeFeed()
{
    AddBlock();
    mMemBlocks[0][0] = 0x3F; // 0011 1111, ie 0 and 1 not prime
    
    // 2 is hard coded
    mPrimes.push_back(2u);
    CrossOffInLastBlock(2u);
    mCurrPrime = mPrimes.begin();
}

void PrimeFeed::AddBlock()
{
    unsigned char* newBlock = new unsigned char[M_BLOCK_SIZE];
    for (uint i = 0; i != M_BLOCK_SIZE; ++i)
        newBlock[i] = 0xFF; // Turn all bits on
    
    mMemBlocks.push_back(newBlock);
    
    for
    (
        list<uint>::iterator p = mPrimes.begin();
        p != mPrimes.end() && *p * *p < 8 * M_BLOCK_SIZE * mMemBlocks.size();
        ++p
    )
    {
        CrossOffInLastBlock(*p);
    }
}

bool PrimeFeed::CheckPrime(uint x)
{
    while (mPrimes.back() * mPrimes.back() < x)
    {
        mPrimes.push_back(FindNextPrime());
        CrossOffInLastBlock(mPrimes.back()); // FIXME: O_O this probably works until BIG numbers
    }
    
    return (mMemBlocks[x / (8 * M_BLOCK_SIZE)][(x % (8 * M_BLOCK_SIZE)) / 8] >> (7 - (x % 8))) % 2 == 1;
}

void PrimeFeed::CrossOffInLastBlock(uint p)
{
    // FIXME: This seems sub-optimal
    
    uint firstAbsPos = 8 * M_BLOCK_SIZE * (mMemBlocks.size() - 1);
    uint relPos;
    if (firstAbsPos != 0)
        relPos = ((firstAbsPos - 1) / p + 1) * p - firstAbsPos;
    else
        relPos = p;
    
    if (firstAbsPos + relPos == p)
        relPos += p;
    
    while (relPos < 8 * M_BLOCK_SIZE)
    {
        mMemBlocks.back()[relPos / 8] &= ~('\1' << (7 - relPos % 8));
        relPos += p;
    }
}

uint PrimeFeed::FindNextPrime()
{
    uint primeCandidate = mPrimes.back() + 1;
    
    uint blockIndex = primeCandidate / (8 * M_BLOCK_SIZE);
    uint blockStartAbsPos = blockIndex * (8 * M_BLOCK_SIZE);
    uint relPos = primeCandidate - blockStartAbsPos;
    
    if (blockIndex >= mMemBlocks.size())
    {
        assert(blockIndex == mMemBlocks.size());
        AddBlock();
    }
    
    while (true)
    {
        while (relPos < 8 * M_BLOCK_SIZE)
        {
            // TODO: Use a more efficient way to find the first "on" bit in a byte
            if ((mMemBlocks[blockIndex][relPos / 8] & (1 << (7 - relPos % 8))) != 0)
                break;
            
            ++relPos;
        }
        
        if (relPos < 8 * M_BLOCK_SIZE)
            break;
        
        ++blockIndex;
        blockStartAbsPos += 8 * M_BLOCK_SIZE;
        if (blockIndex == mMemBlocks.size())
            AddBlock();
        
        relPos -= 8 * M_BLOCK_SIZE;
    }
    
    return blockStartAbsPos + relPos;
}

uint PrimeFeed::Next()
{
    // FIXME: need to always know one more than the user wants??
    if (*mCurrPrime == mPrimes.back())
    {
        mPrimes.push_back(FindNextPrime());
        CrossOffInLastBlock(mPrimes.back());
    }
    
    return *mCurrPrime++;
}

void PrimeFeed::Restart()
{
    mCurrPrime = mPrimes.begin();
}
