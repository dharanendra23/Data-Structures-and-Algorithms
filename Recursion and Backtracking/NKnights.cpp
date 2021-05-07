#include<bits/stdc++.h>
using namespace std;
#define vvb vector<vector<bool> >

int countKnights = 0;

void display(vvb &grid, int n) {

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {
            
            if(grid[i][j]) {

                cout << "K\t";
            }else {

                cout << "-\t";
            }
        }
        cout << endl;
    }

    cout << "\n\n";
}

bool isItSafe(vvb &grid, int r, int c, int n) {

    if(r - 2 >= 0 and c - 1 >= 0 and grid[r - 2][c - 1]) return false;
    if(r - 1 >= 0 and c - 2 >= 0 and grid[r - 1][c - 2]) return false;
    if(r - 2 >= 0 and c + 1 < n and grid[r - 2][c + 1]) return false;
    if(r - 1 >= 0 and c + 2 < n and grid[r - 1][c + 2]) return false;

    return true;
}

void nKnights(vvb &grid, int cr, int cc, int count, int n) {

    if(count == n) {

        countKnights++;
        display(grid, n);
        return;
    }

    for(int i = cr; i < n; i++) {
        
        for(int j = (i == cr) ? cc : 0; j < n; j++) {

            if(isItSafe(grid, i, j, n)) {

                grid[i][j] = true;
                nKnights(grid, i, j + 1, count + 1, n);
                grid[i][j] = false;
            }
        }
    }

}

int main() {

    int n = 2;
    vvb grid(n, vector<bool> (n, false));

    nKnights(grid, 0, 0, 0, n);

    cout << countKnights << endl;

    return 0;
}