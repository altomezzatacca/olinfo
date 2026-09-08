#include "bits/stdc++.h"
using namespace std;

void solve1() {
    int n; cin >> n;
    vector<vector<pair<int, int>>> ans;
    for (int m = 0; m < n; m++) {
        for (int q = 0; q < n; q++) {
            vector<pair<int, int>> v;
            for (int x = 0; x < n; x++)
                v.emplace_back(x, (m * x + q) % n);
            v.emplace_back(n, m);
            ans.emplace_back(v);
        }
    }
    for (int l = 0; l < n; l++) {
        vector<pair<int, int>> v;
        for (int h = 0; h < n; h++)
            v.emplace_back(l, h);
        v.emplace_back(n, n);
        ans.emplace_back(v);
    }
    vector<pair<int, int>> v;
    for (int a = 0; a < n + 1; a++)
        v.emplace_back(n, a);
    ans.emplace_back(v);
    sort(begin(ans), end(ans));
    for (auto u: ans) {
        for (auto [f, s]: u)
            cout << f * n + s << " ";
        cout << "\n";
    }
}

void solve2() {
    int n; cin >> n;
    for (int i = 0; i <= n; i++) {
        cout << 0 << " ";
        for (int j = 1; j <= n; j++)
            cout << i * n + j << " ";
        cout << "\n";
    }
    for (int i = 1; i <= n; i++) {
        int k = i - 1;
        for (int j = 0; j < n; j++) {
            cout << i << " ";
            for (int m = 0; m < n; m++)
                cout << n + 1 + m * n + (m * k + j) % n << " ";
            cout << "\n";
        }
    }
}

int main() {
    for (int t = 0; t < 10; t++) {
        string _input = "input_00" + to_string(t) + ".txt";
        string _output = "output_00" + to_string(t) + ".txt";
        freopen(_input.c_str(), "r", stdin);
        freopen(_output.c_str(), "w", stdout);
        solve1();
        fclose(stdin);
        fclose(stdout);
    }
}
