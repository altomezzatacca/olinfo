#include <vector>
using namespace std;
constexpr static int INF = 1e9;

int trova_massimo(int N, vector<int> V) {
    int _max = -INF;
    for(auto &u: V) _max = max(_max, u);
    return _max;
}