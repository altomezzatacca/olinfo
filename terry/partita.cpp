#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int N;
    int K;
    cin >> N >> K;
    vector<int> R(N);
    for (int i = 0; i < N; i++) cin >> R[i];
    int risposta = 0;
    priority_queue<int> pq;
    for(int i = 0; i < N; i++){
        pq.emplace(R[i]);
        while(K <= 1 && !pq.empty()){
            K += pq.top();
            pq.pop();
            risposta++;
        }
        if(K == 1){
            cout << "Case #" << t << ": " << -1 << "\n";
            return;
        }
        K--;
    }
    cout << "Case #" << t << ": " << risposta << "\n";
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
