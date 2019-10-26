#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

void printGrid();
void placeShip();
void guessLocation(); // calls checkLocation
bool checkLocation(int row, int col);
char grid[10][10];

int main() {
    placeShip();
    printGrid();
    guessLocation();
    return 0;
}

bool checkLocation(int row, int col) {
    return grid[row][col] == 'X';
}

void guessLocation() {
    string guess;
    int row, col;
    cout << "Enter your guess: ";
    getline(cin, guess);
    if (guess.size() != 2)
        guessLocation();
    else {
        int letterVal = (int) tolower(guess.at(0)) - 97; // between A - J
        int numVal = (int) guess.at(1) - 48; // between 0 and 9
        cout << "Letter Value = " << letterVal << "; Num = " << numVal << endl; 
        if ((letterVal >= 0 && letterVal < 10) && (numVal >= 0 && numVal < 10)) {
            row = letterVal;
        }
        else {
            guessLocation();
        }
    }
    checkLocation(row, col);
}

void printGrid() {
    cout << " ";
    for (int k = 0; k < 10; k++) {
        cout << (char)(k + 65) << " "; 
    } cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << i; 
        for (int j = 0; j < 10; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void placeShip() {
    srand(time(0));
    int placeX = rand() % 9 + 1; // 1 - 9
    int placeY = rand() % 9 + 1; // 1 - 9
    int length = rand() % 4 + 1; // 1 - 5 spaces
    int direction = rand() % 2 + (-1); // either +0 (vertical) or -1 (horizontal)

    cout << "placeX = " << placeX << "; " << "placeY = " << placeY << endl;
    cout << "ship length = " << length << "; direction = " << direction << endl;

    if (direction >= 0 && ((length + placeY) < 10 && (length + placeY) >= 0)) { // positive -- vertical
        for (int i = 0; i < length; i++) {
            grid[placeX][placeY + i] = 'X';
        }
        cout << "Ship fits in grid vertically" << endl;
    }
    else if (direction < 0 && ((length + placeX) < 10 && (length + placeX) >= 0)) { // negative -- horizontal
        for (int i = 0; i < length; i++) {
            grid[placeX + i][placeY] = 'X';
        }
        cout << "Ship fits in grid horizontally" << endl;
    }
    else {
        cout << "Ship can't fit; Recalculating" << endl;
        placeShip(); // recalculate
    }
}