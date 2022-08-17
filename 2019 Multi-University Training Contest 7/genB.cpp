#include <bits/stdc++.h>
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

int main(){
	srand(time(NULL));
	#ifndef ONLINE_JUDGE
		freopen("B.in", "w", stdout);
	#endif
	int n = 500, T = 1;
	//cin >> T >> n;
	cout << T << endl;
	while (T--){
		cout << n << endl;
		rep(i, 2, n) cout << rand() % (i - 1) + 1 << ' ' << i << endl;
	}
	return 0;
}
