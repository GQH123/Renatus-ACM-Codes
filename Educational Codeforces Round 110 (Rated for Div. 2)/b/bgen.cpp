#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
using namespace std;

int main(){
	srand(time(NULL));
	int T = 1;
	cout << T << endl;
	int n = 200;
	cout << n << endl;
	rep(i, 1, n) cout << rand() % 100000 + 1 << ' ';
	cout << endl;
	return 0;
}
