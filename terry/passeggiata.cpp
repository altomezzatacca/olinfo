#include <bits/stdc++.h>
using namespace std;

void solve(int t){
    int N; cin >> N;
    vector<long long> A(N), prefix(N);
    for(int i = 0; i < N; i++)
        cin >> A[i];
    for(int i = 0, k; i < N; prefix[i] = (i == 0 ? k : min(1LL * k, prefix[i - 1])), i++)
        cin >> k;
    long long ans = 0;
    for(int i = 0; i < N; i++)
        ans += A[i] * prefix[i];
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