#include "monopolySimulator.hpp"

void MonopolySimulator::PlayTurn()
{
    boost::optional<int> rollResult = mDie->Roll();
    
    //std::cout << "Roll result: ";
    
    /*
    if (rollResult)
        std::cout << *rollResult;
    else
        std::cout << "three doubles (jail)";
    */
    
    //std::cout << std::endl;
    
    if (!rollResult)
    {
        mPosition = 10; // Jail
        return;
    }
    
    mPosition += *rollResult;
    mPosition %= 40;
    
    if (mPosition == 7 || mPosition == 22 || mPosition == 36)
    {
        // Chance
        
        switch (mChanceDeck.Pickup())
        {
            case ChanceCard::ADVANCE_TO_GO:
                //std::cout << "Chance: Advance to go" << std::endl;
                mPosition = 0;
                break;
            
            case ChanceCard::GO_TO_JAIL:
                //std::cout << "Chance: Go to jail" << std::endl;
                mPosition = 10;
                break;
            
            case ChanceCard::GO_TO_C1:
                //std::cout << "Chance: Go to C1" << std::endl;
                mPosition = 11;
                break;
            
            case ChanceCard::GO_TO_E3:
                //std::cout << "Chance: Go to E3" << std::endl;
                mPosition = 24;
                break;
            
            case ChanceCard::GO_TO_H2:
                //std::cout << "Chance: Go to H2" << std::endl;
                mPosition = 39;
                break;
            
            case ChanceCard::GO_TO_R1:
                //std::cout << "Chance: Go to R1" << std::endl;
                mPosition = 5;
                break;
            
            case ChanceCard::GO_TO_NEXT_RAILWAY:
                
                //std::cout << "Chance: Go to next railway" << std::endl;
                
                if (mPosition == 7)
                    mPosition = 15;
                else if (mPosition == 22)
                    mPosition = 25;
                else if (mPosition == 36)
                    mPosition = 5;
                else
                    assert(false);
                
                break;
            
            case ChanceCard::GO_TO_NEXT_UTILITY:
                
                //std::cout << "Chance: Go to next utility" << std::endl;
                
                if (mPosition == 7 || mPosition == 36)
                    mPosition = 12;
                else if (mPosition == 22)
                    mPosition = 28;
                else
                    assert(false);
                
                break;
            
            case ChanceCard::GO_BACK_3:
                
                //std::cout << "Chance: Go back 3" << std::endl;
                
                mPosition += 40 - 3;
                mPosition %= 40;
                break;
            
            case ChanceCard::OTHER:
                //std::cout << "Chance: Other" << std::endl;
                break;
        }
    }
    else if (mPosition == 2 || mPosition == 17 || mPosition == 33)
    {
        // Community chest
        
        switch (mCommunityChest.Pickup())
        {
            case CommunityChestCard::ADVANCE_TO_GO:
                //std::cout << "Community Chest: Advance to go" << std::endl;
                mPosition = 0;
                break;
            
            case CommunityChestCard::GO_TO_JAIL:
                //std::cout << "Community Chest: Go to jail" << std::endl;
                mPosition = 10;
                break;
            
            case CommunityChestCard::OTHER:
                //std::cout << "Community Chest: Other" << std::endl;
                break;
        }
    }
    else if (mPosition == 30)
    {
        // Go to jail
        
        mPosition = 10;
    }
}
