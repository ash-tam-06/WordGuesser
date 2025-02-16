cmake_minimum_required(VERSION 3.30)
project(WordGuesser)

set(CMAKE_CXX_STANDARD 20)

add_executable(WordGuesser main.cpp Utils/checkGuess.cpp Utils/checkGuessNumInput.cpp Utils/checkWordInput.cpp)