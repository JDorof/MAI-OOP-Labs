#include <gtest/gtest.h>
#include "../src/solution.h"

TEST(SevenConstructors, DefaultConstructor) {
    Seven sev;
    EXPECT_EQ(sev.size, 0);
    EXPECT_EQ(sev.arr, nullptr);
}

TEST(SevenConstructors, AssignIntConstructor) {
    Seven sev(10, '5');
    ASSERT_EQ(sev.size, 10);
    for (size_t i = 0; i < 10; ++i) {
        ASSERT_EQ(sev.arr[i], '5');
    }
}

TEST(SevenConstructors, AssignIntConstructorException) {
    EXPECT_ANY_THROW(Seven sev(2, 'g'));
}

TEST(SevenConstructors, InitList) {
    Seven sev({'1', '2', '3', '4', '5', '6'});
    for (size_t i = 0; i < sev.size; ++i) {
        ASSERT_EQ(sev.arr[i], char(i + 49));
    }
}

TEST(SevenConstructors, InitListException) {
    EXPECT_ANY_THROW(Seven sev({'1', '2', '3', 'g', '5', '6'}));
}

TEST(SevenConstructors, CopyConstructor) {
    Seven sev1({'1', '4', '6', '3'});
    Seven sev = sev1;
    ASSERT_NE(&sev1, &sev) << "Copy constructor must do copy!\n";
    ASSERT_EQ(sev1.size, sev.size);
    for (size_t i = 0; i < sev.size; ++i) {
        ASSERT_EQ(sev1.arr[i], sev.arr[i]) << "Values must be equal!";
        ASSERT_NE(&sev1.arr[i], &sev.arr[i]) << "Need copy!";
    }
}

TEST(SevenConstructors, EmptyCopyOperator) {
    Seven sev1({'1', '3', '2', '6'});
    Seven sev;
    sev1 = sev;
    ASSERT_NE(&sev1, &sev) << "Copy constructor must do copy!\n";
    ASSERT_EQ(sev1.size, sev.size);
}

TEST(SevenConstructors, NotEmptyCopyOperator) {
    Seven sev1({'1', '3', '2', '6'});
    Seven sev({'1', '4'});
    sev1 = sev;
    ASSERT_NE(&sev1, &sev) << "Copy constructor must do copy!\n";
    ASSERT_EQ(sev1.size, sev.size);
}

TEST(SevenConstructors, MoveOperator) {
    Seven sev1({'1', '1', '1'});
    Seven sev;
    sev = std::move(sev1);
    ASSERT_EQ(sev.size, 3);
    ASSERT_EQ(sev1.size, 0);
    ASSERT_EQ(sev1.arr, nullptr);
}

TEST(SevenConstructors, String) {
    Seven sev("123456");
    for (size_t i = 0; i < sev.size; ++i) {
        ASSERT_EQ(sev.arr[i], char(i + 49));
    }
}

TEST(SevenConstructors, StringException) {
    EXPECT_ANY_THROW(Seven sev("1234g6"));
}

TEST(SevenConstructors, ConstructorWithHyphenation) {
    Seven sev({'7','6','6','1'});
    for (size_t i = 0; i < 3; ++i) {
        ASSERT_EQ(sev.arr[i], '0');
    }
    ASSERT_EQ(sev.arr[3], '2');
}

TEST(SevenComparison, BiggerSelf) {
    Seven sev("11");
    Seven sev1("11");
    ASSERT_FALSE(sev > sev);
    ASSERT_FALSE(sev > sev1);
}

TEST(SevenComparison, BiggerSize) {
    Seven sev1("1111");
    Seven sev2("111");
    Seven sev3("11");
    ASSERT_TRUE(sev1 > sev2);
    ASSERT_TRUE(sev1 > sev3);
    ASSERT_TRUE(sev2 > sev3);
    ASSERT_FALSE(sev2 > sev1);
    ASSERT_FALSE(sev3 > sev1);
    ASSERT_FALSE(sev3 > sev2);
}

TEST(SevenComparison, BiggerValue) {
    Seven sev1("226");
    Seven sev2("121");
    Seven sev3("011");
    ASSERT_TRUE(sev1 > sev2);
    ASSERT_TRUE(sev1 > sev3);
    ASSERT_TRUE(sev2 > sev3);
    ASSERT_FALSE(sev2 > sev1);
    ASSERT_FALSE(sev3 > sev1);
    ASSERT_FALSE(sev3 > sev2);
}

TEST(SevenComparison, BiggerSizeValue) {
    Seven sev1("12000");
    Seven sev2("1100");
    Seven sev3("110");
    Seven sev4("100000000");
    ASSERT_TRUE(sev1 > sev2);
    ASSERT_TRUE(sev1 > sev3);
    ASSERT_TRUE(sev1 > sev4);
    ASSERT_TRUE(sev2 > sev4);
    ASSERT_FALSE(sev2 > sev3);
    ASSERT_FALSE(sev2 > sev1);
    ASSERT_FALSE(sev3 > sev1);
    ASSERT_FALSE(sev3 > sev2);
}

TEST(SevenComparison, SmallerSelf) {
    Seven sev("11");
    Seven sev1("11");
    ASSERT_FALSE(sev < sev);
    ASSERT_FALSE(sev < sev1);
}

TEST(SevenComparison, SmallerSize) {
    Seven sev1("11");
    Seven sev2("111");
    Seven sev3("1111");
    ASSERT_TRUE(sev1 < sev2);
    ASSERT_TRUE(sev1 < sev3);
    ASSERT_TRUE(sev2 < sev3);
    ASSERT_FALSE(sev2 < sev1);
    ASSERT_FALSE(sev3 < sev1);
    ASSERT_FALSE(sev3 < sev2);
}

TEST(SevenComparison, SmallerValue) {
    Seven sev1("011");
    Seven sev2("111");
    Seven sev3("112");
    ASSERT_TRUE(sev1 < sev2);
    ASSERT_TRUE(sev1 < sev3);
    ASSERT_TRUE(sev2 < sev3);
    ASSERT_FALSE(sev2 < sev1);
    ASSERT_FALSE(sev3 < sev1);
    ASSERT_FALSE(sev3 < sev2);
}

TEST(SevenComparison, SmallerSizeValue) {
    Seven sev1("100000000");
    Seven sev2("110");
    Seven sev3("1100");
    Seven sev4("12000");
    ASSERT_TRUE(sev1 < sev2);
    ASSERT_TRUE(sev1 < sev3);
    ASSERT_TRUE(sev1 < sev4);
    ASSERT_TRUE(sev2 < sev4);
    ASSERT_FALSE(sev2 < sev3);
    ASSERT_FALSE(sev2 < sev1);
    ASSERT_FALSE(sev3 < sev1);
    ASSERT_FALSE(sev3 < sev2);
}

TEST(SevenComparison, Equation) {
    Seven sev1("11");
    Seven sev2("11");
    Seven sev3("01");
    Seven sev4("0");
    ASSERT_TRUE(sev1 == sev2);
    ASSERT_FALSE(sev2 == sev3);
    ASSERT_FALSE(sev3 == sev1);
    ASSERT_FALSE(sev1 == sev4);
    ASSERT_FALSE(sev2 == sev4);
    ASSERT_FALSE(sev3 == sev4);
}

TEST(SevenComparison, NotEquation) {
    Seven sev1("11");
    Seven sev2("11");
    Seven sev3("01");
    Seven sev4("0");
    ASSERT_FALSE(sev1 != sev2);
    ASSERT_TRUE(sev2 != sev3);
    ASSERT_TRUE(sev3 != sev1);
    ASSERT_TRUE(sev1 != sev4);
    ASSERT_TRUE(sev2 != sev4);
    ASSERT_TRUE(sev3 != sev4);
}

TEST(SevenComparison, SelfEquation) {
    Seven sev("113");
    ASSERT_TRUE(sev == sev);
}

TEST(SevenAddition, SimpleAddition) {
    Seven sev1("123");
    Seven sev2("123");
    Seven sum = sev1 + sev2;
    ASSERT_EQ(sum.size, 3);
    for (size_t i = 0; i < sum.size; ++i) {
        ASSERT_EQ(sum.arr[i], char((i + 1) * 2 + 48));
    }
}

TEST(SevenAddition, AdditionWithHyphenation) {
    Seven sev1("133");
    Seven sev2("634");
    Seven sum = sev1 + sev2;
    ASSERT_EQ(sum.size, 4);
    ASSERT_EQ(sum.arr[0], '0');
    ASSERT_EQ(sum.arr[1], '0');
    ASSERT_EQ(sum.arr[2], '1');
    ASSERT_EQ(sum.arr[3], '1');
}

TEST(SevenAddition, AdditionWithDifferentOrders) {
    Seven sev1("11");
    Seven sev2("222");
    Seven sum = sev1 + sev2;
    ASSERT_EQ(sum.size, 3);
    ASSERT_EQ(sum.arr[0], '3');
    ASSERT_EQ(sum.arr[1], '3');
    ASSERT_EQ(sum.arr[2], '2');
}

TEST(SevenAddition, AdditionWithDifferentOrdersWithHyphenation) {
    Seven sev1("657");
    Seven sev2("44444");
    Seven sum = sev1 + sev2;
    ASSERT_EQ(sum.size, 5);
    ASSERT_EQ(sum.arr[0], '3');
    ASSERT_EQ(sum.arr[1], '3');
    ASSERT_EQ(sum.arr[2], '5');
    ASSERT_EQ(sum.arr[3], '5');
    ASSERT_EQ(sum.arr[4], '4');
}