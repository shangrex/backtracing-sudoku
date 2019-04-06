//#include<stdio.h>
//#include<stdlib.h>
#include<iostream>
#include<stack>
#include<cstring>
#include<vector>
#include"sudoku.h"
#include<stdio.h>
#define loopi for(int i=0;i<9;i++)
#define loopj for(int j=0;j<9;j++)
//#include<bits/stdc++.h>
//#include "sudoku.h"
using namespace std;
int v[9][9], ans[9][9];
int row[9][10] = {0}, col[9][10] = {0}, matrix[9][10] = {0};

int backtrack(int c, int result,int x, int y) {

    if(result == 2)return 2;
    if(c == 81) {
        result++;
        loopi {
            loopj {
                ans[i][j] = v[i][j];
            }
        }
        //memcpy(ans, v,sizeof(int) * 81);
        return result;
    }

    //solve
    if(v[y][x] != 0) {
        result = backtrack(c+1, result, (x<8)?x+1:0,(x<8)?y:y+1);
    } else {
        //elemination

        for(int k = 1; k < 10; k++) {
            if(!row[y][k] && !col[x][k] && !matrix[(y/3)*3+(x/3)][k]) {
                v[y][x] = k;
                row[y][k] = 1;
                col[x][k] = 1;
                matrix[(y/3)*3+(x/3)][k] = 1;
                result = backtrack(c+1, result, (x<8)?x+1:0,(x<8)?y:y+1);
                if(result == 2)return 2;
                row[y][k] = 0;
                col[x][k] = 0;
                matrix[(y/3)*3+(x/3)][k] = 0;
                v[y][x] = 0;
            }
        }
    }

    return result;

}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    sudoku solve;
    loopi {
        loopj {
            cin >> v[i][j];
            //if(v[i][j] != 0)count++;
            //scanf("%d", &v[i][j]);
        }
    }
    loopi {
        loopj {
            if(v[i][j] != 0) {
                row[i][v[i][j]] = 1;
                col[j][v[i][j]] = 1;
                matrix[(i/3)*3+(j/3)][v[i][j]] = 1;

            }
        }
    }

    int c = 0;
    int result = 0;
    int x = 0, y = 0;
    result = backtrack(c, result, x, y);
    if(result == 1) {
        cout << 1 << '\n';
        solve.printout(ans);
    } else cout << result << '\n';
    return 0;
}
