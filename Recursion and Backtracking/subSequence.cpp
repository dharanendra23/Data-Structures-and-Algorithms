#include<bits/stdc++.h>
using namespace std;

void subSequence(string str, string otpString){
    if(str.size() == 0){
        cout << otpString << endl;
        return;
    }

    subSequence(str.substr(1), otpString + str.substr(0,1));
    subSequence(str.substr(1), otpString);
}

int main(){
    string str = "abc";

    subSequence(str, "");

    return 0;
}