#ifndef MONOPOLY_SIMULATOR_HPP
#define MONOPOLY_SIMULATOR_HPP

#include <memory>

#include "chanceDeck.hpp"
#include "communityChest.hpp"
#include "IDie.hpp"

class MonopolySimulator
{
private:
    std::unique_ptr<IDie> mDie;
    int mPosition;
    ChanceDeck mChanceDeck;
    CommunityChest mCommunityChest;

public:
    MonopolySimulator(std::unique_ptr<IDie>&& die)
    :
        mDie(std::move(die)),
        mPosition(0),
        mChanceDeck(MakeChanceDeck()),
        mCommunityChest(MakeCommunityChest())
    {
    }
    
    int GetPosition() { return mPosition; }
    
    void PlayTurn();
};

#endif // MONOPOLY_SIMULATOR_HPP
