#include<bits/stdc++.h>
using namespace std;
//x agisce sulla colonna (max: R)
//y agisce sulla riga (max : C)
//terreno è di dimensioni [R][C]

void scavi(int R, int C, int Q, vector<int> &x1, vector<int> &y1, vector<int> &x2, vector<int> &y2, vector<int> &P, vector<vector<int>> &terreno){
	vector<vector<int>> offset (R + 1, vector<int> (C + 1));
    //O(Q + RC)
    for(int q = 0; q < Q; q++){
        offset[x1[q]    ][y1[q]    ] += P[q];
        offset[x2[q] + 1][y1[q]    ] -= P[q];
        offset[x1[q]    ][y2[q] + 1] -= P[q];
        offset[x2[q] + 1][y2[q] + 1] += P[q];
    }
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            if(r > 0) offset[r][c] += offset[r - 1][c];
            if(c > 0) offset[r][c] += offset[r][c - 1];
            if(r > 0 && c > 0) offset[r][c] -= offset[r - 1][c - 1];
            terreno[r][c] = offset[r][c];
        }
    }
}
