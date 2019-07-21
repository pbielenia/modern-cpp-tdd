#include "Soundex.h"
#include <unordered_map>

std::string tdd::Soundex::encode(const std::string& word) const
{
    return zeroPad(upperFront(head(word)) + tail(encodedDigits(word)));
}

std::string tdd::Soundex::upperFront(const std::string& string) const
{
    return std::string(1, std::toupper(static_cast<unsigned char>(string.front())));
}

char tdd::Soundex::lower(char c) const
{
    return std::tolower(static_cast<unsigned char>(c));
}

std::string tdd::Soundex::head(const std::string& word) const
{
    return word.substr(0, 1);
}

std::string tdd::Soundex::tail(const std::string& word) const
{
    return word.substr(1);
}

std::string tdd::Soundex::encodedDigit(char letter) const
{
    const std::unordered_map<char,std::string> encodings {
        {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
        {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, 
                    {'s', "2"}, {'x', "2"}, {'z', "2"},
        {'d', "3"}, {'t', "3"},
        {'l', "4"},
        {'m', "5"}, {'n', "5"},
        {'r', "6"}
    };
    auto it = encodings.find(lower(letter));
    return it == encodings.end() ? NotADigit : it->second;
}

std::string tdd::Soundex::encodedDigits(const std::string& word) const
{
    std::string encoding;

    encodeHead(encoding, word);
    encodeTail(encoding, word);

    
    return encoding;
}

void tdd::Soundex::encodeHead(std::string& encoding, const std::string& word) const
{
    encoding += encodedDigit(word.front());
}

void tdd::Soundex::encodeTail(std::string& encoding, const std::string& word) const
{
    for (auto letter : tail(word)) {
        if (!isComplete(encoding))
            encodeLetter(encoding, letter);
    }
}

void tdd::Soundex::encodeLetter(std::string& encoding, char letter) const
{
    auto digit = encodedDigit(letter);
    if ((digit != NotADigit) && (digit != lastDigit(encoding)))
        encoding += digit;
}

std::string tdd::Soundex::lastDigit(const std::string& encoding) const
{
    if (encoding.empty()) return NotADigit;
    else return std::string(1, encoding.back());
}

std::string tdd::Soundex::zeroPad(const std::string& word) const
{
    auto zerosNeeded = max_code_length - word.length();
    return word + std::string(zerosNeeded, '0');
}

bool tdd::Soundex::isComplete(const std::string& encoding) const
{
    return (encoding.length() == max_code_length);
}
