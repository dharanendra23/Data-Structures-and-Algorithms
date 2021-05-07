#include<bits/stdc++.h>
using namespace std;

int countQueens = 0;

void display(vector<vector<bool> > &grid, int n) {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j]) {

                cout << "Q\t";
            }else {

                cout << "-\t";
            }
        }
        cout << endl;
    }
}

// Not optimised

// bool isItSafe(vector<vector<bool> > &grid, int row, int col, int n) {

//     // for column
//     for(int i = row - 1; i >= 0; i--) {

//         if(grid[i][col]) return false;
//     }

//     // upper-left diagonal
//     for(int i = row - 1, j = col - 1; i >= 0 and j >=0; i--, j--) {

//         if(grid[i][j]) return false;
//     }

//     // upper-right diagonal
//     for(int i = row - 1, j = col + 1; i >=0 and j < n; i--, j++) {

//         if(grid[i][j]) return false;
//     }

//     return true;
// }

// void nQueens(vector<vector<bool> > &grid, int cur_row, int n) {

//     if(cur_row == n) {
        
//         countQueens++;
//         display(grid, n);
//         cout<<"\n";
//         return;
//     }

//     for(int i = 0; i < n; i++) {

//         if(isItSafe(grid, cur_row, i, n)) {

//             grid[cur_row][i] = true;
//             nQueens(grid, cur_row + 1, n);
//             grid[cur_row][i] = false;
//         }
//     }
// }

// optimised

bitset<100> col, leftDiagnl, rightDiagnl;

void nQueens(vector<vector<bool> > &grid, int cur_row, int n) {

    if(cur_row == n) {

        display(grid, n);
        cout << endl;
        return;
    }

    for(int c = 0; c < n; c++) {

        if(!col[c] and !leftDiagnl[cur_row - c + n -1] and !rightDiagnl[cur_row + c]) {
            col[c] = leftDiagnl[cur_row - c + n -1] = rightDiagnl[cur_row + c] = 1;
            grid[cur_row][c] = true;
            nQueens(grid, cur_row + 1, n);
            col[c] = leftDiagnl[cur_row - c + n -1] = rightDiagnl[cur_row + c] = 0;
            grid[cur_row][c] = false;
        }
    }
}

int main() {

    int n = 4;
    vector<vector<bool> > grid(n, vector<bool> (n, false));

    if(n != 1 and n < 4) cout<<"Not Possible"<<endl;
    nQueens(grid, 0, n);

    //cout << countQueens << endl;

    return 0;
}