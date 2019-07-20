#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>


namespace tdd {

class Soundex {
public:
    std::string encode(const std::string& word) const;
private:
    static const size_t max_code_length{4};

    std::string head(const std::string& word) const;
    std::string tail(const std::string& word) const;
    std::string encodedDigit(char letter) const;
    std::string encodedDigits(const std::string& word) const;
    std::string zeroPad(const std::string& word) const;
};

} // namespace tdd
#endif // SOUNDEX_H