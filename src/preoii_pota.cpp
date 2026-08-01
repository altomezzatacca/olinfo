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

void permute(int subtask, int N, int V[], int R[]){
	vector<int> v(N); for(int i = 0; i < N; i++) v[i] = V[i];
	sort(v.begin(), v.end());
	int sx = 0, dx = N - 1;
	for(int i = 0; i < N; i++){
		if(i % 2 == 0)
			R[i] = v[dx--];
		else
			R[i] = v[sx++];
	}
}