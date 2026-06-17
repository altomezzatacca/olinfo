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

bool solve(){
	ll n, k; cin >> n >> k;
	if(k == 1) return 1;
	if(n >= k * (k + 1) / 2 && n <= k * (k + 1) / 2 + 1) return 1;
	else return 0;
}
    
int main(){
    
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
   	ios::sync_with_stdio(false);
    cin.tie(nullptr);
   	cout.tie(nullptr);

   	int t; cin >> t;
   		
	while(t--) cout << (solve() ? "YES" : "NO") << endl;

	return 0;
}