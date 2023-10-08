#include "..//include/Decryptor.h"
#include "..//include/helper.h"
#include "..//include/Hacker.h"

#include <iostream>
#include <fstream>

int main() {
    using std::cout;
    using std::endl;
    Encryptor e;
    std::string text{"abandoned abbreviation"};
    auto key = e.encrypt(text);
    cout << "Text after encrypting " << endl;
    cout << text << endl;

    std::ifstream file("C:\\Users\\Razmik Arshakyan\\OneDrive\\Desktop\\C++\\OOP\\Tasks\\Cube-Encryptor\\words_alpha.txt");
    if (!file.is_open()) {
        std::cerr << "Unable to open the file." << endl;
        return -1;
    }

    std::vector<std::string> word_list;
    std::string line;
    while (std::getline(file, line)) {
        word_list.push_back(line);
    }

    file.close();

    Hacker h;
    cout << "Decrypting without key" << endl;
    h.decrypt_without_key(text, word_list);
    cout << text;
    
}