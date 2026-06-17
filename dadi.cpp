#include <stdio.h>
#include <assert.h>

#define MAXN 100000

void simula(int N, char C[], int R[]) {
    // Mettete qui il codice della soluzione
    int dado[3]={1, 2, 3}, j=0, x;
    for(int i=0; i<N; i++){
        switch (C[i]){
            case 'X':
                x=dado[1];
                dado[1]=dado[0];
                dado[0]=7-x;
                break;
            case 'Y':
                x=dado[0];
                dado[0]=dado[2];
                dado[2]=7-x;
                break;
            case 'Z':
                x=dado[2];
                dado[2]=dado[1];
                dado[1]=7-x;
                break;
            case 'F':
                R[j]=dado[1];
                j++;
                break;
            case 'T':
                R[j]=dado[0];
                j++;
                break;
            case 'R':
                R[j]=dado[2];
                j++;
                break;
                    
        }
    }
}

char C[MAXN];
int R[MAXN];

int main() {
    FILE *fr, *fw;
    int N, M, i;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d\n", &N));
    M = 0;
    for (i = 0; i < N; ++i) {
        assert(1 == fscanf(fr, "%c", &C[i]));
        if (C[i] == 'T' || C[i] == 'F' || C[i] == 'R')
            ++M;
    }

    simula(N, C, R);
    for (i = 0; i < M; ++i)
        fprintf(fw, "%d ", R[i]);
    fprintf(fw, "\n");

    fclose(fr);
    fclose(fw);
    return 0;
}
