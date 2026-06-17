#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

long long solve(int N, int* M, int* P) {
    vector<pair<int, int>> V;
    for(int i = 0; i < N; i++)
        V.push_back({M[i] - P[i], i});
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    long long ans = 0;
    for(int i = 0; i < N; i++){
        if(i < N/2) ans += M[V[i].second];
        else ans += P[V[i].second];
    }
    return ans;
}