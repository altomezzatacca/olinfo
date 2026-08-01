#include <bits/stdc++.h>
using namespace std;

int bicollatz(int a, int b) {
    int n = 0;
	map <int, map <int, bool>> mp;
	while (!mp[a][b] && (a != 1 || b != 1)){
		mp[a][b] = true;
		if (a % 2 == 0 && b % 2 == 0) {
			a >>= 1;
			b >>= 1;
		} else if (a % 2 == 1 && b % 2 == 1) {
			a = 3*a + 1;
			b = 3*b + 1;
		} else if (a % 2 == 1) {
			a += 3;
		} else if (b % 2 == 1) {
			b += 3;
		}
		n++;
	}
    return ((mp[a][b]) ? -1 : n);
}


int main() {
    FILE *fr, *fw;
    int A, B;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &A, &B));

    fprintf(fw, "%d\n", bicollatz(A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}