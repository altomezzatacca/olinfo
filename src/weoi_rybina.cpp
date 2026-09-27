#include "bits/stdc++.h"
#include "rybina.h"
using namespace std;
using ll = long long;

GuessResult guess(long long x);

void rybina_search(int n) {
    ll p10 = 1;
    while (n--) p10 *= 10;
    ll lA = 0, rA = p10, 
       lB = 0, rB = p10;
    ll A = 0, B = 0;
    bool okA = 0, okB = 0;
    bool status = 0;
    while (!(okA && okB)) {
        ll mA = (lA + rA) >> 1, mB = (lB + rB) >> 1;
        if (status == 0) { // AB
            if (mA == p10) mA--;
            ll ask = (!okA ? mA * p10 : A * p10 + mB);
            auto [c, s] = guess(ask);
            if (s) status = !status;
            if (!okA) {
                if (lA == rA) {
                    c == 1 ? A = mA : A = mA - 1;
                    okA = 1;
                } else if (lA == mA && c == -1) {
                    A = mA - 1;
                    okA = 1;
                } else {
                    c == 1 ? lA = mA + 1 : rA = mA;
                }
            } else {
                if (lB == rB) {
                    c == 1 ? B = mB : B = mB - 1;
                    okB = 1;
                } else if (lB == mB && c == - 1) {
                    B = mB - 1;
                    okB = 1;
                } else {
                    c == 1 ? lB = mB + 1 : rB = mB;
                }
            }
        } else { // BA
            if (mB == p10) mB--;
            ll ask = (!okB ? mB * p10 : B * p10 + mA);
            auto [c, s] = guess(ask);
            if (s) status = !status;
            if (!okB) {
                if (lB == rB) {
                    c == 1 ? B = mB : B = mB - 1;
                    okB = 1;
                } else if (lB == mB && c == - 1) {
                    B = mB - 1;
                    okB = 1;
                } else {
                    c == 1 ? lB = mB + 1 : rB = mB;
                }
            } else {
                if (lA == rA) {
                    c == 1 ? A = mA : A = mA - 1;
                    okA = 1;
                } else if (lA == mA && c == -1) {
                    A = mA - 1;
                    okA = 1;
                } else {
                    c == 1 ? lA = mA + 1 : rA = mA;
                }
            }
        }
    }
    status == 0 ? guess(A * p10 + B) : guess(B * p10 + A);
}
