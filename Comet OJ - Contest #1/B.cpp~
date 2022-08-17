#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)s
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxn 300020
#define maxm 
#define M 
using namespace std;

char s[maxn];

int main(){
	
		freopen("B.in", "r", stdin);
		
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		ll ans = n;
		int ptr = 1;
		while (ptr <= n && s[ptr] == '0') ptr++;
		int now = 0;
		while (ptr <= n && s[ptr] != '9') now = 1, ptr++; 
		while (ptr <= n && s[ptr] == '9') ans += now, now++, ptr++;
		while (ptr <= n){
			while (ptr <= n && s[ptr] != '9') ptr++; 
			now = 1;
			while (ptr <= n && s[ptr] == '9') ans += now, now++, ptr++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
