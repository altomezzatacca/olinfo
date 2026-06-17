#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlll;
constexpr static int inf = 2e9;
constexpr static ll linf = 1e18;
constexpr static int mod1 = 1e9 + 7;
constexpr static int mod2 = 998244353;

vector<ll> calcola(int T, int M, vector<ll> S, vector<ll> P) {
    vector<ll> ans(M), ord(M);
	iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return P[i] < P[j];
    });

	ll x = S[0], w = 0, j = 1;
    for (int i: ord){
        while(j < T){
            ll temp = min(S[j], (P[i] - w) / j);
            x += temp;
            S[j] -= temp;
            w += j * temp;
            if (S[j] > 0) break;
            else j++;
        }
        ans[i] = x;
    }
    return ans;
}