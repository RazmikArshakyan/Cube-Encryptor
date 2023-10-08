#ifndef DECRYPTOR
#define DECRYPTOR

#include "Encryptor.h"

#include <vector>
#include <string>

class Decryptor {
public:  
    void decrypt(std::string& enc, const std::string& key);

private:
    void cube_decryptor(Cube& cube, const std::string& key);

};

#endif