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
int backtrack(int v[9][9], int c, int result,int x, int y,int ans[9][9]) {
    int tmp1 =x+1, tmp2 = y+1;
    if(result >= 2)return 2;
    if(c == 81) {
        result++;
        loopi {
            loopj {
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
                result = backtrack(v, c+1, result, (x<8)?tmp1:0,(x<8)?y:tmp2, ans);
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
    int v[9][9], ans[9][9];
    sudoku solve;
    int count = 0;
    loopi {
        loopj {
            cin >> v[i][j];
            if(v[j][i] != 0)count++;
            //scanf("%d", &v[i][j]);
        }
    }
    if(count < 17){
        cout << 0 << '\n';
        return 0;
    }
    int c = 0;
    int result = 0;
    int x = 0, y = 0;
    result = backtrack(v, c, result, x, y, ans);
    if(result == 1) {
        cout << 1 << '\n';
        solve.printout(ans);
    } else cout << result << '\n';
    return 0;
}
