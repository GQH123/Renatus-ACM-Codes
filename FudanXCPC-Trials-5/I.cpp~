#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 
#define maxm
using namespace std;

//int num[1 << 20][40], bc[1 << 20], base = (1 << 20) - 1;
//inline void gen(int& x){	
//	x = (1ll * x * 487237 + 1011807) & base;
//}

int bc[1 << 20], base = (1 << 20) - 1;

inline int gen(int x){	
	return ((1ll * x * 487237 + 1011807) & base);
}

int lis[2][1 << 20], cs[2], d = 0;
void shift(int op){
	d ^= 1, cs[d] = 0; int lim = cs[d ^ 1];
	rep(i, 1, lim) {
		if ((bc[lis[d ^ 1][i]] & 1) == op) {
			lis[d][++cs[d]] = gen(lis[d ^ 1][i]);
		}
	}
}

int main(){
	bc[0] = 0; srep(i, 1, (1 << 20)) bc[i] = bc[i >> 1] + (i & 1);
	srep(i, 0, (1 << 20)) lis[0][++cs[0]] = i;
	int num, _num;
	cin >> num;
	while (1){
		cout << 1 << endl;
		cin >> _num;
		if (_num == -1) return 0;
		if (_num < num) shift(0);
		else shift(1);
		num = _num;
		//cerr << cs[d] << endl;
		if (cs[d] == 1) break;
	}
	int life = lis[d][1];
	while (1){
		if (bc[life] & 1) {
			if (200 - num <= num) cout << 200 - num << endl;
			else cout << num << endl;
		}
		else cout << 1 << endl; 
		cin >> num;
		if (num == -1) return 0;
		life = gen(life);
	}
	/*
	srep(i, 0, (1 << 20)) {
		int x = i;
		srep(j, 0, 40) {
			num[i][j] = bc[x];
			gen(x);
		}
	}
	*/
	return 0;
}
