#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

template<typename Out>
void split(const string &s, char delim, Out result) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        *(result++) = item;
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}

void print(vector<string> words){
    for (string word : words){
        cout << word << endl;
    }
}

int main(){
    string lyric = "Come on, come on, turn the radio on/ It's Friday night and I won't be long.";
    vector<string> x = split(lyric, ' ');
    print(x);
    return 0;
}