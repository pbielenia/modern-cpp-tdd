#include "CharUtil.h"
#include <string>

bool tdd::charutil::isVowel(char letter)
{
    return
        (std::string("aeiouy").find(lower(letter)) != std::string::npos);
}

char tdd::charutil::lower(char c)
{
    return std::tolower(static_cast<unsigned char>(c));
}
