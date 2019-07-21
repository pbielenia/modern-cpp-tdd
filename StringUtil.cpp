#include "StringUtil.h"

std::string tdd::stringutil::head(const std::string& word)
{
    return word.substr(0, 1);
}

std::string tdd::stringutil::tail(const std::string& word)
{
    return word.substr(1);
}

std::string tdd::stringutil::zeroPad(const std::string& word, const size_t max_code_length)
{
    auto zerosNeeded = max_code_length - word.length();
    return word + std::string(zerosNeeded, '0');
}

std::string tdd::stringutil::upperFront(const std::string& string)
{
    return std::string(1, std::toupper(static_cast<unsigned char>(string.front())));
}
