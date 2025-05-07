cmake_minimum_required(VERSION 3.30)
project(WordGuesser)

set(CMAKE_CXX_STANDARD 20)

include(include)

add_executable(WordGuesser main.cpp
        src/checkGuess.cpp
        src/checkGuessNumInput.cpp
        src/checkWordInput.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(wordGuess_test test/guess_test.cpp
        src/checkGuess.cpp
        src/checkGuessNumInput.cpp
        src/checkWordInput.cpp)

target_include_directories(wordGuess_test PRIVATE include)
target_link_libraries(wordGuess_test gtest_main)

include(GoogleTest)
gtest_discover_tests(wordGuess_test)