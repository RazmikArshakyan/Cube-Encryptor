#include "..//include/Encryptor.h"  

#include <random>

std::string Encryptor::encrypt(std::string& text)
{
    std::vector<Cube> cubes = string_to_cubes(text);

    std::string key{};
    for (auto& el : cubes) {
        int ct = random_rotate(0, 360);
        el.rotate_left(ct);
        if (!key.empty()) {
            key += ':';
        }
        key = key + "L" + std::to_string(ct) + ',';

        ct = random_rotate(0, 360);
        el.rotate_down(ct);
        key = key + "D" + std::to_string(ct) + ',';

        ct = random_rotate(0, 360);
        el.rotate_right(ct);
        key = key + "R" + std::to_string(ct) + ',';

        ct = random_rotate(0, 360);
        el.rotate_up(ct);
        key = key + "U" + std::to_string(ct) + ',';
    }

    text.clear();
    for (auto& el : cubes) {
        text += el.to_string();
    }

    return key;
}

size_t Encryptor::random_rotate(int min, int max)
{
    std::random_device rd;  
    std::mt19937 mt(rd()); 
    std::uniform_int_distribution<int> dist(min, max); 

    return dist(mt);
}

std::vector<Cube> Encryptor::string_to_cubes(const std::string &text)
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