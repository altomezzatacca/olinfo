#include <bits/stdc++.h>
using namespace std;

void solve(int t){
    int N; cin >> N;
    set<int> S;
    for(int i = 0, k; i < N; S.insert(k), i++)
        cin >> k;
    int ans = S.size();
    cout << "Case #" << t << ": ";
    cout << ans << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
        solve(t);
}