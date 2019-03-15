#ifndef CHANCE_DECK_HPP
#define CHANCE_DECK_HPP

#include "deck.hpp"

enum class ChanceCard
{
    ADVANCE_TO_GO,
    GO_TO_JAIL,
    GO_TO_C1,
    GO_TO_E3,
    GO_TO_H2,
    GO_TO_R1,
    GO_TO_NEXT_RAILWAY, // 2 cards
    GO_TO_NEXT_UTILITY, // 2 cards
    GO_BACK_3,
    OTHER // 6 cards
};

using ChanceDeck = Deck<ChanceCard>;

inline ChanceDeck MakeChanceDeck()
{
    return ChanceDeck({
        ChanceCard::ADVANCE_TO_GO,
        ChanceCard::GO_TO_JAIL,
        ChanceCard::GO_TO_C1,
        ChanceCard::GO_TO_E3,
        ChanceCard::GO_TO_H2,
        ChanceCard::GO_TO_R1,
        ChanceCard::GO_TO_NEXT_RAILWAY,
        ChanceCard::GO_TO_NEXT_RAILWAY,
        ChanceCard::GO_TO_NEXT_UTILITY,
        ChanceCard::GO_TO_NEXT_UTILITY,
        ChanceCard::GO_BACK_3,
        ChanceCard::OTHER,
        ChanceCard::OTHER,
        ChanceCard::OTHER,
        ChanceCard::OTHER,
        ChanceCard::OTHER,
        ChanceCard::OTHER});
}

#endif // CHANCE_DECK_HPP
