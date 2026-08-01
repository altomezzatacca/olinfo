#include <bits/stdc++.h>
using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; ++i)
        cin >> P[i];

    int ans = 0;
    priority_queue<pair<int, int>> ql, qr;
    bool b = 0;
    for(int i = 0; i < N; i++){
        if(P[i] == N - 1){
            b = 1;
            ql.emplace(P[i], i);
            qr.emplace(P[i], i);
        } else if (b){
            qr.emplace(P[i], i);
        } else 
            ql.emplace(P[i], i);
    }
    int lr = ql.top().second,
        rl = qr.top().second;
    while(!ql.empty()){
        auto [p, i] = ql.top(); ql.pop();
        if(i > lr) ans++;
        else lr = i;
    }
    while(!qr.empty()){
        auto [p, i] = qr.top(); qr.pop();
        if(i < rl) ans++;
        else rl = i;
    }

    cout << ans << endl;

    return 0;
}
