#pragma once

#include <string>

class Soundex {
public:
    Soundex() = default;

    std::string encode(const std::string& word) const;
};
