#include "bits/stdc++.h"
using namespace std;

bool ordina(int N, vector<int> V, vector<int> &L) {
    int &n = N;
    int l = 0, r = 1, h = V[0], last_h = -1;
    while (r <= n) {
        if (r == n || V[r] > h) { // non posso prolungare l'intervallo da flippare
            if (V[r - 1] < last_h) // il minimo di questo intervallo è minore del massimo dell'intervallo prima
                return false;
            L.emplace_back(r - l);
            last_h = V[l];
            if (r < n) h = V[r];
            l = r;
        } else {
            h = V[r];
        }
        r++;
    }
    return true;
}
