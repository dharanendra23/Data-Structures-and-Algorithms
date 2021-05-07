#include <bits/stdc++.h>
#include <string>
using namespace std;

void codesOfString(string str, string otpString, char *code)
{
    if (str.size() == 0)
    {
        cout << otpString << endl;
        return;
    }

    int oneDigitNum = str[0] - '0';
    int twoDigitNum;
    
    codesOfString(str.substr(1), otpString + code[oneDigitNum], code);
    
    if(str.size() >= 2){
        twoDigitNum = stoi(str.substr(0, 2));
        
        if(twoDigitNum <= 26){
             
            codesOfString(str.substr(2), otpString + code[twoDigitNum], code);
        }
    }
}

int main()
{
    char code[27] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                     'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    string str = "123";
    //cin >> str;

    codesOfString(str, "", code);

    return 0;
}
