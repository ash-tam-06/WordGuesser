
#include <iostream>
#include <string>
#include <cstdlib>
#include <list>


using namespace std;

string listOfWords[] = {"place", "party", "cloud", "pinky", "stair", "heart"};
string wordGuessed;
int guessNum;
string correctLetters, wrongPlaceLetters, guess, mystery;



void pickWord() {
    long elapsedSeconds = time(nullptr);
    srand(elapsedSeconds);
    int randNum = rand()%size(listOfWords);
    mystery = listOfWords[randNum];
}


void checkGuess(){
    while(guessNum < 5){
        for(int i = 0; i < 5; i++) {
            if(guess.substr(i, 1) == mystery.substr(i, 1)) {
                correctLetters +=  guess.substr(i,1) + " + ";

            } else if (mystery.find(guess.substr(i, 1)) != string::npos) {
                wrongPlaceLetters += guess.substr(i,1) + " + ";
            }
        }

        if(correctLetters.length() == 10){
            correctLetters = "";
        }

        cout << "These are the letters you got correct: " << correctLetters <<  endl;
        cout << "These are the letters you got correct, but are in the wrong place "<< wrongPlaceLetters << endl;

        guessNum++;
        correctLetters = "";
        wrongPlaceLetters = "";
    }
}

int main() {

    pickWord();

    cout << mystery << endl;


    cout<< "Please write your 5 letter word guess: " << endl;
    cin>>guess;

    checkGuess();

    return 0;
}
