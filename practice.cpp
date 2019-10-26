#include <iostream>

using namespace std;

int main() {
    char sym = 'a';
    cout << "Enter a character: ";
    cin >> sym;

    if (sym == 'a' || sym == 'e' || sym == 'i' || sym == 'o' || sym == 'u') {
        cout << sym << " is a vowel." << endl;
    }
    return 0;
}