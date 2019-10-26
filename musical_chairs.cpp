#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

using namespace std;

string getString();
bool determinePalindrome(string s);
vector<int> parseString(string s);
int getSum(vector<int> v);
int getNumber();
bool determinePrime(int num);
int getNthFib(int num);
vector<string> getCombinations(string num);
void printVector(vector<string> stringVector);
bool validStrangeString(string s);

int main(){
  //cout << determinePalindrome(getString());
  //cout << getSum(parseString(getString()));
  //cout << determinePrime(getNumber());
  //cout << getNthFib(getNumber());
  //printVector(getCombinations(getString()));
  cout << validStrangeString(getString());
  return 0;
}
 
/* // work on acc?7??sss?3 case
bool validStrangeString(string s){
  bool lookNumber = true;
  int question = 3;
  for (int i = 0; i < s.size(); i++){
    if ((int)(s.at(i)) >= 48 && (int)(s.at(i)) <= 57){
      cout << "at i=" << i << " found #, question = " << question << endl;
      lookNumber == false;
      if (question != 3){
        return false;
      } else {
        question = 0;
      }
    }
    else if (!lookNumber && s.at(i) == '?'){
      cout << "at i=" << i << " found ?" << endl;
      question++;
    }
  }
  return true;
}
*/
vector<string> getCombinations(string s){
  vector<string> numbers(0);
  string newNumber = "";
  for (int i = 0; i < s.size(); i++){
    newNumber += s.at(i); 
    for (int j = 0; j < s.size(); j++){
        if (i != j){
          newNumber+= s.at(j);
        }
    }
    numbers.push_back(newNumber);
    newNumber = "";
  }
  return numbers;
}

void printVector(vector<string> stringVector){
  for (int i = 0; i < stringVector.size(); i++){
    cout << stringVector.at(i) << endl;
  }
}

int getNthFib(int num){
  vector<int> sequence(0);
  sequence.push_back(1);
  sequence.push_back(1);
  if (num <= 2){
    return 1;
  } else {
    for (int i = 1; i < num - 1; i++){
      sequence.push_back(sequence.at(i) + sequence.at(i - 1));
      cout << sequence.at(i + 1) << " ";
    }
  }
  cout << endl;
  return sequence.at(sequence.size() - 1);
}

bool determinePrime(int num){
  int number = num;
  for (int i = number - 1; i > 1; i--) { // can we make this more efficient?
    if (number % i == 0){
      return false;
    }
  }
  return true;
}

int getNumber() {
  int num;
  cout << "Enter a number: ";
  cin >> num;

  return num;
}

int getSum(vector<int> v){
  int sum = 0;
  for (int i = 0; i < v.size(); i++){
    sum += v.at(i);
  }
  return sum;
}

vector<int> parseString (string str){
  vector<int> v(0);
  string s = str + " ";
  string nextNumber = "";
  for (int i = 0; i < s.size(); i++) {
    if (s.at(i) == ' '){
      v.push_back(stoi(nextNumber));
      nextNumber = "";
    } else {
      nextNumber += s.at(i);
    }
  }
  return v;
}

string getString(){
  string userinput;
  cout << "Enter a string: ";
  getline(cin, userinput);

  return userinput;
}

bool determinePalindrome(string s){
  string s_backwards = "";
  for (int i = s.size()-1; i >= 0; i--){
    cout << i << ": " << s.at(i) << endl;
    s_backwards += s.at(i);
  }
  if (s_backwards == s){
    return true;
  } else {
    return false;
  }
}