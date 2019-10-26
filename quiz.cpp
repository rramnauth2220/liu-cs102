#include <iostream>
#include <string>

using namespace std;

void collectInputs();
void isConfirmed(int val, int base);
bool isValid(int val, int base);
void convertBase(int val, int base);

int main(){
    /*cout << "-------------------------------" << endl;
    cout << " Base 10 --> Base X Converter  " << endl;
    cout << "-------------------------------" << endl;

    string base, val; 
    cout << "Value to convert: ";
    getline(cin, val);
    cout << "Base to convert " << val << " into: ";
    getline(cin, base);

    string ans = "";

    int intVal = stoi(val);
    int intBase = stoi(base);
    while (intVal > 0) {
        cout << intVal << "/" << intBase << " = " << intVal/intBase << " with remainder of " << intVal%intBase << endl;
        ans = to_string(intVal%intBase) + " " + ans;
        intVal = intVal/intBase;
    }
    cout << "Answer: " << ans << endl; 
*/
    collectInputs();
}

/* collect console inputs for value and base*/
void collectInputs(){
    string base, val; 
    cout << "Value to convert: ";
    getline(cin, val);
    cout << "Base to convert " << val << " into: ";
    getline(cin, base);

    int intVal = stoi(val); // stoi converts a string into an int
    int intBase = stoi(base);

    bool moveOn = isValid(intVal, intBase);
    if (moveOn)
        isConfirmed(intVal, intBase);
}

/* check if user input is valid */
bool isValid(int val, int base){
    // check if val is a legal value i.e. integer and positive
    // check if base is a legal value i.e. integer and positive
    if (val >= 0 && base >= 1)
        return true;
    else {
        cout << "Invalid inputs. Try again." << endl;
        collectInputs();
        return false;
    }
}

/* ask for user confirmation before computing*/
void isConfirmed(int val, int base){
    string confirmed;
    cout << "Confirm: convert " << val << " in base 10 into base " << base << " (Y/N)? ";
    getline(cin, confirmed);

    if (confirmed.find('N') != -1){
        collectInputs();
    }
    else {
        convertBase(val, base);
    }
}

// recursive implementation
void convertBase(int val, int base){
    /*
        1. Divide the number by the base
        2. Store the remainder
        3. Repeat the process with the whole number part of division
        4. Stop when you reach zero
        5. Answer = remainders in reverse order
    */
   if (val > 0){
        int wholeDivide = val/base;
        cout << val << " / " << base << " = " << wholeDivide << ", remainder " << val % base << endl;
        convertBase(wholeDivide, base);
   }

   cout << val % base;
}