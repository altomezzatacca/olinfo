#include <bits/stdc++.h>
using namespace std;

double scosse(int N) {
    return 0.5 * 0.5 * N * (N - 1);
}


int main() {
    FILE *fr, *fw;
    int N;
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    fprintf(fw, "%.6f\n", scosse(N));
    fclose(fr);
    fclose(fw);
    return 0;
}