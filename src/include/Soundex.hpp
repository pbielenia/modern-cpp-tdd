#pragma once

#include <string>

class Soundex {
public:
    Soundex() = default;

    std::string encode(const std::string& word) const;
    std::string encodedDigit(char letter) const;

private:
    std::string head(const std::string& word) const;
    std::string tail(const std::string& word) const;
    std::string lastDigit(const std::string& encoding) const;
    std::string upperFront(const std::string& string) const;
    std::string encodedDigits(const std::string& word) const;
    std::string zeroPad(const std::string& word) const;
    bool isComplete(const std::string& encoding) const;
    char lower(char c) const;
    bool isVowel(char letter) const;
    void encodeHead(std::string& encoding, const std::string& word) const;
    void encodeTail(std::string& encoding, const std::string& word) const;
    void encodeLetter(std::string& encoding, char letter, char last_letter) const;

};
