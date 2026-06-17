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

int main(){
    
	freopen("input.txt", "r", stdin);
   	ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
   	
	int T, S, Q, ans = 0;
	cin >> T >> S >> Q;
	map<int, vector<vector<int>>> right;
	for(int i = 0; i < T; i++){
		int tot = 0;
		vector<int> a;
		for(int j = 0; j < Q; j++){
			int x; cin >> x;
			tot += x;
			a.push_back(x);
		}
		sort(a.begin(), a.end());
		right[tot].push_back(a);
	}
	for(int i = 0; i < S; i++){
		int tot = 0;
		vector<int> a;
		for(int j = 0; j < Q; j++){
			int x; cin >> x;
			tot += x;
			a.push_back(x);
		}
		sort(a.begin(), a.end());
		for(auto V: right[tot])
			if (a == V) ans++;
	}
	cout << ans;
	return 0;
}