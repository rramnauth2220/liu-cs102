/*
     ^
    ^^^
   ^^^^^
  ^^^^^^^
 ^^^^^^^^^
^^^^^^^^^^^
*/

#include <iostream>
#include <vector>

// #include <unistd.h>
#include <windows.h>
#include <chrono> // on Windows
#include <thread> // on Windows

using namespace std;

int enterNumber();
void drawTree(int levels);
void printTree();
void ShowConsoleCursor(bool showFlag);

vector<vector<char>> tree;

int main(){
    ShowConsoleCursor(false);
    drawTree(enterNumber());
    return 0;
}

void drawTree(int levels){
    for (int i = 0; i < levels; i++){ // level
        vector<char> level;
        for (int k = levels; k >= i; k--) { // spacing
            level.push_back(' ');
        }
        for (int j = 0; j <= (i * 2); j++){ // leaves
            level.push_back('^');
        }
        tree.push_back(level);
    }
    //printTree();
    while(1){
        system("CLS"); // on Windows
        //system("clear"); // Mac OS

        int row = rand() % tree.size(); // random level
        int col = rand() % tree.at(row).size(); // random leaf/space
        
        if (tree.at(row).at(col) == '^'){ // toggle
            tree.at(row).at(col) = '*';
        } else if (tree.at(row).at(col) == '*'){
            tree.at(row).at(col) = '^';
        }

        printTree();
        Sleep(20000);
        //usleep(1000000); // Mac OS -- milliseconds
    }
} 

void printTree(){
    for (int i = 0; i < tree.size(); i++){ // levels
        for (int j = 0; j < tree.at(i).size(); j++){
            cout << tree.at(i).at(j);
        }
        cout << endl;
    }
}

int enterNumber(){
    int num;
    cout << "Enter a number: ";
    cin >> num;
    return num;
}

// disabling the cursor
// (https://stackoverflow.com/questions/18028808/blinking-underscore-with-console)
void ShowConsoleCursor(bool showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}