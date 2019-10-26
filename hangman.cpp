#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

void initialize(vector<char> v);
string getWord();
vector<char> convertWordToVector(string w);
void printVector(vector<char> v);
char enterLetter();
bool checkLetter(char c, vector<char> v);
bool contains(char c, vector<char> v);
void updateDisplay(int points, bool good);
int updateDisplayVector (char c, vector<char> v);
void playHangman();
void playAgain();

string words[5]= {"strawberry", "lime", "orange", "lemon", "mango"};
vector<char> display;
vector<char> prevLetters;
int score;
int attemptsLeft;
int highscore = 0;

int main() {
    playHangman();
    return 0;
}

void playAgain() {
    char ans;
    cin.ignore();
    cout << "Want to play again? (Y/N) ";
    cin >> ans;
    if (ans == 'Y' || ans == 'y')
        playHangman();
}

void playHangman() {
    vector<char> goodLetters = convertWordToVector(getWord());
    initialize(goodLetters);

    while (attemptsLeft > 0 && score < display.size()) {
        int points = 0;
        char guess = enterLetter();
        bool goodGuess = checkLetter(guess, goodLetters);
        if (!contains(guess, prevLetters)) {
            prevLetters.push_back(guess);
            points = updateDisplayVector(guess, goodLetters);
        }
        updateDisplay(points, goodGuess);
    }
    if (attemptsLeft <= 0) {
        cout << "You lost! The word was "; printVector(goodLetters);
    } else {
        cout << "You won!" << endl;
    }
    playAgain();
}

int updateDisplayVector (char c, vector<char> v) {
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (c == v.at(i)) {
            display.at(i) = c;
            count++;
        }
    }
    return count;
}

bool contains(char c, vector<char> v) {
    for (int i = 0; i < v.size(); i++) {
        if (v.at(i) == c)
            return true;
    }
    return false;
}

bool checkLetter(char c, vector<char> v) {
    if (contains(c, v) && !contains(c, prevLetters))
        return true;
    return false;
}

void updateDisplay(int points, bool good) {
    score += points;
    if (!good) 
        attemptsLeft--;

    cout << "Score: " +  to_string(score) + "; Highscore: " + to_string(highscore) + "; Attempts: " + to_string(attemptsLeft) << endl;
    cout << "Previous guesses: "; printVector(prevLetters);
    printVector(display);
}

void initialize(vector<char> v) {
    cout << "----------------------------" << endl;
    cout << "           HANGMAN          " << endl;
    cout << "----------------------------" << endl;
   
    display.clear();
    prevLetters.clear();
    for (int i = 0; i < v.size(); i++){
        display.push_back('*');
    }
    printVector(display);
    
    if (highscore < score) 
        highscore = score;
    score = 0;
    attemptsLeft = 7;
}

char enterLetter() {
    char c;
    cout << "Guess a letter: ";
    cin >> c;
    int val = (int)c;
    if (val >= 65 && val <= 122) {
        return c;
    } 
    else {
        cout << "Invalid input. Try again." << endl;
        enterLetter();
    }
}

string getWord() {
    srand(time(0));
    int i = rand() % 5;
    return words[i];
}

vector<char> convertWordToVector(string w) {
    vector<char> v;
    for (int i = 0; i < w.size(); i++){
        v.push_back(w.at(i));
    }
    return v;
}

void printVector(vector<char> v) {
    for (int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
}