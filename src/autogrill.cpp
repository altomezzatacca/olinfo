#include <bits/stdc++.h>
using namespace std;
set<long long> S;

void inizia() {
    return;
}

void apri(long long p) {
    S.insert(p);
    return;
}

void chiudi(long long p) {
    S.erase(p);
    return;
}

long long chiedi(long long p) {
    if(S.count(p)) return p;
    auto it = S.upper_bound(p);
    long long n = -1;
    if(it != S.end()) n = *it;
    if(it != S.begin()){
        it--;
        if(n == -1 || abs(*it - p) < abs(n - p))
            n = *it;
    }
    return n;
}
