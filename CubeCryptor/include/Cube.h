#ifndef CUBE
#define CUBE

#include <string>
#include <array>
#include <algorithm>

class Cube {
public:  
    Cube();
    Cube(const std::string& text);
    Cube& operator=(const Cube& rhs);
    Cube(std::string::const_iterator it1, std::string::const_iterator it2);
    void rotate_left(size_t count);
    void rotate_right(size_t count);
    void rotate_up(size_t count);
    void rotate_down(size_t count);
    std::string to_string() const;

private:
    size_t rows{2};
    size_t columns{4};  
    const size_t max_rotate{4};
    std::array<std::array<char, 4>, 2> _cube;

};

#endif