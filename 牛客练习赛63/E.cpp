#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ll long long int 
#define ld long double
#define lowbit(x) (x & -x)
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define M 
#define B
#define maxn 
#define maxs
#define maxm 
#define maxk
#define maxb
//#define DEBUG
using namespace std;

int n; char s[maxn];
int f[maxn];
void init(){ 
	f[0] = f[1] = 0;
	srep(i, 1, n){
		int now = f[i];
		while (now && s[now] != s[i]) now = f[now];
		f[i + 1] = (s[now] == s[i]) ? now + 1 : 0;
	}
}
int match(char* t){
	int now = 0, ans = 0, l = strlen(t);
	srep(i, 0, l){
		while (now && s[now] != t[i]) now = f[now];
		now = (s[now] == t[i]) ? now + 1 : 0;
		if (now == n) ans++, now = f[now];
	}
	return ans;
}

struct ele{
	char pre[maxn], suf[maxn];
};
void power(ll y){
	
	if (y & 1){
	}
}

int main(){
	ll y;
	scanf("%lld", &y);
	scanf("%s%s%s", a, b, s);
	n = strlen(s);
	init();
	power(y);
	return 0;
}
