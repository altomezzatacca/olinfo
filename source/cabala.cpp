#include <bits/stdc++.h>
using namespace std;

long long pow(int b, int e){
    if(e == 0) return 1;
    if(e == 1) return b;
    long long x = pow(b, e >> 1);
    long long ans = x * x;
    if(e & 1) ans *= b;
    return ans;
}

//c: numero di cifre
//n: numero corrente
//best: migliore fin ora
long long occulta(int N, int M, int c, long long n, long long &best) {
    if (c < N)
        for(int i = 3; i < 10; i+=3)
            if(c == 0 || i != n / pow(10, c - 1) % 10){
                long long x = n + i * pow(10, c);
                best = max(best, x % M);
                occulta(N, M, c + 1, x, best);
            }
    return best;
}

int main() {
    FILE *fr, *fw;
    int T, N, M, i;
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &T));
    for (i=0; i<T; i++) {
        assert(2 == fscanf(fr, "%d %d", &N, &M));
        long long ans = -1;
        fprintf(fw, "%d ", occulta(N, M, 0, 0, ans));
    }
    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}