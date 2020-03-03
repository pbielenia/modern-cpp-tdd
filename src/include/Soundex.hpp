#pragma once

#include <string>

class Soundex {
public:
    Soundex() = default;

    std::string encode(const std::string& word) const;

private:
    std::string head(const std::string& word) const;
    std::string encodedDigits(const std::string& word) const;
    std::string encodedDigit() const;
    std::string zeroPad(const std::string& word) const;

};
