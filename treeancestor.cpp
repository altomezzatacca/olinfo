#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin("input.txt");

    int N, K;
    cin >> N >> K;
    int lg = log2(K)+1;

    vector<vector<int>> ancestor(N, vector<int>(lg, -1));
	ancestor[0][0]=-1;
    for (int i=0; i<N-1; i++){
        int x, y;
        cin >> x >> y;
        ancestor[max(x, y)][0]=min(x, y);
    }

    for (int j=1; j<lg; j++){
        for (int i=0; i<N; i++){
            if (ancestor[i][j-1] != -1) ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
        }
    }

    auto K_func = [&](int nodo) {
        int r=nodo;
        for (int i=lg-1; i>=0; i--){
            if (K & (1<<i)){
                if (ancestor[r][i]==-1) return -1;
                r=ancestor[r][i];
            }
        }
        return r;
    };

    for (int i=0; i<N; i++) cout << K_func(i) << " ";
    cout << endl;

    return 0;
}