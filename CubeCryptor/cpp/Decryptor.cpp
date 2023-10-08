#include "..//include/Decryptor.h"
#include <sstream>

void Decryptor::decrypt(std::string &enc, const std::string &key)
{
    std::vector<Cube> cubes = string_to_cubes(enc);
    std::vector<std::string> keys = splitter(key, ':');
    enc.clear();
    size_t i{};

    for (auto& el : cubes) {
        cube_decryptor(el, keys[i]);
        ++i;
        enc += el.to_string();
    }
} 

std::vector<std::string> Decryptor::splitter(const std::string &text, char symbol)
{
    std::vector<std::string> tokens;
    std::stringstream ss(text);
    std::string token;
    while (std::getline(ss, token, symbol)) {
        tokens.push_back(token);
    }
    return tokens;
}

void Decryptor::cube_decryptor(Cube &cube, const std::string &key)
{
    std::vector<std::string> edges = splitter(key, ',');
    int size = edges.size() - 1;
    for (int i = size; i >= 0; --i) {
        std::string sstring = edges[i].substr(1);
        
        if (edges[i][0] == 'R') {
            cube.rotate_left(std::stoi(sstring) % 4);
        }
        else if (edges[i][0] == 'L') {
            cube.rotate_right(std::stoi(sstring) % 4);
        }
        else if (edges[i][0] == 'U') {
            cube.rotate_down(std::stoi(sstring) % 4);
        }
        else if (edges[i][0] == 'D') {
            cube.rotate_up(std::stoi(sstring) % 4);
        }
    }
}
