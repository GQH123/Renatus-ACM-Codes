#include <bits/stdc++.h>
#define maxa 2000020
#define maxn 30
#define maxm
#define maxb
#define maxr 200000
#define maxs
#define maxv 1020
#define M 1000000007
#define pii pair<int, int>
#define pdd pair<double, double>
#define uint unsigned int
#define ull unsigned long long int
#define ll long long int 
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
#define mo(x) (x = (x >= M) ? (x - M) : x)
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

int n; 

bool vis[maxa];
int p[maxa], son[maxa];
int cp = 0;
ll C[maxv][maxv];
void init(int mx){
	rep(i, 2, mx){
		if (!vis[i]) p[++cp] = i, son[i] = cp;
		rep(j, 1, cp){
			if (i * p[j] > mx) break;
			vis[i * p[j]] = 1;
			son[i * p[j]] = j;
			if (i % p[j] == 0) break;
		}
	}
	C[0][0] = 1;
	srep(i, 1, maxv){
		C[i][0] = 1;
		rep(j, 1, i){
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1], mo(C[i][j]);
		}
	}
}

set<int> lis;
set<int> :: iterator it;
int num[maxa];
void dep(int x){
	while(x > 1){
		lis.insert(son[x]);
		num[son[x]]++;
		x /= p[son[x]];
	}
}

ll cal(){
	int d = 1, nnum = 0;
	ll ans = 0, tmp = 1;
	per(siz, n, 1){
		tmp = 1;
		for (it = lis.begin(); it != lis.end(); it++){
			nnum = num[*it];
			tmp = tmp * C[nnum + siz - 1][siz - 1] % M; 
		}
		ans += (M + d * C[n][siz] * tmp % M) % M, mo(ans);
		d = -d; 
	}
	return ans;
}

void recover(){
	for (it = lis.begin(); it != lis.end(); it++) num[*it] = 0; 
	lis.clear(); 
}

int main(){ 

        freopen("A.in", "r", stdin); 
        
    int x;
    init(1000020);
    while (scanf("%d", &n) == 1){
    	rep(i, 1, n) scanf("%d", &x), dep(x);
    	printf("%lld\n", cal());
    	recover();
    } 
    return 0;
}
