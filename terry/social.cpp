#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    vector<pair<int, int>> order(N);
    for(int i = 0; i < N; i++){
      order[i].first = A[i];
      order[i].second = i;
    }
    vector<int> F(N, 0); // memorizza qui le risposte
    sort(order.rbegin(), order.rend());
    vector<bool> used(N, 0);
    int last_i = 0;
    for(int i = 0; i < N; i++){
        auto [val, ix] = order[i];
        // val = order[i].first
        // ix = order[i].second
        int new_i = max(i + 1, last_i);
        for(int j = 0; j < val; j++){
          int jx = new_i + j;
          if(jx >= N){
            F[order[0].second] = ix;
          } else {
            used[jx] = true;
            F[order[jx].second] = ix;
            last_i = jx + 1;
          }
        }
    }
    
    cout << "Case #" << t << ":";
    for (int i=0; i<N; i++) {
        cout << " " << F[i];
    }
    cout << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t;
    cin >> T;

    for (t = 1; t <= T; t++) {
        solve(t);
    }
}