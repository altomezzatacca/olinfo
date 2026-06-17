#include <stdbool.h>
bool chiedi(int X);

int indovina() {
	int ans = 0;
	int x = 2147483647, a = 1;
	int y = 1;
	chiedi(x);
	x -= y;
	for(int i = 0; i < 31; i++){
		if(!chiedi(x)) ans += a;
		a <<= 1;
		y <<= 1;
		x -= y;
	}
	return ans;
}