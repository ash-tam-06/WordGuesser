#include <gtest/gtest.h>
#include "../include/checkGuess.hpp"
#include "../include/checkGuessNumInput.hpp"
#include "../include/checkWordInput.hpp"
#include <string>

using namespace std;

TEST(CheckGuessTest, AllCorrect) {
    EXPECT_TRUE(checkGuess("apple", "apple"));
}

TEST(CheckGuessTest, SomeCorrectSomeWrongPlace) {
    EXPECT_FALSE(checkGuess("apron", "apple"));
}

TEST(CheckGuessTest, AllWrong) {
    EXPECT_FALSE(checkGuess("zebra", "input"));
}

TEST(CheckGuessTest, SomeCorrectOnly) {
    EXPECT_FALSE(checkGuess("angle", "apple"));
}

TEST(CheckGuessTest, WrongLengthIgnored) {
    EXPECT_FALSE(checkGuess("app", "apple"));
}