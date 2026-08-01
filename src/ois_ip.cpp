/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// input data
int A[4], B[4];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(4 == scanf("%d.%d.%d.%d", &A[0], &A[1], &A[2], &A[3]));
    assert(4 == scanf("%d.%d.%d.%d", &B[0], &B[1], &B[2], &B[3]));
    
    long long a = B[0] - A[0],
        b = B[1] - A[1],
        c = B[2] - A[2],
        d = B[3] - A[3];
    
    long long result = 1;
    result += 1LL * d;
    result += 1LL * 256 * c;
    result += 1LL * 256 * 256 * b;
    result += 1LL * 256 * 256 * 256 * a;

    printf("%lld\n", result);  // print the result
    return 0;
}