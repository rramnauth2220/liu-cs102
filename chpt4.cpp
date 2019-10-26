#include <iostream>
#include <string>

using namespace std;

int main() {
    //switch statements

    int bookOption = 0;
    cout << "This switch statement will print: ";
    switch(bookOption){ // pass int expression
        case 0: // like an if(bookOption == 1)
            cout << "Harry Potter" << endl;
            break;
        case 2:
            cout << "Hunger Games" << endl;
            break;
        case 3:
            cout << "Don't read. Watch a movie!" << endl;
            break;
        default:  //like the else statement
            cout << "Read your CS textbook" << endl;
    }

    cout << "The if-elseif-else statements will print: ";
    if (bookOption == 0){
        cout << "Harry Potter" << endl;
    } else if (bookOption == 2){
        cout << "Hunger Games" << endl;
    } else if (bookOption == 3){
        cout << "Don't read. Watch a movie!" << endl;
    } else {
        cout << "Read your CS textbook" << endl;
    }

    bookOption = 10;
    string bookToRead = (bookOption) ? "Harry" : "Not Harry";
    cout << "Ternary Operator prints: " << bookToRead;
}