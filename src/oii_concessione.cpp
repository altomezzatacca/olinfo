#include "bits/stdc++.h"
using namespace std;

struct piramide {

    vector<string> v;
    vector<vector<array<int, 2>>> pref1, pref2;
    int n;

    piramide () {}
    piramide (int n, vector<string> m): n(n), v(m) {
        pref1.assign(n, vector<array<int, 2>> (n));
        pref2.assign(n, vector<array<int, 2>>(n));
        for (int i = 0; i < n; i++) {
            array<int, 2> a = {0, 0};
            a[vb(i, 0)]++;
            pref1[i][0] = a;
        }
        for (int i = 0; i < n; i++) {
            array<int, 2> a = {0, 0};
            a[vb(0, i)]++;
            pref1[0][i] = a;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                array<int, 2> a = pref1[i - 1][j - 1];
                a[vb(i, j)]++;
                pref1[i][j] = a;
            }
        }
        for (int i = 0; i < n; i++) {
            array<int, 2> a = {0, 0};
            a[vb(i, 0)]++;
            pref2[i][0] = a;
        }
        for (int i = 0; i < n; i++) {
            array<int, 2> a = {0, 0};
            a[vb(n - 1, i)]++;
            pref2[n - 1][i] = a;
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 1; j < n; j++) {
                array<int, 2> a = pref2[i + 1][j - 1];
                a[vb(i, j)]++;
                pref2[i][j] = a;
            }
        }
    }

    bool check_diag_1 (int x, int y, int h, bool c) {
        return pref1[x + h][y + h][!c] - pref1[x][y][!c] + (vb(x, y) == !c ? 1 : 0) == 0;
    }

    bool check_diag_2 (int x, int y, int h, bool c) {
        return pref2[x][y + h][!c] - pref2[x + h][y][!c] + (vb(x + h, y) == !c ? 1 : 0) == 0;
    }

    bool vb (int x, int y) {
        return v[x][y] - '0';
    }

    // 1 se la cima della piramide di base x, x + h, y + h, x è nera, 0 altrimenti
    bool cima (int x, int y, int h) {
        if (h == 0) return vb(x, y);
        if (h == 1) return v[x][y] == v[x + 1][y + 1] && v[x + 1][y] == v[x][y + 1] && v[x][y] != v[x][y + 1];
        bool c1 = vb(x, y), c2 = vb(x + h, y);
        bool ans1 = 1, ans2 = 1;
        {
            ans1 &= check_diag_1(x, y, h, c1);
            ans1 &= check_diag_1(x + 1, y, h - 1, !c1);
            ans1 &= check_diag_1(x + 2, y, h - 2, !c1);
            ans1 &= check_diag_1(x, y + 1, h - 1, !c1);
            ans1 &= check_diag_1(x, y + 2, h - 2, !c1);
        } {
            ans2 &= check_diag_2(x, y, h, c2);
            ans2 &= check_diag_2(x, y, h - 1, !c2);
            ans2 &= check_diag_2(x, y, h - 2, !c2);
            ans2 &= check_diag_2(x + 1, y + 1, h - 1, !c2);
            ans2 &= check_diag_2(x + 2, y + 2, h - 2, !c2);
        }
        return (ans1 || ans2);
    }

};

piramide p;

void init(int N, vector<string> M) {
    p = piramide(N, M);
}

bool query(int h, int x, int y) {
    return p.cima(x, y, h);
}

// GRADER DI ESEMPIO, NON MODIFICARE

#ifndef EVAL

int main() {
    int N, Q;
    cin >> N >> Q;
    
    vector<string> M(N);
    for (int i = 0; i < N; i++)
        cin >> M[i];
    
    init(N, M);

    for (int i = 0; i < Q; i++) {
        int h, x, y;
        cin >> h >> x >> y;
        cout << query(h, x, y) << '\n';
    }
}

#endif
