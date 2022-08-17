#include <bits/stdc++.h>
#define maxn 300020
#define maxm
#define maxb
#define maxr 200000
#define maxs
#define M 
#define pii pair<int, int>
#define pdd pair<double, double>
#define uint unsigned int
#define ull unsigned long long int
#define ll __int128
#define lowbit(x) x & -x
#define fi first
#define se second
#define pb push_back
#define next NEXT
#define hash HASH
#define ls ch[x][0]
#define rs ch[x][1]
#define pi 3.141592653589793
#define ei 2.718281828459045
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
//#define ONLINE_JUDGE
//#define DEBUG
using namespace std;

char *p1, *p2, buffer[maxr];
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = gc();
    x = f ? x : -x;
} 

int n, m;
char s[maxn];
int pos[maxn];
struct query{
	int l, r;
	query(int l, int r) : l(l), r(r){}
	query(){}
	bool operator < (const query b) const{
		return (pos[l] == pos[b.l]) ? r < b.r : pos[l] < pos[b.l];
	}
}p[maxn];

bool vis[maxn];
void upd(int x){
	if (vis[x]){
		
	}
	else {
	}
	vis[x] ^= 1;
}

int main(){ 
	scanf("%d%d", &n, &m); 
	scanf("%s", s + 1);
	int blo = (int)sqrt(n), x, y;
	rep(i, 1, n) pos[i] = (i - 1) / blo + 1; 
	rep(i, 1, m){
		scanf("%d", &x, &y);
		p[i] = query(x, y);
	}
	sort(p + 1, p + 1 + m);
	rep(i, 1, m){
		
	}
    return 0;
}
