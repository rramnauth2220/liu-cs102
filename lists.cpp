#include <string>
#include <iostream>
#include <vector> 

using namespace std;

int main() {
    // VECTORS
    vector<int> lotteryNums;
    
    cout << "Is vector empty? : " << lotteryNums.empty() << endl;
    
    for (int i = 0; i < lotteryNums.size(); i++) {
        cout << "At index " << i << ", number = " << lotteryNums.at(i) << endl; 
    }


    return 0;
}