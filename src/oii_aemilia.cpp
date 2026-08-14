#include "bits/stdc++.h"
using namespace std;

vector<int> verifica(int N, vector<int> T) {
    int &n = N;
    vector<int> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    for (int i = 0; i < n; i++)
        q.emplace(T[i], i);
    int l, r = l = q.top().second;
    int t = 0;
    ans.emplace_back(l);
    while (!q.empty()) {
        auto [tt, u] = q.top(); q.pop();
        if (u >= l && u <= r) continue;
        if (u > r) {
            if(t + u - r > tt) return {};
            for(int i = r + 1; i <= u; i++)
                ans.emplace_back(i);
            t += u - r;
            r = u;
        } else if (u < l) {
            if(t + l - u > tt) return {};
            for(int i = l - 1; i >= u; i--)
                ans.emplace_back(i);
            t += l - u;
            l = u;
        }
    }
    return ans;
}
