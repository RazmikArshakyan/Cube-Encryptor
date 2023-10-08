#ifndef DECRYPTOR
#define DECRYPTOR

#include "Encryptor.h"

#include <vector>
#include <string>

class Decryptor : private Encryptor {
public:  
    void decrypt(std::string& enc, const std::string& key);

private:
    std::vector<std::string> splitter(const std::string& text, char symbol);
    void cube_decryptor(Cube& cube, const std::string& key);

};

#endif