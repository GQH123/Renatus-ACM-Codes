#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxc 53
#define maxn 160020
#define maxm 
#define maxr 1000020
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
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0; 
	while (!('0' <= ch && ch <= '9')) ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
}

int lis[maxn];
int m = 0, cs = 0;

set<int> c[maxn];
set<int> :: iterator it, it2;
void add(int x, int y, int v){
	while (x <= cs){
		if (v == 1) c[x].insert(y);
		else c[x].clear();
		x += lowbit(x);
	}
}
int get(int x, int y1, int y2){
	while (x){
		if (c[x].empty()) {
			x -= lowbit(x);
			continue;
		}
		it = c[x].lower_bound(y1);
		it2 = c[x].upper_bound(y2); 
		x -= lowbit(x);
		if (it == it2) continue;
		else return 1;
	}
	return 0;
}

struct q{
	int type, x, y1, y2, c, res, tim;
	q(int type, int x, int y1, int y2, int c, int tim) : type(type), x(x), y1(y1), y2(y2), c(c), res(0), tim(tim){}
	q(){}
}ope[maxn];

vector<q> G[maxc];

void recover1(int cc){
	int op, type, x, y1, y2, z, si = G[cc].size();
	srep(i, 0, si){
		int type = G[cc][i].type, x = G[cc][i].x, y1 = G[cc][i].y1, y2 = G[cc][i].y2, z = G[cc][i].c; 
		add(x, y1, -1); 
	} 
} 

int main(){
	int op, type, x, y, y1, y2, z;
	//cerr << sizeof(c) << endl;
	while (1){
		while (read(op), !op);
		if (op == 3) break;
		m = 0;
		while (op == 1 || op == 2) {
			if (op == 1){
				read(x), read(y), read(z);
				m++;
				ope[m] = q(1, x, y, y, z, m);
				lis[++cs] = x;
				//G[z].pb(ope[m]);
			}
			else {
				read(x), read(y), read(z);
				m++;
				ope[m] = q(2, x, y, z, -1, m);
				lis[++cs] = x;
				//G[51].pb(ope[m]);
			} 
			read(op);
		}
		sort(lis + 1, lis + 1 + cs);
		cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
		int mic = 51, mxc = -1;
		rep(i, 1, m) {
			ope[i].x = lower_bound(lis + 1, lis + 1 + cs, ope[i].x) - lis;
			if (ope[i].type == 1) {
				mic = min(mic, ope[i].c), mxc = max(mxc, ope[i].c);
				G[ope[i].c].pb(ope[i]);
			}
			else G[51].pb(ope[i]);
		}
		rep(cc, mic, mxc){
			int ptra = 0, ptrb = 0;
			int si = G[cc].size(), si2 = G[51].size();
			while (ptrb != si2) {
				if (ptra < si && G[cc][ptra].tim < G[51][ptrb].tim) {	
					int type = G[cc][ptra].type, x = G[cc][ptra].x, y1 = G[cc][ptra].y1, y2 = G[cc][ptra].y2, z = G[cc][ptra].c;
					add(x, y1, 1);
					ptra++;
				}
				else {
					int type = G[51][ptrb].type, x = G[51][ptrb].x, y1 = G[51][ptrb].y1, y2 = G[51][ptrb].y2, z = G[51][ptrb].c;
					ope[G[51][ptrb].tim].res += get(x, y1, y2); 
					ptrb++;
				}
			}
			/*
			srep(i, 0, si){
				int type = G[cc][i].type, x = G[cc][i].x, y1 = G[cc][i].y1, y2 = G[cc][i].y2, z = G[cc][i].c;
				if (type == 1 && z == cc){
					add(x, y1, 1);
				}
				else {
					ope[i].res += get(x, y1, y2); 
					//printf("%d\n", res);
				}
			} 
			*/
			recover1(cc);
		}
		rep(i, 1, m) if (ope[i].type == 2) printf("%d\n", ope[i].res); 
		rep(cc, mic, mxc) G[cc].clear(); G[51].clear();
		cs = m = 0; 
		if (op == 3) break;
	}
	return 0;
}
