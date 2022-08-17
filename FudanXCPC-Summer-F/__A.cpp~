#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next) 
#define maxs 600020
#define maxr 1000000
#define maxm 
#define M1 1000000007
#define B1 2333
#define M2 1000000009
#define B2 23333
#define ui unsigned int
#define ll long long int 
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define piu pair<int, ui>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define lowbit(x) (x & -x)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0;
	while (!('0' <= ch && ch <= '9')) ch = gc();
	while ('0' <= ch && ch <= '9') x = 10 * x + ch - '0', ch = gc();
}
void reads(char* s){
	char ch = gc(); int l = 0;
	while (!('a' <= ch && ch <= 'z')) ch = gc();
	while ('a' <= ch && ch <= 'z') s[l++] = ch, ch = gc();
	s[l] = '\0';
}

int n, m;

namespace PRE{
	int ct = 0;
	int ch[maxs][26];
	int p[maxs];
	void add(char* s, int id){
		int l = strlen(s), now = 0; 
		srep(i, 0, l) {
			if (!ch[now][s[i] - 'a']) ch[now][s[i] - 'a'] = ++ct;
			now = ch[now][s[i] - 'a']; 
		}
		p[id] = now;
	}
	int tim;
	int idfs[maxs], dfs[maxs], siz[maxs];
	void DFS(int x){
		dfs[x] = ++tim;
		siz[x] = 1;
		idfs[tim] = x;
		rep(i, 0, 25) {
			if (!ch[x][i]) continue;
			DFS(ch[x][i]);
			siz[x] += siz[ch[x][i]];
		}
	}
	int walk(char* s){
		int now = 0, l = strlen(s);
		srep(i, 0, l) {
			if (!ch[now][s[i] - 'a']) return -1;
			now = ch[now][s[i] - 'a'];
		}
		return now;
	}
	void recover(){	
		rep(i, 0, ct) rep(j, 0, 25) ch[i][j] = 0; 
		ct = tim = 0; 
	}
}

namespace SUF{
	int p[maxs];
	int ct = 0;
	int ch[maxs][26];
	void add(char* s, int id){
		int l = strlen(s), now = 0; 
		reverse(s, s + l);  
		srep(i, 0, l) {
			if (!ch[now][s[i] - 'a']) ch[now][s[i] - 'a'] = ++ct;
			now = ch[now][s[i] - 'a']; 
		}
		p[id] = now;
	}
	int tim;
	int idfs[maxs], dfs[maxs], siz[maxs];
	void DFS(int x){
		dfs[x] = ++tim;
		siz[x] = 1;
		idfs[tim] = x;
		rep(i, 0, 25) {
			if (!ch[x][i]) continue;
			DFS(ch[x][i]);
			siz[x] += siz[ch[x][i]];
		}
	}
	int walk(char* s){
		int now = 0, l = strlen(s);
		reverse(s, s + l);
		srep(i, 0, l) {
			if (!ch[now][s[i] - 'a']) return -1;
			now = ch[now][s[i] - 'a'];
		}
		return now;
	}
	void recover(){	
		rep(i, 0, ct) rep(j, 0, 25) ch[i][j] = 0; 
		ct = tim = 0; 
	}
}
int cty;

char s[maxs]; 
struct eve{
	int type, x, y1, y2, d, id; //type = 0, point, type = 1, query
	eve(int type, int x, int y1, int y2, int d, int id) : type(type), x(x), y1(y1), y2(y2), d(d), id(id){}
	eve(){}
	bool operator < (const eve b) const{
		return (x == b.x) ? (type < b.type) : x < b.x;
	}
}q[maxs << 2];
int cq = 0;

int c[maxs];
void add(int x, int v){
	while (x <= cty) {
		c[x] += v;
		x += lowbit(x);
	}
}
int get(int x){
	int ans = 0;
	while (x){
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}
int res[maxs];

void recover(){
	rep(i, 1, cty) c[i] = 0; cq = 0;
	PRE :: recover(), SUF :: recover();
	rep(i, 1, m) res[i] = 0;
}

int main(){
	int T; read(T);
	while (T--){
		read(n), read(m);
		rep(i, 1, n) {
			reads(s);
			PRE :: add(s, i); 
			SUF :: add(s, i); 
		}
		//int type, x, y1, y2, d, id;
		PRE :: DFS(0), SUF :: DFS(0);
		cty = SUF :: ct + 1;
		rep(i, 1, n) q[++cq] = eve(0, PRE :: p[i], SUF :: p[i], -1, -1, i);
		rep(i, 1, m) {
			reads(s);
			int x = PRE :: walk(s);
			reads(s);
			int y = SUF :: walk(s);
			if (x == -1 || y == -1) {
				res[i] = 0;
				continue;
			}
			q[++cq] = eve(1, PRE :: dfs[x] - 1, SUF :: dfs[y], SUF :: dfs[y] + SUF :: siz[y] - 1, -1, i);
			q[++cq] = eve(1, PRE :: dfs[x] + PRE :: siz[x] - 1, SUF :: dfs[y], SUF :: dfs[y] + SUF :: siz[y] - 1, 1, i);
		} 
		sort(q + 1, q + 1 + cq);
		rep(i, 1, cq){
			if (q[i].type == 0) add(q[i].y1, 1);
			else res[q[i].id] += q[i].d * (get(q[i].y2) - get(q[i].y1 - 1)); 
		}
		rep(i, 1, m) printf("%d\n", res[i]);
		recover();
		/*
		DFS(0);
		init(0, ct, 1); 
		rep(i, 1, m) {
			reads(s);
			int x = walk(s);
			reads(s);
			if (x == -1) {
				printf("0\n");
				continue;
			}
			int l = strlen(s);
			play(haa, s, l, B1, M1);
			qd.fi = haa[0];
			play(haaa, s, l, B2);
			qd.se = haaa[0];
			qx = dfs[x], qy = dfs[x] + siz[x] - 1;
			printf("%d\n", get(0, ct, 1));
		} 
		recover();
		*/
	} 
	return 0;
}
