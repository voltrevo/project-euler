#include <cassert>
#include <iostream>
#include <deque>
#include <set>

std::set<std::string> commonWords;

int GetScore(std::deque<int> text, int* key);

int main()
{
    std::deque<int> text;
    
    commonWords.insert("and");
    commonWords.insert("the");
    commonWords.insert("that");
    commonWords.insert("have");
    commonWords.insert("for");
    commonWords.insert("not");
    commonWords.insert("with");
    commonWords.insert("you");
    
    int i;
    char c;
    
    while (true)
    {
        std::cin >> i;
        
        if (std::cin.eof())
            break;
        
        text.push_back(i);
        
        std::cin >> c;
    }
    
    int maxScore = 0;
    
    int key[3];
    for (key[0] = 'a'; key[0] != 'z'; ++key[0])
    {
        for (key[1] = 'a'; key[1] != 'z'; ++key[1])
        {
            for (key[2] = 'a'; key[2] != 'z'; ++key[2])
            {
                int score = GetScore(text, key);
                if (score > maxScore)
                {
                    maxScore = score;
                    std::cout << static_cast<char>(key[0]);
                    std::cout << static_cast<char>(key[1]);
                    std::cout << static_cast<char>(key[2]);
                    std::cout << ": " << score << std::endl;
                }
            }
        }
    }
    
    key[0] = 'g';
    key[1] = 'o';
    key[2] = 'd';
    
    int sum = 0;
    for (int i = 0; i != text.size(); ++i)
        sum += text[i] ^ key[i % 3];
    
    std::cout << sum << std::endl;
    
    return 0;
}

int GetScore(std::deque<int> text, int* key)
{
    for (int i = 0; i != text.size(); ++i)
        text[i] ^= key[i % 3];
    
    char str[5];
    int score = 0;
    
    for (int i = 0; i != text.size(); ++i)
    {
        if (i + 2 < text.size())
        {
            str[0] = text[i];
            str[1] = text[i + 1];
            str[2] = text[i + 2];
            str[3] = '\0';
            
            if (commonWords.find(str) != commonWords.end())
                ++score;
        }
        
        if (i + 3 < text.size())
        {
            str[0] = text[i];
            str[1] = text[i + 1];
            str[2] = text[i + 2];
            str[3] = text[i + 3];
            str[4] = '\0';
            
            if (commonWords.find(str) != commonWords.end())
                ++score;
        }
    }
    
    return score;
}
