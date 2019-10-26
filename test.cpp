#include <iostream>
#include <string>
using namespace std;
// CS 102 HW 09/26/2018 
string to_base (int num, int base)
{

string bases = "0123456789ABCDEF";
string result = "";

 while( num > 0){
        result = bases [ num%base] + result;
        num /=base;
    }
return result;
}

int main()
{
    int n,b;
    char response;

    cout << " Enter the number:";
    cin >> n;
    cout << " Enter the Base:" ;
    cin >> b;
    cout << " Is " << n << " in to " << b <<  " Y/N " << endl;
    cin >> response; 
    if (response == 'Y')
{
    cout << " Answer: " << to_base(n,b) << endl;
}
    else if (response == 'N')
    {
        cout << " Sorry, try again! " << endl;
    }


return 0;
}