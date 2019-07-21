#ifndef STRING_UTIL_H
#define STRING_UTIL_H

#include <string>

namespace tdd {

namespace stringutil {

std::string head(const std::string& word);
std::string tail(const std::string& word);
std::string zeroPad(const std::string& word, const size_t max_code_length);
std::string upperFront(const std::string& string);

} // namespace stringutil

} // namespace tdd

#endif // STRING_UTIL_H
