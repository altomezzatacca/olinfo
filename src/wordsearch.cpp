#include <bits/stdc++.h>
using namespace std;
constexpr static int mod = 1e9 + 7;
vector<int> vx = {1, 1, 1, 0, 0, -1, -1, -1},
            vy = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int H, W;
    string S;
    cin >> S;
    cin >> H >> W;
    vector<string> M(H);
    for(int i = 0; i < H; i++)
        cin >> M[i];
    vector<vector<int>> dp(H, vector<int> (W)), dp1(H, vector<int> (W));
    function<bool(int, int)> exists = [&](int a, int b) -> bool{
		return (a >= 0 && a < H && b >= 0 && b < W);
	};
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
            if(M[i][j] == S[0])
                dp[i][j] = 1;
    for(int k = 1; k < (int)S.size(); k++){
        for(int i = 0; i < H; i++)
            for(int j = 0; j < W; j++)
                dp1[i][j] = 0;
        for(int i = 0; i < H; i++)
            for(int j = 0; j < W; j++)
                if(dp[i][j])
                    for(int kk = 0; kk < 8; kk++)
                        if(exists(i + vx[kk], j + vy[kk]) && M[i + vx[kk]][j + vy[kk]] == S[k])
                            dp1[i + vx[kk]][j + vy[kk]] = (dp1[i + vx[kk]][j + vy[kk]] + dp[i][j]) % mod;
        dp = dp1;
    }
    int ans = 0;
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
            ans = (ans + dp[i][j]) % mod;
    cout << ans << endl;
}