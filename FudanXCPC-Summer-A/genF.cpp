#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
using namespace std;

int main(){
	srand(time(NULL));
	int T = 1000;
	printf("%d\n", T);
	while (T--){
		int a = rand(), b = rand(), c = rand() + 1, n = rand(), k1, k2;
		k1 = rand() % 11, k2 = (k1 == 10) ? 0 : (rand() % (10 - k1));
		printf("%d %d %d %d %d %d\n", a, b, c, n, k1, k2);
	}
	return 0;
}
