#include <cassert>
#include <cstddef>
#include <iostream>
#include <set>

const char* HAND_NAMES[] = {
    "error",
    "high card",
    "pair",
    "two pair",
    "three of a kind",
    "straight",
    "flush",
    "full house",
    "four of a kind",
    "straight flush",
    "error"};

struct PokerHand
{
    std::size_t mRank;
    std::size_t mKeyCardNum;
    std::multiset<std::size_t, std::greater<std::size_t> > mCardNums;
    
    bool operator>(const PokerHand& rhs) const
    {
        std::cout << HAND_NAMES[mRank] << " vs. " << HAND_NAMES[rhs.mRank] << ": ";
        if (mRank > rhs.mRank)
        {
            std::cout << "win" << std::endl;
std::cout << std::endl;
            return true;
        }
        else if (rhs.mRank > mRank)
        {
            std::cout << "loss" << std::endl;
std::cout << std::endl;
            return false;
        }
        else
        {
            std::cout << "needs tiebreaking";
        }
        
        if (mKeyCardNum > rhs.mKeyCardNum)
        {
            std::cout << ", win on key card" << std::endl << std::endl;
            return true;
        }
        else if (rhs.mKeyCardNum > mKeyCardNum)
        {
            std::cout << ", loss on key card" << std::endl << std::endl;
            return false;
        }
        
        if (mCardNums > rhs.mCardNums)
        {
            std::cout << ", win on general cards" << std::endl << std::endl;
            return true;
        }
        else if (rhs.mCardNums > mCardNums)
        {
            std::cout << ", loss on general cards" << std::endl << std::endl;
            return false;
        }
        
        std::cout << ", unbroken tie" << std::endl;
        
        return false;
    }
    
    bool operator<(const PokerHand& rhs) const
    {
        return rhs > *this;
    }
};

std::size_t CharToCardNum(char c)
{
    if ('2' <= c && c <= '9')
        return c - '0';
    
    if (c == 'T')
        return 10u;
    
    if (c == 'J')
        return 11u;
    
    if (c == 'Q')
        return 12u;
    
    if (c == 'K')
        return 13u;
    
    if (c == 'A')
        return 14u;
    
    std::cerr << "Invalid char: " << c << std::endl;
    assert(false);
    return 0u;
}

template <typename Container>
typename Container::value_type SecondElement(Container& c)
{
    typename Container::iterator it = c.begin();
    assert(it != c.end());
    ++it;
    assert(it != c.end());
    return *it;
}

std::istream& operator>>(std::istream& is, PokerHand& ph)
{
    ph.mCardNums.clear();
    
    char c;
    char suit;
    bool isFlush = true;
    
    for (int i = 0; i != 5; ++i)
    {
        is >> c;
        if (is.eof())
            return is;
std::cout << c;
        ph.mCardNums.insert(CharToCardNum(c));
        
        is >> c;
        if (is.eof())
            return is;
std::cout << c << ' ';
        if (c != suit && i != 0)
            isFlush = false;
        
        suit = c;
    }
std::cout << std::endl;
    
    std::multiset<std::size_t, std::greater<std::size_t> > repeats;
    std::size_t prevCard = 0;
    std::size_t counter = 0;
    std::size_t maxCount = 0;
    std::size_t cardNumOfMaxCount = 0;
    for (
        std::multiset<std::size_t>::iterator it = ph.mCardNums.begin();
        it != ph.mCardNums.end();
        ++it)
    {
        if (*it == prevCard)
        {
            ++counter;
        }
        else
        {
            if (counter != 0)
            {
                repeats.insert(counter);
                if (counter > maxCount)
                {
                    maxCount = counter;
                    cardNumOfMaxCount = prevCard;
                }
                else if (counter == maxCount)
                {
                    cardNumOfMaxCount = std::max(cardNumOfMaxCount, prevCard);
                }
            }
            
            counter = 1;
            prevCard = *it;
        }
    }
    
    repeats.insert(counter);
    if (counter > maxCount)
    {
        maxCount = counter;
        cardNumOfMaxCount = prevCard;
    }
    else if (counter == maxCount)
    {
        cardNumOfMaxCount = std::max(cardNumOfMaxCount, prevCard);
    }
    
    bool isStraight = false;
    
    if (*repeats.begin() == 1)
    {
        isStraight = true;
        prevCard = 0;
        for (
            std::multiset<std::size_t>::iterator it = ph.mCardNums.begin();
            it != ph.mCardNums.end();
            ++it)
        {
            if (prevCard != 0 && *it != prevCard - 1)
            {
                isStraight = false;
                break;
            }
            
            prevCard = *it;
        }
    }
    
    if (isStraight && isFlush)
    {
        ph.mRank = 9; // straight flush
        ph.mKeyCardNum = *ph.mCardNums.begin();
    }
    else if (*repeats.begin() == 4)
    {
        ph.mRank = 8; // four of a kind
        ph.mKeyCardNum = cardNumOfMaxCount;
    }
    else if (*repeats.begin() == 3 && *repeats.rbegin() == 2)
    {
        ph.mRank = 7; // full house
        ph.mKeyCardNum = cardNumOfMaxCount;
    }
    else if (isFlush)
    {
        ph.mRank = 6; // flush
        ph.mKeyCardNum = *ph.mCardNums.begin();
    }
    else if (isStraight)
    {
        ph.mRank = 5; // straight
        ph.mKeyCardNum = *ph.mCardNums.begin();
    }
    else if (*repeats.begin() == 3)
    {
        ph.mRank = 4; // three of a kind
        ph.mKeyCardNum = cardNumOfMaxCount;
    }
    else if (*repeats.begin() == 2 && SecondElement(repeats) == 2)
    {
        ph.mRank = 3; // two pair
        ph.mKeyCardNum = cardNumOfMaxCount;
    }
    else if (*repeats.begin() == 2)
    {
        ph.mRank = 2; // pair
        ph.mKeyCardNum = cardNumOfMaxCount;
    }
    else
    {
        ph.mRank = 1; // high card
        ph.mKeyCardNum = *ph.mCardNums.begin();
    }
    
    return is;
}

int main()
{
    int wins = 0;
    
    PokerHand p1, p2;
    while (true)
    {
        std::cin >> p1 >> p2;
        if (std::cin.eof())
            break;
        
        if (p1 > p2)
            ++wins;
    }
    
    std::cout << wins << std::endl;
    
    return 0;
}
