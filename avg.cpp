// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>
using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

    long long N, K;
    cin >> N >> K;

	long long media=0;
    
    vector<long long> P(N);
    for (int i = 0; i < N; ++i){
        cin >> P[i];
        media+=P[i];
	}
    sort(P.rbegin(), P.rend());
    long long ans = 0;
    
	if(K*N>media){
		ans=1;
	} else {
		long long i=0;
        while(media>K*N){
            media-=(P[i]-1);
            i++;
        }
        ans=i;
	}
    
    cout << ans << endl;

    return 0;
}
    