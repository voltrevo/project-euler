#ifndef DECK_HPP
#define DECK_HPP

#include <algorithm>
#include <cassert>
#include <initializer_list>

template <typename Card>
class Deck
{
private:
    std::vector<Card> mCards;
    unsigned int mIndex;
    
    void Reset()
    {
        mIndex = 0u;
        std::random_shuffle(mCards.begin(), mCards.end());
    }

public:
    Deck(const std::initializer_list<Card>& cards)
    :
        mCards(cards),
        mIndex(0u)
    {
        std::random_shuffle(mCards.begin(), mCards.end());
    }
    
    const Card& Pickup()
    {
        if (mIndex == mCards.size())
            Reset();
        
        assert(mIndex < mCards.size());
        
        return mCards[mIndex++];
    }
};

#endif // DECK_HPP
