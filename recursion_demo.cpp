#include <iostream>

using namespace std;

int getFactorialRecursively(int number){
    int factorial;
    if (number == 1) // this base case tells the recursive function when to stop
        factorial = 1;
    else 
        factorial = getFactorialRecursively(number - 1) * number; // recursive because it calls itself
    return factorial;
}

int main() {
    cout << getFactorialRecursively(5);
    return 0;
}