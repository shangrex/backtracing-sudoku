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

int backtrack(int c, int result,int x, int y) {

    if(result == 2)return 2;
    if(c == 81) {
        result++;
        memcpy(ans, v,sizeof(int) * 81);
        return result;
    }

    //solve
    if(v[y][x] != 0) {
        result = backtrack(c+1, result, (x<8)?x+1:0,(x<8)?y:y+1);
    } else {
        //elemination
        int row[10] = {0}, col[10] = {0}, matrix[10] = {0};

        loopi{
            row[v[y][i]]++;
            col[v[i][x]]++;
        }
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                matrix[v[y/3*3+i][x/3*3+j]]++;
            }
        }


        for(int k = 1; k < 10; k++) {
            if(!row[k] && !col[k] && !matrix[k]) {
                v[y][x] = k;
                result = backtrack(c+1, result, (x<8)?x+1:0,(x<8)?y:y+1);
                if(result == 2)return 2;
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
    int count = 0;
    loopi {
        loopj {
            cin >> v[i][j];
            //if(v[i][j] != 0)count++;
            //scanf("%d", &v[i][j]);
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
