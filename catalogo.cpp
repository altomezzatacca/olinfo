#include <bits/stdc++.h>
using namespace std;
map<long long, long long> m;

void aggiungi(long long int id) {
    m[id]++;
}

void togli(long long int id) {
    m[id]--;
}

int conta(long long int id) {
    return m[id];
}