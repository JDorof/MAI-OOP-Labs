#include <gtest/gtest.h>
#include "../src/solution.h"

TEST(EluminateUnsetBitsTest, SingleOne) {
    std::string input = "1";
    EXPECT_EQ(eluminate_unset_bits(input), 1);
}

TEST(EluminateUnsetBitsTest, SingleZero) {
    std::string input = "0";
    EXPECT_EQ(eluminate_unset_bits(input), 0);
}

TEST(EluminateUnsetBitsTest, MixedBits1) {
    std::string input = "101";
    EXPECT_EQ(eluminate_unset_bits(input), 3);
}

TEST(EluminateUnsetBitsTest, AllOnes) {
    std::string input = "111";
    EXPECT_EQ(eluminate_unset_bits(input), 7);
}

TEST(EluminateUnsetBitsTest, MixedBits2) {
    std::string input = "1001";
    EXPECT_EQ(eluminate_unset_bits(input), 3);
}

TEST(EluminateUnsetBitsTest, LeadingAndTrailingZeros) {
    std::string input = "00010010";
    EXPECT_EQ(eluminate_unset_bits(input), 3);
}

TEST(EluminateUnsetBitsTest, LongBinaryString) {
    std::string input = "1010101010101010";
    EXPECT_EQ(eluminate_unset_bits(input), 255);
}

TEST(EluminateUnsetBitsTest, ThrowsOnEmptyString) {
    std::string input = "";
    EXPECT_THROW(eluminate_unset_bits(input), std::invalid_argument);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}