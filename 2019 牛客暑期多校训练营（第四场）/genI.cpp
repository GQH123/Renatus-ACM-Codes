#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
using namespace std;

int main(){
	freopen("I.in", "w", stdout);
	srand(time(NULL));
	int n = 200000;
	rep(i, 1, n) printf("%c", 'a' + rand() % 26);
	return 0;
}
