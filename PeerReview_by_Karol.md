# Code Structure & CMake
Overall, I think code was very well organized. The only issues I encounter was around the utils folder. Just make sure that when you are giving path to 
folder it is correct. I had to change it to include folder.
# Modularity & Readability
The function seperations was very clear. The only thing I would change would be using strings as global variables. I would suggest using a text file and 
reading from that text file.
# Test Covrage
Test cases covered a good amount of cases, but missed a few. The function toLower didn't work. For the round input, input like, 4bc worked.  For my word guess input like, FLAKE, didnt work. Test cases didn't cover that.
# Bugs or Gaps Identified
Again toLower() function didn't work. Input like 4bc worked. And input like FLAKE didn't work. I would suggest making a for-range based for loop to convert each character
to lowercase with tolower() function.
# Test Output & Clarity
The test cases were clear and overall code was very clear and neat. Interacting with program was very easy to understand. 
# 5 New Google Test cases
```
#include <gtest/gtest.h>
#include "../include/checkGuess.hpp"
#include "../include/checkGuessNumInput.hpp"
#include "../include/checkWordInput.hpp"
#include <string>

using namespace std;

string validGuess(const string& guess) {
    if (guess.empty()) {
        throw invalid_argument("Empty string");
    }
    else if (guess.length() != 5) {
        throw invalid_argument("Guess exceeds 5 char");
    }
    for (auto letter : guess) {
        if (!isalpha(letter)) {
            throw invalid_argument("string contains other characters that arent letters");
            break;
        }
    }
    return guess;
}

int validRoundsInput(const string& input) {
    int rounds;
       size_t pos;//updated to the position in the string where the conversion stopped
       rounds = stoi(input, &pos);
       if (pos != input.length()) {
           throw invalid_argument("input can only contain numbers");
       }
       else if (rounds > 10 || rounds < 3) {
           throw out_of_range("out of range");
       }
   
    return rounds;
}
TEST(CheckGuessTest, EmptyGuess) {
    EXPECT_THROW(validGuess(" "), invalid_argument);
}
TEST(CheckGuessTest, ValidInitialGuess) {
    EXPECT_EQ(validGuess("apple"), "apple");
}
TEST(CheckGuessTest, InvalidInitialGuess) {
    EXPECT_THROW(validGuess("available"), invalid_argument);
    EXPECT_THROW(validGuess("f1ake"), invalid_argument);
}

TEST(CheckGuessTest,InvalidRoundInput) {
    EXPECT_THROW(validRoundsInput("11"), out_of_range);
    EXPECT_THROW(validRoundsInput("11ac"), invalid_argument);
}
TEST(CheckGuessTest, ValidRoundInput) {
    EXPECT_EQ(validRoundsInput("7"), 7);
    EXPECT_EQ(validRoundsInput("3"), 3);
}
```
# Architecture & Design Feedback
All in all, great program. I would defenetily suggest using a text file and creting a for-range based for loop to convert string to lowercase. 
