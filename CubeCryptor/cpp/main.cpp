#include <iostream>
#include "..\\include/Decryptor.h"

int main() {
    using std::cout;
    using std::endl;
    Encryptor e;
    std::string text{"Judge views had mirth table seems great him for her."};
    auto key = e.encrypt(text);
    cout << "Text afrer encrypting " << endl;
    cout << text << endl;
    Decryptor d;
    d.decrypt(text, key);
    cout << "Text after decrypting " << endl;
    cout << text << endl;
}