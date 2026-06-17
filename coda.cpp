#include <vector>
using namespace std;

vector<int> cucina(int N, int K, int X, vector<int> H) {
    vector<int> R(X+1, 0), F(X, 0), C(X+1);
    for(int i = 0; i < N; i++) F[H[i]]++;
    C[X] = K-1;
    
    for(int i = X-1; i >= 0; i--){
    	int p = min(F[i], K - C[i+1]);
    	C[i] = max(0, C[i+1] + p - 1);
    	R[i] = R[i+1] + p;
	}
	R.pop_back();

    return R;
}