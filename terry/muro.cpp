#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int N, Q;
    cin >> N >> Q;
    vector<int> L(Q);
    for (int i = 0; i < Q; i++) 
        cin >> L[i];
    int ix = 0; // slot dove scrivo il prossimo colore
    for(int i = 0; i < Q; i++){
        if(N - ix < L[i]) ix = N - L[i] + 1;
        else ix++;
    }
    cout << "Case #" << t << ": " << ix << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) 
        solve(t);
    return 0;
}