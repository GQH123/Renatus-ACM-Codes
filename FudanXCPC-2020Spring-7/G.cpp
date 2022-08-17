#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 200020
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

/*
int ch[maxn][2], root = 0, ct = 0;
int p[maxn], d[maxn], v[maxn];
inline void rotate(int& x, int d){
	int y = ch[x][d]; ch[x][d] = ch[y][d ^ 1], ch[y][d ^ 1] = x; x = y;
}
int insert(int& x, int _v, int fa){
	if (!x) {x = ++ct, v[x] = _v, p[x] = rand(); return d[x] = d[fa] + 1;}
	else {
		int d = _v > v[x];
		int res = insert(ch[x][d], _v, x);
		if (p[ch[x][d]] > p[x]) rotate(x, d);
		return res;
	}
}

int vv[maxn], lis[maxn];
bool cmp(int i, int j){
	return (vv[i] == vv[j]) ? i < j : vv[i] < vv[j];
}
*/

set<int> s;
int n, root, d[maxn], lis[maxn], ch[maxn][2];
bool cmp(int i, int j){
	return (d[i] == d[j]) ? i < j : d[i] < d[j];
}
void getans(int x){
	if (x == root) printf("%d", x);
	else printf(" %d", x);
	if (ch[x][0]) getans(ch[x][0]);
	if (ch[x][1]) getans(ch[x][1]); 
}

int main(){
	//srand(time(NULL));
		//freopen("G.in", "r", stdin);

	int x;
	bool f = 0;
	while (scanf("%d", &n) == 1){  
		/*
		rep(i, 1, n) scanf("%d", &x), vv[x] = insert(root, x, 0), lis[i] = i; 
		sort(lis + 1, lis + 1 + n, cmp);
		rep(i, 1, n) printf("%d ", lis[i]); printf("\n");
		rep(i, 1, ct) ch[i][0] = ch[i][1] = p[i] = d[i] = v[i] = vv[i] = 0;
		root = ct = 0;
		*/
		rep(i, 1, n) {
			scanf("%d", &x);
			if (s.empty()) s.insert(x), d[x] = 1, root = x;
			else {
				set<int> :: iterator it = s.lower_bound(x);
				if (it == s.end()){
					it--;
					assert(!ch[*it][1]);
					d[x] = d[*it] + 1;
					ch[*it][1] = x;
					s.insert(x);
					//if (ch[*it][0] && ch[*it][1]) s.erase(it);
				}
				else {
					if (ch[*it][0]){
						it--;
						assert(!ch[*it][1]);
						d[x] = d[*it] + 1;
						ch[*it][1] = x;
						s.insert(x);
						//if (ch[*it][0] && ch[*it][1]) s.erase(it);
					}
					else {
						d[x] = d[*it] + 1;
						ch[*it][0] = x;
						s.insert(x);
						//if (ch[*it][0] && ch[*it][1]) s.erase(it);
					}
				}
			}
			lis[i] = i; 
		}
		//sort(lis + 1, lis + 1 + n, cmp);
		//rep(i, 1, n) printf("%d ", lis[i]); printf("\n");
		getans(root); 
		rep(i, 1, n) ch[i][0] = ch[i][1] = d[i] = 0;
		s.clear();
		printf("\n");
	}
	return 0;
}

