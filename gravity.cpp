#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000

int passeggia(int N, vector<int> H) {
    int s=1, g=1;
    for(int i=0; i<N-1; i++){
    	if (H[i]<H[i+1]) s=g+1;
    	if (H[i]>H[i+1]) g=s+1;
	}
    return max(s, g);
}

vector<int> H;

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++){
        int q;
        assert(1 == fscanf(fr, "%d", &q));
        H.push_back(q);
    }
    fprintf(fw, "%d\n", passeggia(N, H));
    fclose(fr);
    fclose(fw);
    return 0;
}