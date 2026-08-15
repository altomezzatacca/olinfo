#include "bits/stdc++.h"
using namespace std;

int sbugiarda(int N, vector<int> H) {
    int &n = N;
    vector<int> &h = H;
    int ans = 0;
    vector<int> prv(n), nxt(n); // primo elemento precedente/successivo con h > h[i]
    vector<int> l(n, 1), r(n, 1); // numero di grattacieli panoramici a sx/dx con indice <= (o >=) a i
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top().first <= h[i])
            s.pop();
        if (s.empty())
            prv[i] = -1;
        else
            prv[i] = s.top().second;
        s.emplace(h[i], i);
    }
    while (!s.empty()) s.pop();
    for (int i = n - 1; i >= 0; i--) {
        while(!s.empty() && s.top().first <= h[i])
            s.pop();
        if (s.empty())
            nxt[i] = -1;
        else
            nxt[i] = s.top().second;
        s.emplace(h[i], i);
    }
    for (int i = 0; i < n; i++)
        if(nxt[i] != -1)
            l[nxt[i]] = max(l[nxt[i]], l[i] + 1);
    for (int i = n - 1; i >= 0; i--)
        if(prv[i] != - 1)
            r[prv[i]] = max(r[prv[i]], r[i] + 1);
    vector<int> prefix_max(n), suffix_max(n);
    prefix_max[0] = l[0];
    for (int i = 1; i < n; i++)
        prefix_max[i] = max(prefix_max[i - 1], l[i]);
    suffix_max[n - 1] = r[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suffix_max[i] = max(suffix_max[i + 1], r[i]);
    for (int i = 0; i < n - 1; i++) // al variare del picco (tra i e i + 1), cerco il massimo l prima e il massimo r dopo
        ans = max(ans, prefix_max[i] + suffix_max[i + 1]);
    return ans;
}
