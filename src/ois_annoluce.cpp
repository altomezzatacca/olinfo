#include <bits/stdc++.h>
using namespace std;

vector<__int128_t> s;

void mappatura(int N, int X[], int Y[], int Z[]) {
    for (int i=0; i<N; i++){
    	__int128_t d = 1LL*X[i]*X[i]+1LL*Y[i]*Y[i]+1LL*Z[i]*Z[i];
    	s.push_back(d);
	}
    sort(s.begin(), s.end());
}

long long query(int D) {
	long long d=1LL*D*D+1;
    return lower_bound(s.begin(), s.end(), d)-s.begin();
}


#define MAXN 100000
int X[MAXN], Y[MAXN], Z[MAXN];

int main() {
    FILE *fr, *fw;
    int N, Q, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(3 == fscanf(fr, "%d%d%d", &X[i], &Y[i], &Z[i]));

    mappatura(N, X, Y, Z);

    assert(1 == fscanf(fr, "%d", &Q));
    for(i=0; i<Q; i++) {
        int D;
        assert(1 == fscanf(fr, "%d", &D));
        fprintf(fw, "%lld\n", query(D));
    }

    fclose(fr);
    fclose(fw);
    return 0;
}
