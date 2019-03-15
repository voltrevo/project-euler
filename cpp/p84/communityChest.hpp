#ifndef COMMUNITY_CHEST_HPP
#define COMMUNITY_CHEST_HPP

#include "deck.hpp"

enum class CommunityChestCard
{
    ADVANCE_TO_GO,
    GO_TO_JAIL,
    OTHER
};

using CommunityChest = Deck<CommunityChestCard>;

inline CommunityChest MakeCommunityChest()
{
    return CommunityChest({
        CommunityChestCard::ADVANCE_TO_GO,
        CommunityChestCard::GO_TO_JAIL,
        CommunityChestCard::OTHER,
        CommunityChestCard::OTHER,
        CommunityChestCard::OTHER,
        CommunityChestCard::OTHER,
        CommunityChestCard::OTHER,
        CommunityChestCard::OTHER,
        CommunityChestCard::OTHER,
        CommunityChestCard::OTHER,
        CommunityChestCard::OTHER,
        CommunityChestCard::OTHER,
        CommunityChestCard::OTHER,
        CommunityChestCard::OTHER,
        CommunityChestCard::OTHER,
        CommunityChestCard::OTHER});
}

#endif // COMMUNITY_CHEST_HPP
