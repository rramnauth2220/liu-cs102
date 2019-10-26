#include <iostream>
#include <vector>
//#include <unistd.h> // for Mac OS for system(...)
#include <chrono> // for Windows - sleep/delay thread
#include <thread> // for Windows - sleep/delay thread
#include <windows.h> // for Windows - hide cursor

using namespace std;

int enterNumber(string qualifier);
void drawTriangle();
void drawLayered();
void drawLights();
void printTree();
void ShowConsoleCursor(bool showFlag); // for Windows - hide cursor

vector< vector<char> > tree;

int main(){
    //drawTriangle();
    //drawLayered();
    drawLights();
    return 0;
}

void drawLights(){
    ShowConsoleCursor(false); // hide cursor
    int levels = enterNumber("levels") * 2;

    // build Christmas tree
    for (int i = 1; i <= levels; i+=2){
        vector<char> level;
        for (int k = (levels - i)/2; k > 0; k--){
            level.push_back(' ');
        }
        for (int j = 1; j <= i; j++){
            level.push_back('.');
        }
        tree.push_back(level);
    }
    
    while (1){
        //system("clear"); // on Mac OS
        system("CLS"); // on Windows

        int r = rand() % tree.size();
        int c = rand() % tree.at(r).size();

        if (tree[r][c] == '.'){ // toggle lights
            tree[r][c] = '*'; 
        } else if (tree[r][c] == '*'){ 
            tree[r][c] = '.'; 
        }

        printTree();

        //usleep(50000); // on Mac OS
        Sleep(20); // on Windows
    }
}

// hiding blinking cursor for Windows
// (https://stackoverflow.com/questions/18028808/blinking-underscore-with-console)
void ShowConsoleCursor(bool showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void printTree(){
    for (int layer = 0; layer < tree.size(); layer++){
        for (int light = 0; light < tree.at(layer).size(); light++){
            cout << tree[layer][light];
        }
        cout << endl;
    }
}

void drawLayered(){
    int layers = enterNumber("layers") * 2;
    int depth = enterNumber("depth of each layer") * 2;

    for (int m = 0; m < layers; m+=2){
        for (int i = 1; i <= depth; i+=2){
            for (int k = (depth * layers/2 - i)/2 - m/2; k > 0; k--){
                cout << " ";
            }
            int j;
            for (j = 1; j <= (i + m); j++){
                cout << "^";
            }
            cout << endl;
        }
    }
}

void drawTriangle(){
    int levels = enterNumber("levels") * 2;
    for (int i = 1; i <= levels; i+=2){
        for (int k = (levels - i)/2; k > 0; k--){
            cout << " ";
        }
        for (int j = 1; j <= i; j++){
            cout << "^";
        }
        cout << endl;
    }
}

int enterNumber(string qualifier){
    int num;
    cout << "Enter a number (" << qualifier << "): ";
    cin >> num;
    return num;
}