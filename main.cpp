#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include "utils/checkGuess.hpp"
#include "utils/checkWordInput.hpp"
#include "utils/checkGuessNumInput.hpp"


using namespace std;
//array containing all the possible mystery words
string listOfWords[] = {"place", "party", "cloud", "pinky", "stair", "heart", "about", "alert", "argue", "beach", "above", "alike", "arise", "began"
, "begin", "abuse", "bench", "black", "blame", "blind", "cover", "craft", "crush", "crash", "crime", "crowd", "clean", "clear", "cause", "close", "curve"
, "daily", "death", "dance" ,"dealt", "debut", "delay", "depth", "doing", "doubt", "dozen", "draft", "drawn", "dream", "entry", "event", "exact", "exist", "extra", "faith", "false" ,"forth", "forty", "found"
,"frame", "frank", "fraud", "guest", "guide", "guess", "grown", "guard", "group", "happy", "hence", "hotel", "human", "horse", "heavy", "index", "inner", "input", "ideal", "issue", "irony", "juice", "joint", "judge"
, "known", "local", "loose", "logic", "lower", "lucky", "lunch", "lying", "learn", "layer", "magic", "major", "maker", "march", "music", "mouse", "moral", "noted", "noise", "north"
, "nurse", "novel", "newly", "ocean", "often", "order", "other","ought", "paint", "paper"," peace", "phone", "ratio", "queen", "reach", "ready", "refer", "right", "quick", "shall", "sense", "serve","seven","shall","shape","share"
,"title","times","tired","today","topic","total","taken","trend","trial","until","unity","upper","wound","write","wrong","wrote","wheel","young","youth","virus", "visit", "video","wound","would","vital","voice"};

int guessNum;
string guess;


int main() {
  //getting a random word from listOfWords array
    long elapsedSeconds = time(nullptr);
    srand(elapsedSeconds);
    int randNum = rand()%size(listOfWords);
    string mystery = listOfWords[randNum];

    //intro to the game and how it works
    cout << "Hello! Welcome to a word guessing game!" << endl;
    cout << "Here is how this game will work: " << endl;
    cout << "-You get a certain number of guesses, and must guess the mystery word before you run out of guesses." << endl;
    cout << "-After each guess, you will be told what letters were in the right spot, and what letters are in the word" << endl;
    cout << endl;
    cout << "You have the option to chose the difficulty of this game by choosing how many guesses you get!" << endl;

    //getting user to pick how many guesses they would like
    guessNum = checkGuessNumInput();

    //actual game play, looping until user guesses word or till they run out of guesses
    while(guessNum > 0) {

        guess = checkWordInput(); //making sure user input is vaild
        if (checkGuess(guess, mystery)) { //checking if user guessed correctly
            cout << "you got it! the mystery word was: " << mystery << endl;
            break;
        }

        guessNum--;
    }
    if (guessNum == 0) { //only print of user ran out of guesses
        cout << "You ran out of guesses. The word was: " << mystery << endl;
    }


    return 0;
}
