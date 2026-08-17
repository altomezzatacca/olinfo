#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; cin >> n;
    vector<int> v(n);
    for(auto &u: v) cin >> u;
    vector<int> pari(n), dispari(n);
    v[0] % 2 == 0 ? pari[0]++ : dispari[0]++;
    for (int i = 1; i < n; i++) {
        pari[i] = pari[i - 1];
        dispari[i] = dispari[i - 1];
        v[i] % 2 == 0 ? pari[i]++ : dispari[i]++;
    }
    vector<int> ans;
    if (pari[n - 1] - pari[0] == dispari[n - 1] - dispari[0]) ans.emplace_back(v[0]);
    for (int i = 1; i < n; i++)
        if ((pari[i - 1] == dispari[i - 1]) && (pari[n - 1] - pari[i] == dispari[n - 1] - dispari[i]))
         ans.emplace_back(v[i]);
    cout << (int)ans.size() << "\n";
    for (auto u: ans) cout << u << " ";
    cout << "\n";
}
