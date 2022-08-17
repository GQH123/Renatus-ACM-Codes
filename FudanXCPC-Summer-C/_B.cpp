#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxc 52
#define maxn 160020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define pc putchar
#define ll long long int 
#define ld long double 
#define lowbit(x) (x & -x)
#define M 
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

int lis[maxn];
int m = 0, cs = 0;

set<int> c[maxc][maxn];
set<int> :: iterator it, it2;
void add(int id, int x, int y, int v){
	while (x <= cs){
		if (v == 1) c[id][x].insert(y);
		else c[id][x].erase(y);
		x += lowbit(x);
	}
}
int get(int id, int x, int y1, int y2){
	while (x){
		if (c[id][x].empty()) {
			x -= lowbit(x);
			continue;
		}
		it = c[id][x].lower_bound(y1);
		it2 = c[id][x].upper_bound(y2); 
		x -= lowbit(x);
		if (it == it2) continue;
		else return 1;
	}
	return 0;
}

struct q{
	int type, x, y1, y2, c;
	q(int type, int x, int y1, int y2, int c) : type(type), x(x), y1(y1), y2(y2), c(c){}
	q(){}
}ope[maxn];

void recover(){
	int op, type, x, y1, y2, z;
	rep(i, 1, m){
		int type = ope[i].type, x = ope[i].x, y1 = ope[i].y1, y2 = ope[i].y2, z = ope[i].c;
		if (type == 1){
			add(z, x, y1, -1);
		} 
	}
	cs = m = 0; 
}

int main(){
	int op, type, x, y, y1, y2, z;
	cerr << sizeof(c) << endl;
	while (1){
		while (scanf("%d", &op) == 1 && !op);
		if (op == 3) break;
		m = 0;
		while (op == 1 || op == 2) {
			if (op == 1){
				scanf("%d%d%d", &x, &y, &z);
				ope[++m] = q(1, x, y, y, z);
				lis[++cs] = x;
			}
			else {
				scanf("%d%d%d", &x, &y, &z);
				ope[++m] = q(2, x, y, z, -1);
				lis[++cs] = x;
			} 
			scanf("%d", &op);
		}
		sort(lis + 1, lis + 1 + cs);
		cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
		int mic = 51, mxc = -1;
		rep(i, 1, m) {
			ope[i].x = lower_bound(lis + 1, lis + 1 + cs, ope[i].x) - lis;
			if (ope[i].type == 1) mic = min(mic, ope[i].c), mxc = max(mxc, ope[i].c);
		}
		rep(i, 1, m){
			int type = ope[i].type, x = ope[i].x, y1 = ope[i].y1, y2 = ope[i].y2, z = ope[i].c;
			if (type == 1){
				add(z, x, y1, 1);
			}
			else {
				int res = 0;
				rep(cc, mic, mxc) res += get(cc, x, y1, y2); 
				printf("%d\n", res);
			}
		} 
		recover();
		if (op == 3) break;
	}
	return 0;
}
