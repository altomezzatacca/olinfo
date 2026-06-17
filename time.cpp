#include <bits/stdc++.h>
using namespace std;
int H0, M0, H1, M1;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(4 == scanf("%d%d%d%d", &H0, &M0, &H1, &M1));

	if(M1 < M0) {
        M1 += 60;
        H1 --;
    }
    if(H1 < H0) H1 += 24;

	int h = H1 - H0;
    int m = M1 - M0;

    cout << h << " " << m; // print the result
    return 0;
}