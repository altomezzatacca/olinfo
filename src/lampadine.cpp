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

vector<int> disconnect(vector<int> L);
void series(vector<int> G);

struct Group{
	vector<int> head, tail;
};

void study(int N) {
	vector<int> head(N);
	iota(head.begin(), head.end(), 0);
	vector<Group> G;
	G.pb({head, {}});

	while(!G.empty()){
		vector<int> query;
		for(auto [head, tail]: G)
			copy(head.begin(), head.begin() + head.size() / 2, back_inserter(query));
		vector<int> V = disconnect(query);
		vector<Group> _new_;
		for(auto [head, tail]: G){
			vector<int> head1, head2, tail1, tail2;
			for(int i = 0; i < head.size() / 2; i++)
				head1.pb(head[i]);
			
			for(int i = head.size() / 2; i < head.size(); i++){
				if(V[head[i]]) head2.pb(head[i]);
				else tail1.pb(head[i]);
			}

			for(auto x: tail){
				if(V[x]) tail2.pb(x);
				else tail1.pb(x);
			}

			if(head1.size() > 1)
				_new_.pb({head1, tail1});
			else {
				tail1.pb(head1[0]);
				series(tail1);
			}

			if(head2.size() > 1)
				_new_.pb({head2, tail2});
			else if(!head2.empty()) {
				tail2.pb(head2[0]);
				series(tail2);
			}
		}
		G = _new_;
	}
}