#ifndef HACKER
#define HACKER

#include "Cube.h"
#include "helper.h"

#include <vector>

class Hacker {
public:  
    void decrypt_without_key(std::string& text, std::vector<std::string>& word_list);

};

//#include "..//cpp/Hacker.cpp"
#endif