#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first 
#define se second 
#define maxr 100019
#define maxn 220
#define maxm
#define maxs 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n;
//int mat[maxn][maxn];

struct ele{
	char s[maxn];
	pii cmp;
	void read(){
		scanf("%s", s + 1);
	}
	//int sta[maxn];
	int mat[maxn];
	int pos = 1;
	int cs = 0;
	int sta[maxn];
	void process(){
		/*cmp = pii(0, 0);
		int l = strlen(s + 1);
		rep(i, 1, l){
			if (s[i] == '+') cmp.se++, sta[cs] = 1;
			else if (s[i] == '[') sta[++cs] = 0;
			else if (s[i] == ']') {
				if (sta[cs]) cmp.se = 0, cmp.fi++, cs--, sta[cs] = 1; 
				else cs--;
			}
		}*/
		int l = strlen(s + 1);
		//int pos = 1;
		rep(i, 1, l){
			/*if (s[i] == '+') sta[cs] = 1, mat[pos] = max(mat[pos], cs);
			else if (s[i] == '[') sta[++cs] = 0;
			else if (s[i] == ']') {
				if (sta[cs]) sta[cs - 1] = 1; 
				cs--; 
				if (!cs) pos++;
			}*/
			//else if (s[i] == ']') { cs--; if (!cs) pos++; }
			if (s[i] == '+') {
				if (cs) mat[0] = 0, mat[pos] = max(mat[pos], cs);
				else mat[0]++;
			}
			else if (s[i] == '[') cs++;
			else if (s[i] == ']') { cs--; if (!cs) pos++; }
		}
		while (pos && !mat[pos]) pos--;
		cs = 0;
		rep(i, 1, pos) {
			while (cs && sta[cs] < mat[i]) cs--;
			sta[++cs] = mat[i];
		}
		pos = cs;
		rep(i, 1, pos) mat[i] = sta[i];
	}
	bool operator < (const ele b) const{
		//if (pos != b.pos) return pos < b.pos;
		//per(i, pos, 0) {
			//if (mat[i] != b.mat[i]) return mat[i] < b.mat[i];
		//}
		rep(i, 1, min(pos, b.pos)){
			if (mat[i] != b.mat[i]) return mat[i] < b.mat[i];
		}
		if (pos != b.pos) return pos < b.pos;
		else return mat[0] < b.mat[0];
	}
	void debug(){
		printf("\n");
		printf("%d\n", pos);
		rep(i, 1, pos) printf("%d ", mat[i]);
		printf("\n");
	}
}p[maxn];

struct ele2{
	int id;
	pii cmp;
	ele2(int id, pii cmp) : id(id), cmp(cmp){}
	ele2(){}
	bool operator < (const ele2 b) const{
		return cmp < b.cmp;
	}
}a[maxn];



int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("G.in", "r", stdin);
		#endif
	
	scanf("%d", &n);
	rep(i, 1, n) p[i].read(), p[i].process();
	//rep(i, 1, n) a[i].id = i, a[i].cmp = p[i].cmp;
	//sort(a + 1, a + 1 + n);
	//rep(i, 1, n) printf("%s\n", p[a[i].id].s + 1);
	sort(p + 1, p + 1 + n);
	//rep(i, 1, n) printf("%d ", i), p[i].debug();
	rep(i, 1, n) printf("%s\n", p[i].s + 1); 
	return 0;
}
