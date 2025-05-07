#include <iostream>
#include <string>
#include <list>

using namespace std;
int checkGuessNumInput() {
    int guessNum;

    //making sure user input is an int between 3 to 10
    while (true) {
        cout << "How many guesses would you like? You can choose any number between 3 to 10" << endl;
        cin >> guessNum;
        if(cin.fail() || (guessNum > 10 || guessNum < 3)){ //making sure user input is an int between 3 to 10
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<< "invalid input. please enter a valid guess num.\n";
        }else{
            cin.ignore(numeric_limits<streamsize>:: max(),'\n');
            break;
        }
    }
    return guessNum;
}