#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
using namespace std;

int main(){
	int n = 100000; cout << n << endl;
	rep(i, 1, n) cout << rand() % n + 1 << ' '; cout << endl;
	int m = 100000; cout << m << endl;
	rep(i, 1, m) {
		int l = rand() % n + 1;
		int r = rand() % n + 1;
		if (l > r) swap(l, r);
		cout << l << ' ' << r << ' ' << rand() % n + 1 << ' ' << rand() % n + 1 << endl;
	}
}
