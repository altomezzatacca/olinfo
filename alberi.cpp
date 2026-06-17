#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr static int inf = 2e9;
constexpr static ll linf = 1e18;
constexpr static int mod = 1e9 + 7;

long long carica(int N, int K, vector<int> A) {
    if(N == 1) return A[0];
    vector<ll> B(N), C(N);
    B[N - 1] = A[N - 1];
    for(int i = N - 2; i >= 0; i--)
        B[i] = B[i + 1] + A[i];
    for(int i = 0; i < N; i++)
        C[i] = 1LL * (N - i) * K + A[N - 1];
    ll ix = -1, best = 0;
    for(int i = 0; i < N; i++)
        if(B[i] - C[i] > best){
            best = B[i] - C[i];
            ix = i;
        }
    ll ans = (ix == -1 ? B[0] : B[0] - B[ix] + K * (N - ix) + A[N - 1]);
    return ans;
}

#ifndef EVAL

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int &a: A) cin >> a;

    cout << carica(N, K, A) << endl;

    return 0;
}

#endif