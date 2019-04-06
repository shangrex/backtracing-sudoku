#include<iostream>
#include<stdio.h>
#include"sudoku.h"
using namespace std;
int sudoku::printout(int v[9][9]) {

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << v[i][j];
            //printf("%d",v[i][j]);
            if(j!=8)cout << ' ';
        }
        cout << '\n';
    }
    //cout << '\n';
    return 0;
}
