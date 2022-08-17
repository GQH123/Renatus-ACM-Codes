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
#define M 1000000007
//#define ONLINE_JUDGE
//#define DEBUG
using namespace std;

ll inv2 = 500000004;

char *p1, *p2, buffer[maxr];
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = gc();
    x = f ? x : -x;
}

int n;
int a[maxn];
ll A[maxn], B[maxn], C[maxn], D[maxn];

int main(){ 
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", a + i);
	rep(i, 1, n) A[i] = (A[i - 1] + a[i]) % M;
	rep(i, 1, n) B[i] = (B[i - 1] + (ll)a[i] * a[i] % M) % M;
	rep(i, 1, n) C[i] = (C[i - 1] + (ll)A[i] * A[i] + B[i]) % M;
	rep(i, 1, n) D[i] = (D[i - 1] + A[i]) % M;
	ll res = 0;
	rep(l, 1, n){	
		res += (ll)(n - l + 1) * (A[l - 1] * A[l - 1] - B[l - 1]) % M;
		res += C[n] - C[l - 1];
		res %= M;
		res += M - 2 * A[l - 1] * (D[n] - D[l - 1]) % M;
		res %= M;
	}
	printf("%lld", (ll)res * inv2 % M);
    return 0;
}
