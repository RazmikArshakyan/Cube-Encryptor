#include "..//include/Cube.h"

#include <sstream>
#include <random>

std::vector<std::string> splitter(const std::string &text, char symbol)
{
    std::vector<std::string> tokens;
    std::stringstream ss(text);
    std::string token;
    while (std::getline(ss, token, symbol)) {
        tokens.push_back(token);
    }
    return tokens;
}

size_t random_rotate(int min, int max)
{
    std::random_device rd;  
    std::mt19937 mt(rd()); 
    std::uniform_int_distribution<int> dist(min, max); 

    return dist(mt);
}


std::vector<Cube> string_to_cubes(const std::string &text)
{
    size_t ct = text.size() / 8 + (text.size() % 8 != 0);
    std::vector<Cube> cubes(ct);

    auto it1 = text.begin();
    auto it2 = text.begin() + 8;
    for (auto& el : cubes) {
        el = Cube(it1, it2);
        it1 = it2;
        it2 = std::min(it2 + 8, text.end());
    }
    return cubes;
}