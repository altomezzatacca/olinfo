#include "bits/stdc++.h"
using namespace std;
// ordino per s decrescente
// indici i < j: se p[i] < p[j] allora j domina i

vector<int> count(int N, vector<int> S, vector<int> P) {
    int &n = N;
    vector<int> c(N);
    vector<int> idx(n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](int a, int b){
        return S[a] > S[b];
    });
    int tot = 1; // numero di materiali mai dominati
    array<pair<int, int>, 2> min_p;
    vector<int> in(n);
    map<int, int> m;
    min_p[0] = {P[idx[0]], idx[0]};
    min_p[1] = {P[idx[1]], idx[1]};
    if (P[idx[1]] < P[idx[0]]) {
        tot++;
        swap(min_p[0], min_p[1]);
    } else {
        in[idx[1]] = 1;
        m[idx[0]]++;
    }
    for (int i = 2; i < n; i++) {
        int p = P[idx[i]];
        if (p < min_p[0].first) {
            tot++;
            min_p[1] = min_p[0];
            min_p[0] = {p, idx[i]};
        } else if (p < min_p[1].first && p > min_p[0].first) {
            in[idx[i]] = 1;
            m[min_p[0].second]++;
            min_p[1] = {p, idx[i]};
        } else // p > min_p[1]
            in[idx[i]] = 2;
    }
    for (int k = 0; k < n; k++) {
        c[k] = tot;
        if (in[k] == 0) c[k]--;
        c[k] += m[k];
    }
    return c;
}
