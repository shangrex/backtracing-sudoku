//#include<stdio.h>
//#include<stdlib.h>
#include<iostream>
#include<stack>
#include<cstring>
#include<vector>
#include"sudoku.h"
#define loopi for(int i=0;i<9;i++)
#define loopj for(int j=0; j<9;j++)
//#include<bits/stdc++.h>
//#include "sudoku.h"
using namespace std;
int printout(int v[9][9]);
int backtrack(int v[9][9], int c, int result,int x, int y,int ans[9][9]) {
    int tmp1 =x+1, tmp2 = y+1;
    if(result >= 2)return 2;
    if(c == 81) {
        result++;
        for(int i = 0; i < 9; i ++) {
            for(int j = 0; j < 9; j++) {
                ans[i][j] = v[i][j];
            }
        }
        return result;

    }

    //solve
    if(v[y][x] != 0) {
        result = backtrack(v, c+1, result, (x<8)?tmp1:0,(x<8)?y:tmp2, ans);
    } else {
        //elemination
        int row[10], col[10], matrix[10];
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(matrix,0,sizeof(matrix));
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
                result = backtrack(v, c+1, result, (x<8)?tmp1:0,(x<8)?y:tmp2, ans);
                if(result == 2)return 2;
                v[y][x] = 0;
            }
        }
    }

    return result;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v[9][9], ans[9][9];
    sudoku solve;

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> v[i][j];
        }
    }
    int c = 0;
    int result = 0;
    int x= 0, y = 0;
    result = backtrack(v, c, result, x, y, ans);
    if(result == 1) {
        cout << 1 << '\n';
        solve.printout(ans);
    } else cout << result << '\n';


    return 0;
}




