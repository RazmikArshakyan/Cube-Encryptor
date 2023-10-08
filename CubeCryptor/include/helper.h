#ifndef HELPER
#define HELPER

#include "..//include/Cube.h"

#include <vector>
#include <string>

std::vector<std::string> splitter(const std::string &text, char symbol);
size_t random_rotate(int min, int max);
std::vector<Cube> string_to_cubes(const std::string &text);

#endif