#include "..//include/Hacker.h"

void Hacker::decrypt_without_key(std::string &text, std::vector<std::string>& word_list)
{
    std::vector<Cube> cubes = string_to_cubes(text);
    bool found = false;
    std::string decrypted{};
    std::vector<std::string> ss;
    std::string str;
    std::string t;
    while (!found) {
        for (auto& el : cubes) {
            int ct = random_rotate(0, 5);
            el.rotate_down(ct);

            ct = random_rotate(0, 5);
            el.rotate_left(ct);

            ct = random_rotate(0, 5);
            el.rotate_right(ct);

            ct = random_rotate(0, 5);
            el.rotate_up(ct);      
        }

        str = "";
        for (auto& el : cubes) {
            str += el.to_string();
        }
        
        t = "";
        for (size_t i{}; i < str.size(); ++i) {
            if (str[i] != '\000') {
                t += str[i];
            }
        }
        
        bool el_found = false;
        ss = splitter(t, ' ');
        if (ss.size() == 1) {
            word_list.erase(std::remove_if(word_list.begin(), word_list.end(),
            [t](const std::string& el) { return el.size() != t.size(); }),
            word_list.end());
        }

        for (auto el = ss.begin(); el != ss.end(); ++el) {
            for (auto& it : word_list) {
                 if (*el == it) {
                    decrypted += *el;
                    found = true;
                    el = ss.erase(el);
                    t = "";
                    for (auto el = ss.begin(); el != ss.end(); ++el) {
                        t += *el;
                    }
                }
            }
        }
    }
    
    text += " " + decrypted;
    if (!ss.empty()) {
        decrypt_without_key(t, word_list);
    }
}   