#ifndef ENCRYPTOR
#define ENCRYPTOR

#include "Cube.h"

#include <string>
#include <vector>

class Encryptor {
public:
    std::string encrypt(std::string& text);  
    
protected:  
    size_t random_rotate(int min, int max);
    std::vector<Cube> string_to_cubes(const std::string& text);
};

#endif