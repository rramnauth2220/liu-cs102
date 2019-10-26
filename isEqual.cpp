#include <iostream>
#include <vector>

using namespace std;

bool isAllEqual(vector<int> v); // prototype
bool equalRecursive(int num, vector<int> v); // prototype

int main() {
  vector<int> v = {0, 1, 0, 1, 23};
  //cout << isAllEqual(v);
  cout << equalRecursive(v.at(v.size() - 1), v);
  return 0;
}

bool equalRecursive(int num, vector<int> v) {
    if (v.size() <= 0) { // base case
        return true;
    } else {
        int n = v.at(v.size() - 1);
        v.pop_back();
        cout << "n = " << n << endl;
        return (n == equalRecursive(num, v));
    }
}

bool isAllEqual(vector<int> v) {
    int num = v.at(0); // track the first num
    for (int i = 1; i < v.size(); i++){
        if (v.at(i) != num){
            return false; 
        }
    }
    return true;
}