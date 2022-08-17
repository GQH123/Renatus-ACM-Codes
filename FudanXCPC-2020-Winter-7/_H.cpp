#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 3020
#define maxm 
#define maxr 100000
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

map<ll, int> s;
int n;
ll a[maxn];

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int main(){
	
	scanf("%d", &n);
	rep(i, 1, n) read(a[i]);
	int mx = 0;
	per(i, n - 1, 1){
		rep(j, i + 1, n){
			ll d = a[j] - a[i];
			//int& ans = s[d];
		}
	}
	printf("%d", mx);
	return 0;
}

