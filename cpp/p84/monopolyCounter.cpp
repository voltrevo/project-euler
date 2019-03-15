#include <array>
#include <iostream>

#include "doubleDie.hpp"
#include "monopolySimulator.hpp"

int main()
{
    MonopolySimulator game(std::unique_ptr<IDie>(new DoubleDie(4)));
    std::array<std::pair<int, int>, 40> freqs;
    
    for (int i = 0; i != 40; ++i)
    {
        freqs[i].first = i;
        freqs[i].second = 0;
    }
    
    //std::cout << "Position: " << game.GetPosition() << std::endl;
    
    for (int i = 0; i != 10000000; ++i)
    {
        //std::cout << std::endl;
        game.PlayTurn();
        //std::cout << "Position: " << game.GetPosition() << std::endl;
        ++freqs[game.GetPosition()].second;
    }
    
    std::sort(
        freqs.begin(),
        freqs.end(),
        [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
        {
            return lhs.second > rhs.second;
        });
    
    for (int i = 0; i != 40; ++i)
    {
        std::cout << freqs[i].first << ": " << freqs[i].second << std::endl;
    }
    
    return 0;
}
