#include<iostream>
#include<string>
#include <chrono>
#include <thread>

using namespace std;

const char rocket[] =
"           _\n\
          /^\\\n\
          |-|\n\
          | |\n\
          |N|\n\
          |A|\n\
          |S|\n\
          |A|\n\
         /| |\\\n\
        / | | \\\n\
       |  | |  |\n\
        `-\"\"\"-`\n\
";

int main()
{
    for (int i = 0; i < 50; i++) 
        cout << "\n";
    printf("%s", rocket);
    int j = 300000;
    for (int i = 0; i < 50; i++){
        sleep_for(10ns);
        j = (int)(j * 0.9);
        printf("\n");
    }
    return 0;
}