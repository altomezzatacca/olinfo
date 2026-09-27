#include "bits/stdc++.h"
using namespace std;
using ll = long long;

long long estrai(int N, long long K, vector<int> A, vector<int> Q) {
    ll n = N, k = K;
    vector<ll> AA, QQ;
    for (auto u: A) AA.emplace_back(1LL * u);
    for (auto u: Q) QQ.emplace_back(1LL * u);
    vector<ll> prefix(n);
    prefix[0] = QQ[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + QQ[i];
    ll sum = 0, time = 0;
    vector<ll> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = i + 1;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        sum += QQ[i] * (AA[i] - 1), time += AA[i] - 1;
        pq.emplace(QQ[i], AA[i] - 1);
        while(!pq.empty() && prefix[i] + sum - pq.top().first * pq.top().second >= k) {
            sum -= pq.top().first * pq.top().second;
            time -= pq.top().second;
            pq.pop();
        }
        if (!pq.empty() && prefix[i] + sum - pq.top().first >= k){
            auto [q, a] = pq.top(); pq.pop();
            ll remaining = prefix[i] + sum - k;
            remaining -= remaining % q;
            ll t = remaining / q;
            time -= t;
            sum -= remaining;
            pq.emplace(q, a - t);
        }
        if (prefix[i] + sum < k) ans[i] = 1e18;
        ans[i] += time;
    }
    ll res = 1e18 + 1;
    for (auto u: ans)
        res = min(u, res);
    if (res == 1e18 + 1) return 67;
    return res;
}

#ifndef EVAL
int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<int> A(N), Q(N);
    for(int &x: A) cin >> x;
    for(int &x: Q) cin >> x;
    cout << estrai(N, K, A, Q) << endl;
}
#endif
