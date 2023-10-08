#include "..//include/Cube.h" 

Cube::Cube()
    : _cube{}
{
}

Cube::Cube(const std::string &text)
{
    if (text.size() == 0) {
        return;
    }

    size_t k{};
    for (size_t i{}; i < rows; ++i) {
        for (size_t j{}; j < columns; ++j, ++k) {
            if (k == text.size()) {
                break;
            }
            _cube[i][j] = text[k];
        }
    } 
}

Cube &Cube::operator=(const Cube &rhs)
{
    if (this == &rhs) {
        return *this;
    }

    for (size_t i{}; i < rows; ++i) {
        for (size_t j{}; j < columns; ++j) {
            _cube[i][j] = rhs._cube[i][j];
        }
    }
    return *this;
}

Cube::Cube(std::string::const_iterator it1, std::string::const_iterator it2)
    : _cube{}
{
    for (size_t i{}; i < rows; ++i) {
        for (size_t j{}; j < columns && it1 != it2; ++j, ++it1) {
            _cube[i][j] = *it1;
        }
    }
}

void Cube::rotate_left(size_t count)
{
    count %= max_rotate;
    if (!count) {
        return;
    }
    std::rotate(_cube[0].begin(), _cube[0].begin() + count, _cube[0].end());
    std::rotate(_cube[1].begin(), _cube[1].begin() + count, _cube[1].end());
}

void Cube::rotate_right(size_t count)
{
    rotate_left(max_rotate - (count % max_rotate));
}

void Cube::rotate_up(size_t count)
{
    count %= max_rotate;
    while (count) {
        std::swap(_cube[0][0], _cube[1][0]);
        std::swap(_cube[0][0], _cube[1][3]);
        std::swap(_cube[0][0], _cube[0][3]);
        std::swap(_cube[0][1], _cube[1][1]);
        std::swap(_cube[0][1], _cube[1][2]);
        std::swap(_cube[0][1], _cube[0][2]);
        --count;
    }
}

void Cube::rotate_down(size_t count)
{
    rotate_up(max_rotate - (count % max_rotate));
}

std::string Cube::to_string() const
{
    return std::string(_cube[0].begin(), _cube[0].end()) + std::string(_cube[1].begin(), _cube[1].end());
}