#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x) 
#define maxn 1000120
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std; 

int ch[maxn][2];
int p[maxn], v[maxn], s[maxn], u[maxn];
int root, ct = 0;
inline void pu(int x){
	s[x] = s[ch[x][0]] + s[ch[x][1]] + u[x];
}
void rotate(int& x, int d){
	int k = ch[x][d]; ch[x][d] = ch[k][d ^ 1], ch[k][d ^ 1] = x;
	pu(x), pu(k);
	x = k;
}
void insert(int& x, int _v){
	if (!x) x = ++ct, v[x] = _v, p[x] = rand(), s[x] = u[x] = 1;
	else if (v[x] == _v) s[x]++, u[x]++;
	else {
		int d = (_v > v[x]);
		insert(ch[x][d], _v);
		if (p[ch[x][d]] > p[x]) rotate(x, d);
	} 
	pu(x);
}
int find_val_rank(int x, int rank){
	while (x){
		if (rank <= s[ch[x][0]]) x = ch[x][0];
		else if (rank > s[ch[x][0]] + u[x]) rank -= (s[ch[x][0]] + u[x]), x = ch[x][1];
		else return v[x];
	}
	return -1;
}
void del(int& x, int _v){
	if (v[x] == _v) {
		if (u[x] == 1){
			if (ch[x][0] && ch[x][1]){
				if (p[ch[x][0]] > p[ch[x][1]]) rotate(x, 0), del(ch[x][1], _v);
				else rotate(x, 1), del(ch[x][0], _v);
			}
			else if (ch[x][0]) x = ch[x][0];
			else x = ch[x][1];
		}
		else {u[x]--; return;}
	}
	else {
		int d = (_v > v[x]);
		del(ch[x][d], _v);
	}
	if (x) pu(x);
}

int n, q;

int main(){
	int x;
	scanf("%d%d", &n, &q);
	rep(i, 1, n) scanf("%d", &x), insert(root, x);
	rep(i, 1, q){
		scanf("%d", &x);
		if (x < 0) {
			int _v = find_val_rank(root, -x);
			//cerr << _v << endl;
			assert(_v != -1);
			del(root, _v);
		}
		else insert(root, x);
	}
	if (!s[root]) printf("0");
	else printf("%d", v[root]);
	return 0;
}

