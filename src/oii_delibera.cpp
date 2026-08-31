#include "bits/stdc++.h"
using namespace std;
constexpr static int inf = 1e9;

bool chiedi(vector<int> S, int x);

struct giunta {

    int n = 99;
    double phi = (1.0 + sqrt(5.0)) / 2.0;
    vector<int> dp, mm; // costo in query e lunghezza

    vector<int> get_idx (int l, int r) {
        vector<int> v(r - l + 1);
        iota(begin(v), end(v), l);
        return v;
    }

    void precompute () {
        dp.assign(n + 1, inf);
        mm.resize(n + 1);
        dp[0] = dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            int best = inf, best_m = 0;
            for (int m = 1; m < i; m++) {
                int c1 = i + dp[m - 1]; // i query tot + ricorsione
                int c2 = i + m + dp[i - m]; // i query tot + m per capire quale è a destra + ricorsione
                if (max(c1, c2) < best)
                    best = max(c1, c2), best_m = m;
            }
            dp[i] = best, mm[i] = best_m;
        }
    }

    int solve (int l, int r, vector<int> v) {
        if (l + 1 == r) return v[0];
        int k = v.size();
        int m = l + mm[k] - 1;
        vector<int> ask_l = get_idx(l, m), ask_r = get_idx(m + 1, r);
        vector<int> v_l, v_r;
        for (auto u: v) {
            bool b = chiedi(ask_l, u);
            if (b) v_l.emplace_back(u);
            else v_r.emplace_back(u);
        }
        if ((int)v_l.size() < m - l + 1) {
            return solve(l, m, v_l);
        } else {
            for (auto u: v_l)
                if (chiedi(ask_r, u))
                    return u;
            return solve(m + 1, r, v_r);
        }
    }

    int query () {
        precompute();
        return solve(0, n, get_idx(0, n - 1));
    }

};

int delibera(int N) {
    giunta g;
    return g.query();
}

#ifndef EVAL

namespace {
int N;
vector<int> A;
int queries = 0;
}  // namespace

bool chiedi(vector<int> S, int x) {
    queries++;
    if (x < 0 || x >= N) {
        cout << "Invalid query" << endl;
        exit(0);
    }
    sort(S.begin(), S.end());
    if (!S.empty() && (S.front() < 0 || S.back() >= N + 1)) {
        cout << "Invalid query" << endl;
        exit(0);
    }
    if (unique(S.begin(), S.end()) != S.end()) {
        cout << "Invalid query" << endl;
        exit(0);
    }

    for (int idx : S)
        if (A[idx] == x) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; ++tc) {
        cin >> N;

        A.assign(N + 1, 0);
        for (int i = 0; i < A.size(); ++i) {
            if (!(cin >> A[i])) {
                cout << "Invalid instance" << endl;
                return 0;
            }
        }

        if (N <= 0) {
            cout << "Invalid instance" << endl;
            return 0;
        }
        vector<int> freq(N, 0);
        for (int v : A) {
            if (v < 0 || v >= N) {
                cout << "Invalid instance" << endl;
                return 0;
            }
            freq[v]++;
        }

        int expected_value = -1;
        int twice = 0;
        for (int v = 0; v < N; ++v) {
            if (freq[v] == 2) {
                twice++;
                expected_value = v;
            } else if (freq[v] != 1) {
                cout << "Invalid instance" << endl;
                return 0;
            }
        }
        if (twice != 1) {
            cout << "Invalid instance" << endl;
            return 0;
        }

        queries = 0;

        int got = delibera(N);

        if (got != expected_value)
            cout << "Wrong answer" << endl;
        else
            cout << "Correct. " << queries << " queries." << endl;
    }

    return 0;
}

#endif
