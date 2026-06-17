/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>
using namespace std;

// input data
int N, T, i;

int main() {
//  uncomment the following lines if you want to read/write from files
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &T));
    for(i=0; i<T; i++) {
        assert(1 == scanf("%d", &N));

		int x_a=0, x_b=0;
	
		int msb=0, k=N, x_n;
	    while (k>0) {
	        k>>=1;
	        msb++;
	    }
	    
	    switch (N%4){
	    	case 0:
	    		x_n=N;
	    		break;
	    	case 1:
	    		x_n=1;
	    		break;
	    	case 2:
	    		x_n=N+1;
	    		break;
	    	case 3:
	    		x_n=0;
	    		break;
		}
	    
		int n = (1<<(msb))-1;
		x_a = n;
		x_b= x_n^n;

        printf("%d\n", x_a+x_b); // print the result
    }
    return 0;
}