#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define get GET
using namespace std;

ll m;
int n, p;
char s[20];
char ch[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
ll mi[14];

struct ele{
	char s[4];
	bool operator < (const ele b) const{
		rep(i, 0, 3) if (s[i] != b.s[i]) return s[i] < b.s[i];
		return false;
	}
};
map<ll, ele> get;
char ans[11];
int main(){
	
		freopen("H.in", "r", stdin);
		
	srand(423348);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	scanf("%lld%d", &m, &p);
	mi[0] = 1; rep(i, 1, 13) mi[i] = mi[i - 1] * p % m;
	ll Hash = 0;
	rep(i, 1, n) Hash += s[i] * mi[n - i] % m, Hash %= m;
	//printf("%lld\n", Hash);
	ele op;
	rep(i, 0, 62){
		rep(j, 0, 62){
			rep(k, 0, 62){
				rep(w, 0, 20){
					op.s[0] = ch[i];
					op.s[1] = ch[j];
					op.s[2] = ch[k];
					op.s[3] = ch[w];
					ll hash = (ch[i] * mi[3] % m + ch[j] * mi[2] % m + ch[k] * mi[1] % m + ch[w] * mi[0] % m) % m;
					get[hash] = op;
				}
			}
		}
	}
	while (1){
		rep(i, 1, 10) ans[i] = ch[rand() % 63];
		ll hash = 0;
		rep(i, 1, 10) hash = hash + ans[i] * mi[14 - i] % m, hash %= m;
		hash = (Hash - hash + m) % m;
		//printf("%lld\n", hash);
		if (get.count(hash)) {
			bool f = 0;
			rep(i, 1, 10) if (ans[i] != s[i]) f = 1;
			rep(i, 11, 14) if (s[i] != get[hash].s[i - 11]) f = 1;
			if (!f) goto jump;
			rep(i, 1, 10) printf("%c", ans[i]);
			printf("%s", get[hash].s);
			return 0;
		}
		jump:;
	}
	return 0;
}
