#include <bits/stdc++.h>
#define maxn 520
#define maxm
#define maxb 70
#define maxr 200000
#define maxs
#define M 
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
ll a[maxn]; 
char s[maxn]; 

ll x[maxb], y[maxb];

void add(ll* x, ll v){
	per(bi, 62, 0){
		if (v & (1ll << bi)) {
			if (!x[bi]) {x[bi] = v; return;}
			else v ^= x[bi]; 
		} 
	}
}

bool judge(ll* x, ll v){
	per(bi, 62, 0) if (v & (1ll << bi)) v ^= x[bi]; 
	return !v;
}

void recover(ll* x){
	per(bi, 62, 0) x[bi] = 0;
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
    	scanf("%d", &n);
    	rep(i, 1, n) scanf("%lld", a + i);
    	scanf("%s", s + 1); 
    	rep(bi, 0, 62){
    		per(i, n, 1){
    			if (a[i] & (1ll << bi)) {
    				if (s[i] == '1') {
    					add(y, a[i]);
    					break;
					}
					else {
						add(x, a[i]);
					}
    			}
    		}
		}
		rep(i, 0, 62){
			if (!judge(x, y[i])){
				printf("1\n");
				goto done;
			}
		}
		printf("0\n");
		done: recover(x), recover(y);
    }
    return 0;
}
