#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
using namespace std;

int main(){
	int T = 4, n = 5000000;
	cout << T << endl;
	rep(i, 1, T){
		cout << n << endl;
		rep(j, 1, n) cout << (char)(rand() % 26 + 'a');
		cout << endl;
	}
	return 0;
}
