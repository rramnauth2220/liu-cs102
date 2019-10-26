#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int x = 10;
int addNumbers(int firstNum, int secondNum = 0); //function prototype with a param with a default value of 0
double addNumbers(double firstNum, double secondNum); // function overloading (same name, different params)
int addNumbers(int firstNum, int secondNum, int thirdNum);
int getFactorial(int number);
int getFactorialRecursively(int number);

int main() {
    int x = 4; 
    
    cout << "Global var x = " << ::x << endl;
    cout << "Local var x = " << x << endl;
    
    cout << "-----------------------------------" << endl;
    cout << "              ARRAYS               " << endl;
    cout << "-----------------------------------" << endl;
    // arrays store multiple values of the same data type, like baskets
    
    int luckyNums[5]; // says that this "basket" called luckyNums can hold only 5 integers
    
    int unluckyNums[5] = {4, 6, 1, 9, 78}; // these are the integers in my "basket" called unluckyNums
    
    cout << "First unlucky number = " << unluckyNums[0] << endl;
    cout << "Second unlucky number = " << unluckyNums[1] << endl;
    cout << "Last unlucky number = " << unluckyNums[4] << endl;

    // MULTIDIMENSIONAL ARRAYS means baskets of baskets
    char name[2][5] = {{'B', 'e', 'c', 'k', 'y'},
                        {'R', 'a', 'm', 'e', 'n'}};
    
    // name[index of first array][index of second array]
    cout << "2nd letter in the 2nd array: " << name[1][1] << endl;
    cout << "1st letter in the 1st array: " << name[0][0] << endl;
    cout << "Last letter in the last array: " << name[1][4] << endl;

    name[0][4] = 'i'; // changing last letter of first array to 'i'
    cout << "Last letter in the 1st array: " << name[0][4] << endl;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            cout << name[i][j];
        }
        cout << " ";
    } cout << endl;
    
    cout << "-----------------------------------" << endl;
    cout << "             VECTORS               " << endl;
    cout << "-----------------------------------" << endl;
    // just like arrays, except their size could change

    vector <int> lotteryNumVect(10); // initializes vector with 10 zeros
    int lotteryNumArray[5] = {4, 13, 14, 24, 34};
    // at the beginning of vector, insert elements 0, 1, and 2 of array
    lotteryNumVect.insert(lotteryNumVect.begin(), lotteryNumArray, lotteryNumArray+3);
    for (int i = 0; i < lotteryNumVect.size(); i++){
        cout << "Value at index " << i << " = " << lotteryNumVect.at(i) << endl;
    }

    lotteryNumVect.insert(lotteryNumVect.begin()+5, 44); //add number 44 to vector at index 5
    cout << "Item at index 5 = " << lotteryNumVect.at(5) << endl;
    
    lotteryNumVect.push_back(64); // insert number 64 to the end of the vector
    
    cout << "Last value = " << lotteryNumVect.back() << endl; // get last/back element
    cout << "First value = " << lotteryNumVect.front() << endl; // get first/front element
    cout << "Is the vector empty? " << lotteryNumVect.empty() << endl; // returns an int (0 = false, 1 = true)
    cout << "Size of vector = " << lotteryNumVect.size() << endl; // how many elements?
    
    lotteryNumVect.pop_back(); // removes last element
    cout << "New size of vector = " << lotteryNumVect.size() << endl; // size has decreased by 1

    cout << "-----------------------------------" << endl;
    cout << "           FUNCTIONS               " << endl;
    cout << "-----------------------------------" << endl;

    cout << "5 + 3 = " << addNumbers(5, 3) << endl;
    cout << "5 + 0 = " << addNumbers(5, 0) << endl;
    cout << "5 = " << addNumbers(5) << endl;
    

    cout << "5.6 + 1.5 = " << addNumbers(5.6, 1.5) << endl;
    //cout << "5.6 + 2 = " << addNumbers(5.6, 2) << endl; //does not work, 2nd param is a int, expecting a double

    cout << "5 + 3 + 2 = " << addNumbers (5, 3, 2) << endl;
    cout << "5 + 3 + 0 = " << addNumbers (5, 3, 0) << endl;

    cout << "8! = " << getFactorial(8) << endl;
    cout << "5! = " << getFactorial(5) << endl;
    cout << "0! = " << getFactorial(0) << endl;

    cout << "8! = " << getFactorialRecursively(8) << endl;
    cout << "5! = " << getFactorialRecursively(5) << endl;
    cout << "0! = " << getFactorialRecursively(0) << endl;
    return 0;
}

int addNumbers(int firstNum, int secondNum){
    return firstNum + secondNum;
}

double addNumbers(double firstNum, double secondNum){
    return firstNum + secondNum;
}

int addNumbers(int firstNum, int secondNum, int thirdNum){
    return firstNum + secondNum + thirdNum;
}

int getFactorial(int number){
    int num = number;
    int factorial = 1;
    while(num > 0){
        factorial = factorial * num; 
        num--;
    }
    return factorial;
}

int getFactorialRecursively(int number){
    int factorial;
    if (number == 1) // this base case tells the recursive function when to stop
        factorial = 1;
    else 
        factorial = getFactorial(number - 1) * number; // recursive because it calls itself
    return factorial;

    /* behind the scenes of getFactorialRecursively(5):
            getFactorialRecursively(5) --> else statement --> getFactorialRecursively(4) * 5
            getFactorialRecursively(4) --> else statement --> getFactorialRecursively(3) * 4
            getFactorialRecursively(3) --> else statement --> getFactorialRecursively(2) * 3
            getFactorialRecursively(2) --> else statement --> getFactorialRecursively(1) * 2
            getFactorialRecursively(1) --> if statement --> 1 

        Now we know: 
            getFactorialRecursively(2) = getFactorialRecursively(1) * 2 = 1 * 2
            getFactorialRecursively(3) = getFactorialRecursively(2) * 3 = 1 * 2 * 3
            getFactorialRecursively(4) = getFactorialRecursively(3) * 4 = 1 * 2 * 3 * 4
            getFactorialRecursively(5) = getFactorialRecursively(4) * 5 = 1 * 2 * 3 * 4 * 5

        Therefore:
            getFactorialRecursively(5) = 1 * 2 * 3 * 4 * 5 = 120
    */
}