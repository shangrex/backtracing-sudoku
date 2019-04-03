#include<iostream>
#include"sudoku.h"
#define loopi for(int i=0;i<9;i++)
#define loopj for(int j=0; j<9;j++)
#include<algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v[9][9], u[9][9];
    int n;
    int x, y;
    sudoku t;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> v[i][j];
        }
    }
    loopi{
        loopj{
            u[i][j] = v[i][j];
        }
    }
    cin >> n;
    while(1) {
        if(n == 0)break;
        if(n == 1) {
            cin >> x >> y;
            loopi{
                loopj{
                    if(v[i][j] == x)u[i][j] = y;
                    if(v[i][j] == y)u[i][j] = x;
                }
            }

        }
        //row
        if(n == 2) {
            cin >> x >> y;
            for(int i = 0; i < 3; i++) {
                loopj{
                    swap(v[i+x*3][j], v[i+y*3][j]);
                }
            }
            loopi{
                loopj{
                    u[i][j] = v[i][j];
                }
            }

        }
        //col
        if(n == 3) {
            cin >> x >> y;
            loopi{
                for(int j = 0; j < 3; j++) {
                    swap(v[i][j+x*3], v[i][j+y*3]);
                }
            }
            loopi{
                loopj{
                    u[i][j] = v[i][j];
                }
            }
        }
        //rotate
        if(n == 4) {
            cin >> x;
            while(x--) {
                loopi{
                    loopj{
                        u[j][8-i] = v[i][j];
                    }
                }
            }
        }
        if(n == 5) {
            cin >> x;
            //x=1 up down flip
            if(x == 0) {
                loopj{
                    for(int i = 0; i < 4; i++) {
                        swap(v[i][j], v[8-i][j]);
                    }
                }
            }
            //right left flip
            if(x == 1) {
                loopi{
                    for(int j = 0; j < 4; j++) {
                        swap(v[i][j], v[i][8-j]);
                    }
                }
            }
            loopi{
                loopj{
                    u[i][j] = v[i][j];
                }
            }
        }
        loopi{
            loopj{
                v[i][j] = u[i][j];
            }
        }
        cin >> n;
    }
    /*
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << v[i][j];
            if(j!=8)cout << ' ';
        }
        cout << '\n';
    }
    */
    t.printout(v);
    return 0;
}
