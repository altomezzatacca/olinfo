#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> c(n);
    vector<int> idx(n);
    for (int i = 0; i < n; i++)
        cin >> c[i], c[i]--, idx[c[i]] = i;
    vector<int> ovt(n);
    int macs = 0, ix = 0;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        x--;
        int y = c[idx[x] - 1];
        if (++ovt[y] > macs)
            macs = ovt[y], ix = y;
        else if (ovt[y] == macs && y < ix)
            ix = y;
        idx[y]++;
        idx[x]--;
        swap(c[idx[x]], c[idx[y]]);
        cout << ix + 1 << "\n";
    }
    return 0;
}
