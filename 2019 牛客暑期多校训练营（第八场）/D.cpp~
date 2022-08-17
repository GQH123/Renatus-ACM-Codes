#include <bits/stdc++.h>
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define lowbit(x) (x & -x)
#define pb push_back
using namespace std;

const int inf = 1000000000;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n, m, h, q;
vector<vector<vector<int>>> s[8];
vector<vector<int>> op1;
vector<int> op2;

void chkmax(int& mi, int x){
	mi = (mi >= x) ? mi : x;
}
void chkmin(int& mi, int x){
	mi = (mi <= x) ? mi : x;
}

int get3(int x, int y, int z, int op){
	int mi = -inf;
	if (op & 1){
		while (z) {
			chkmax(mi, s[op][x][y][z]);
			z -= lowbit(z);
		}
	}
	else {	
		while (z <= h){
			chkmax(mi, s[op][x][y][z]);
			z += lowbit(z);
		}
	}
	return mi;
}

int get2(int x, int y, int z, int op){
	int mi = -inf;
	if (op & 2){
		while (y){
			chkmax(mi, get3(x, y, z, op));
			y -= lowbit(y);
		}
	}
	else {
		while (y <= m){
			chkmax(mi, get3(x, y, z, op));
			y += lowbit(y);
		}
	}
	return mi;
}

int get(int x, int y, int z, int op){ //0 - greater, 1 +, smaller
	int mi = -inf;
	if (op & 4) {
		while (x){
			chkmax(mi, get2(x, y, z, op));
			x -= lowbit(x);
		}
	}
	else {
		while (x <= n){
			chkmax(mi, get2(x, y, z, op));
			x += lowbit(x);
		}
	}
	return mi;
}

void add3(int x, int y, int z, int d, int op){ //0 - smaller, 1 +, greater
	//int d = ((op & 4) ? x : -x) + ((op & 2) ? y : -y) + ((op & 1) ? z : -z);
	if (op & 1) {
		while (z <= h){
			chkmax(s[op][x][y][z], d);
			z += lowbit(z);
		}
	}
	else {
		while (z){
			chkmax(s[op][x][y][z], d);
			z -= lowbit(z);
		}
	}
}

void add2(int x, int y, int z, int d, int op){ //0 - smaller, 1 +, greater
	if (op & 2) {
		while (y <= m){
			add3(x, y, z, d, op);
			y += lowbit(y);
		}
	}
	else {
		while (y){
			add3(x, y, z, d, op);
			y -= lowbit(y);
		}
	}
}

void add(int x, int y, int z, int d, int op){ //0 - smaller, 1 +, greater
	if (op & 4) {
		while (x <= n){
			add2(x, y, z, d, op);
			x += lowbit(x);
		}
	}
	else {
		while (x){
			add2(x, y, z, d, op);
			x -= lowbit(x);
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("D.in", "r", stdin);
	#endif
	read(n), read(m), read(h), read(q);
	rep(i, 0, h) op2.pb(-inf);
	rep(i, 0, m) op1.pb(op2);
	rep(j, 0, 7) rep(i, 0, n) s[j].pb(op1);
	int op, x, y, z, v;
	rep(i, 1, q){
		read(op), read(x), read(y), read(z);
		if (op == 2){
			int mi = inf;
			v = get(x, y, z, 7);
			if (v > -inf) chkmin(mi, x + y + z - v);
			v = get(x, y, z, 6);
			if (v > -inf) chkmin(mi, x + y - z - v);
			v = get(x, y, z, 5);
			if (v > -inf) chkmin(mi, x - y + z - v);
			v = get(x, y, z, 4);
			if (v > -inf) chkmin(mi, x - y - z - v);
			v = get(x, y, z, 3);
			if (v > -inf) chkmin(mi, -x + y + z - v);
			v = get(x, y, z, 2);
			if (v > -inf) chkmin(mi, -x + y - z - v);
			v = get(x, y, z, 1);
			if (v > -inf) chkmin(mi, -x - y + z - v);
			v = get(x, y, z, 0);
			if (v > -inf) chkmin(mi, -x - y - z - v);
			
			printf("%d\n", mi);
		}
		else if (op == 1) {
			add(x, y, z, x + y + z, 7);
			add(x, y, z, x + y - z, 6);
			add(x, y, z, x - y + z, 5);
			add(x, y, z, x - y - z, 4);
			add(x, y, z, -x + y + z, 3);
			add(x, y, z, -x + y - z, 2);
			add(x, y, z, -x - y + z, 1);
			add(x, y, z, -x - y - z, 0);
		}
	}
	return 0;
}
