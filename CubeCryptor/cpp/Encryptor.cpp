#include "..//include/Encryptor.h"  
#include "helper.cpp"

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
