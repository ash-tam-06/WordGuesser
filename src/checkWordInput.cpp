#include <iostream>
#include <string>
#include <cstdlib>
#include <list>

using namespace std;

string checkWordInput() { //making sure user only inputs 5 letter string
    bool isValid=false;
    string guess;
    while(!isValid){
        isValid = true;
        cout<< "Please write your 5 letter word guess: " << endl;
        getline(cin, guess);
        guess = toLower(guess);
        if(guess.empty()){ //error handeling to make sure input is not empty
            cout << "invalid input, please enter a non empty string\n" << endl;
            isValid = false;
        } else if (guess.length() != 5){ //making sure string length is 5
            cout << "invalid input, please enter a string that is only 5 letters long\n" << endl;
            isValid = false;
        } else{
          //making sure string only contains letters
            for (auto letter : guess) {
                if (!isalpha(letter)) {
                    cout << "invalid input, please enter a string with only letters\n" << endl;
                    isValid = false;
                    break;
                }
            }

        }
    }
    return guess;
}