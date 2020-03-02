#include <gmock/gmock.h>
#include "Soundex.hpp"

using ::testing::Eq;

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    auto soundex = Soundex();
    auto encoded = soundex.encode("A");

    ASSERT_THAT(encoded, Eq("A"));
}
