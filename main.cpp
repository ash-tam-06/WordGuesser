#include <iostream>
#include <string>
#include <cstdlib>
#include <list>


using namespace std;

string listOfWords[] = {"place", "party", "cloud", "pinky", "stair", "heart"};
string wordGuessed;
int guessNum;
string mysteryWord[5], wordGuessedArray[5], lettersInCorrectPlace[5], lettersInWrongPlace[5];

void makeGuessArray(string word) {
    for (int i = 0; i < 5; i++) {
        wordGuessedArray[i] = word.substr(i, 1);
    }
}

void pickWord() {
    long elapsedSeconds = time(nullptr);
    srand(elapsedSeconds);
    int randNum = rand()%size(listOfWords);
    string randomWord = listOfWords[randNum];
    for (int i = 0; i < 5; i++) {
        mysteryWord[i] = randomWord.substr(i, 1);
    }
}

int main() {


    pickWord();
    for (int i = 0; i<5; i++)
        cout << mysteryWord[i] << endl;

    while (guessNum < 1) {

        cout<< "Please write your 5 letter word guess: " << endl;
        cin>>wordGuessed;
        makeGuessArray(wordGuessed);

        for (int i = 0; i< size(wordGuessedArray); i++) {
            if (mysteryWord[i] == wordGuessedArray[i]) {
                lettersInCorrectPlace[i] = wordGuessedArray[i];
            } else {
                for (int j = i +1; j < size(wordGuessedArray); j++) {
                    if (mysteryWord[i] == wordGuessedArray[j]) {
                        lettersInWrongPlace[i] = wordGuessedArray[j];
                        //TODO: get out of just this for loop
                    }
                }
            }
        }

        cout << "These are the letters you got correct"<< endl;
        for (int i = 0; i <5; i++) {
            cout <<lettersInCorrectPlace[i] << "_";
        }

        cout << "These are the letters you got correct, but are in the wrong place"<< endl;
        for (int i = 0; i <5; i++) {
            cout <<lettersInWrongPlace[i] << "_";
        }

    guessNum++;
    for (int i = 0; i< 5; i++) {
        lettersInWrongPlace[i] = "_";
        lettersInCorrectPlace[i] = "_";
    }
    }



    return 0;
}

