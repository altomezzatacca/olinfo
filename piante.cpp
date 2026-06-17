#include <bits/stdc++.h>
using namespace std;

int pollice_verde(int N, vector<int> H) {
	int ans=0;
    for (int i=0; i<N; i++) {
        if (((i==0 || H[i]>=H[i - 1]) && (i==N-1 || H[i]>=H[i+1])) ) ans++;
    }
    return ans;
}