#include <iostream>

using namespace std;

int sayForever(){
    cout << "Hello World " << endl;
    sayForever();
    return 0;    
}

int main() {
    sayForever();
}
