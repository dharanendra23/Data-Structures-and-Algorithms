#include <bits/stdc++.h>
using namespace std;

// Recusrsion
// void permutations(string str, string osf)
// {

//     if (str.size() == 0)
//     {
//         cout << osf << endl;
//         return;
//     }

//     unordered_set<char> s;

//     for (int i = 0; i < str.size(); i++)
//     {
//         char ch = str[i];
//         if (s.count(ch) == 0)
//         {
//             string ros = str.substr(0, i) + str.substr(i + 1);
//             s.insert(ch);
//             permutations(ros, osf + ch);
//         }
//     }
// }

// Backtracking
void permutations(string str, int i) {

    if(i == str.size()-1) {
        cout << str << endl;
        return;
    }

    for(int j = i; j < str.size(); j++) {
        swap(str[i], str[j]);
        permutations(str, i+1);
        swap(str[i], str[j]);
    }
}

int main()
{

    string str = "ABC";
   
    permutations(str,0);

    return 0;
}