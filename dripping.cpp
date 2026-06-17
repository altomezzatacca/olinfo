#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool fst = 1;

tuple<char, ll, ll> prisonier(ll W, vector<ll> notebook){
	if(fst){
		fst = 0;
		return {'w', -1, -1};
	}
	if(notebook.size() == 0) return {'w', (W + 1) % 2, (W + 1) % 2};
	if(notebook[0] == -1 && W == -1){
		if(notebook.size() == 1) return {'a', 1, 0};
		ll n = 1;
		for(int i = 1; i < notebook.size(); i++){
            int x = 1 - notebook[i];
            n += x << (i - 1);
        }
		return {'a', n, 0};
	}
	if(notebook[0] == -1) return {'w', -1, W};
	bool change = 1;
	for(int i = 0; i < notebook.size() && change; i++)
		if(notebook[i] != 1) change = 0;
	bool last = 1;
	for(int i = 0; i < notebook.size() && last; i++)
		if(notebook[i] != 0) last = 0;
	if (change) return {'w', (W + 1) % 2, (W + 1) % 2};
	else if (last) return {'w', abs(W), abs(W)};
	else return {'w', W, abs(W)};
}