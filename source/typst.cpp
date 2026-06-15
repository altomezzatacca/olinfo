int compila(int D, int X, int N, int S) {
    if (D > N*S + X) return 0;
    int A = (D - X) / S;
    A-=N;
    if (A < 0) A=-A;
    return A;
}
