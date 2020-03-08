#include "Soundex.hpp"
#include <unordered_map>

static const size_t max_code_length{4};
static const std::string not_a_digit{"*"};

std::string Soundex::encode(const std::string& word) const
{
    return zeroPad(upperFront(head(word)) + tail(encodedDigits(word)));
}

std::string Soundex::head(const std::string& word) const
{
    return word.substr(0, 1);
}

std::string Soundex::tail(const std::string& word) const
{
    return word.substr(1);
}

std::string Soundex::lastDigit(const std::string& encoding) const
{
    if (encoding.empty()) return not_a_digit;
    return std::string(1, encoding.back());
}

std::string Soundex::upperFront(const std::string& string) const
{
    return std::string(1,
        std::toupper(static_cast<unsigned char>(string.front())));
}

std::string Soundex::encodedDigits(const std::string& word) const
{
    auto encoding = std::string();
    encodeHead(encoding, word);
    encodeTail(encoding, word);
    return encoding;
}

std::string Soundex::encodedDigit(char letter) const
{
    const std::unordered_map<char, std::string> encodings {
        {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
        {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
                    {'s', "3"}, {'x', "2"}, {'z', "2"},
        {'d', "3"}, {'t', "3"},
        {'l', "4"},
        {'m', "5"}, {'n', "5"},
        {'r', "6"}
    };
    auto it = encodings.find(lower(letter));
    return it == encodings.end() ? not_a_digit :  it->second;
}

std::string Soundex::zeroPad(const std::string& word) const
{
    auto zeros_needed = max_code_length - word.length();
    return word + std::string(zeros_needed, '0');
}

bool Soundex::isComplete(const std::string& encoding) const
{
    return encoding.length() == max_code_length;
}

char Soundex::lower(char c) const
{
    return std::tolower(static_cast<unsigned char>(c));
}

void Soundex::encodeHead(std::string& encoding, const std::string& word) const
{
    encoding += encodedDigit(word.front());
}

void Soundex::encodeTail(std::string& encoding, const std::string& word) const
{
    for (auto letter : tail(word)) {
        if (isComplete(encoding)) break;
            encodeLetter(encoding, letter);
    }
}

void Soundex::encodeLetter(std::string& encoding, char letter) const
{
    auto const digit = encodedDigit(letter);
    if ((digit != not_a_digit) && (digit != lastDigit(encoding)))
        encoding += digit;
}
