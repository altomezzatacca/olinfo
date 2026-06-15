#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P=31, mod=1e9+9;

ll hashing(string &S){
	int M=S.size();
	ll h=0;
	ll pp=1;
	for(int i=M-1; i>=0; i--){
		int x=0;
		pp*=P; pp%=mod;
		int c = S[i] + 1 - 'a';
		x+=pp*c; x%=mod;
		h=h+x;
		h%=mod;
	}
	return h;
}

int booth(string& s) {
    string S=s+s;
    int n=S.size(), M=s.size();
    int i=0, j=1, k;
    while (i<M && j<M) {
        k=0;
        while (k<M && S[i+k]==S[j+k]) k++;
        if (k==M) break;
        if (S[i+k]>S[j+k]){
            i=max(i+k+1, j);
            j=i+1;
        } else {
            j+=k+1;
        }
    }
    return min(i, j)%M;
}

int main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, M;
    cin >> N >> M;

    vector<string> R(N);
    for (int i = 0; i < N; i++) {
        cin >> R[i];
    }

	map<ll, ll> mp;
	for(int i=0; i<N; i++){
		int ix=booth(R[i]);
		string str=R[i].substr(ix)+R[i].substr(0,ix);
		ll h = hashing(str);
		mp[h]++;
	}
	
	ll ans=0;
	for(auto [x, y]: mp) ans+= y*(y-1)/2;

    cout << ans << endl; // print the result
    
    return 0;
}
