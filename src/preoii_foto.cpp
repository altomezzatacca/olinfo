#include "bits/stdc++.h"
using namespace std;

bool heights(int N, vector<int> Z, vector<int> &H) {
    int &n = N;
    if (n == 2) {
        H = {Z[0], Z[0]};
        return 1;
    }
    vector<int> verse(n - 2);
    for (int i = 0; i < n - 2; i++) {
        if (Z[i] < Z[i + 1]) verse[i] = 0;
        if (Z[i] == Z[i + 1]) verse[i] = 1;
        if (Z[i] > Z[i + 1]) verse[i] = 2;
    }
    for (int i = 0; i < n - 3; i++)
        if (verse[i] == 0 && verse[i + 1] == 2)
            return false;
    for (int i = 0; i < n - 2; i++) {
        if (Z[i] > Z[i + 1])
            H[i] = Z[i];
        if (i > 0 && Z[i] == Z[i + 1] && Z[i] == Z[i - 1])
            H[i] = Z[i];
        if (i > 0 && Z[i - 1] < Z[i] && Z[i] < Z[i + 1])
            H[i + 1] = min(Z[i], Z[i + 1]);
        if (i > 0 && Z[i - 1] > Z[i] && Z[i] < Z[i + 1])
            H[i + 1] = min(Z[i], Z[i + 1]);
        if (i > 0 && Z[i - 1] == Z[i] && Z[i] < Z[i + 1])
            H[i] = min(Z[i], Z[i + 1]);
    }
    if (Z[0] > Z[1])
        H[0] = Z[0];
    else
        H[1] = Z[0];
    if (Z[n - 2] > Z[n - 3])
        H[n - 1] = Z[n - 2];
    else
        H[n - 2] = Z[n - 2];
    return true;
}
