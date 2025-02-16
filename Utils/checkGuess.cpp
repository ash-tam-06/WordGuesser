#include <iostream>
#include <string>
#include <cstdlib>
#include <list>

using namespace std;


bool checkGuess(string guess, string mystery){
    string correctLetters, wrongPlaceLetters;
    int numCorrect = 0; //variable to see if all letters are correctly placed
    for(int i = 0; i < 5; i++) { //looping by number of letters in word
        if(guess.substr(i, 1) == mystery.substr(i, 1)) { //checking if letter is correctly placed in guess
            correctLetters +=  guess.substr(i,1) + " + ";
            numCorrect++;
        } else if (mystery.find(guess.substr(i, 1)) != string::npos) {//checking if letter from guess is in the mystery word
            wrongPlaceLetters += guess.substr(i,1) + " + ";
        }
    }

    if(numCorrect == 5) { //if see if guess matched mystery word
        return true;
    }
    cout << "These are the letters you got correct: " << correctLetters <<  endl;
    cout << "These are the letters you got correct, but are in the wrong place: "<< wrongPlaceLetters << endl;
    cout << ""<< endl;
    correctLetters = "";
    wrongPlaceLetters = "";
    return false;
}