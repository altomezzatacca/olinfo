#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int sadness(int N, int K, int V[]) {
    deque<int> mindq, maxdq; //tengono indici di valori crescenti e decrescenti
    for(int i = 0; i <= K; i++){
        while(!mindq.empty() && V[mindq.back()] >= V[i])
            mindq.pop_back();
        mindq.push_back(i);
        while(!maxdq.empty() && V[maxdq.back()] <= V[i])
            maxdq.pop_back();
        maxdq.push_back(i);
    }
    int ris = V[maxdq.front()] - V[mindq.front()];
    
    for(int r = K + 1; r < N; r++){
        int l = r - K;

        while(!mindq.empty() && mindq.front() < l)
            mindq.pop_front();
        while(!mindq.empty() && V[mindq.back()] >= V[r])
            mindq.pop_back();
        mindq.push_back(r);

        while(!maxdq.empty() && maxdq.front() < l)
            maxdq.pop_front();
        while(!maxdq.empty() && V[maxdq.back()] <= V[r])
            maxdq.pop_back();
        maxdq.push_back(r);

        ris = max(ris, V[maxdq.front()] - V[mindq.front()]);
    }
    
    return ris;
}


int V[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

    fr = stdin; //fopen("input.txt", "r");
    fw = stdout; //fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &V[i]));

    fprintf(fw, "%d\n", sadness(N, K, V));
    fclose(fr);
    fclose(fw);
    return 0;
}