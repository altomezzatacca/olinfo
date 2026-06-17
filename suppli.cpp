#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N; cin >> N;
    vector<int> V(N);
    for(auto &u: V) cin >> u;
    int g = V[0];
    for(int i = 1; i < N; i++)
        g = lcm(g, V[i]);
    vector<bool> dp(g);
    dp[0] = 1;
    for(auto u: V)
        dp[u] = 1;
    for(int i = 0; i < g; i++)
        if(dp[i])
            for(auto u: V){
                int ix = i + u;
                if(ix >= g) continue;
                dp[ix] = 1;
            }
    int ans = 0;
    for(int i = g - 1; g > 0 && ans == 0; i--)
        if(!dp[i])
            ans = i;
    cout << ans << endl;
}