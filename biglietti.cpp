#include <bits/stdc++.h>
using namespace std;

int compra(int N, int M, int A, int B) {
    int a = A * N;
    int b = (N / M) * B + (N % M) * A;
    int c = ceil(1.0 * N / M) * B;
    int ans = min(a, b);
    return min(ans, c);
}

int main() {
    FILE *fr, *fw;
    int N, M, A, B;
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));
    fprintf(fw, "%d\n", compra(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}