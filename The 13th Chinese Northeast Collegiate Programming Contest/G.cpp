#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 200020
#define pb push_back 
#define pll pair<ll, ll>
#define fi first
#define se second
#define ll long long int 
#define lowbit(x) (x & -x)
using namespace std;   


int n;
int x[maxn], y[maxn], a[maxn], b[maxn];
int lis[maxn << 2], cs = 0;
namespace PRE{//get
	ll c[maxn << 2];
	void add(int x, int v){	
		while (x <= cs){
			c[x] += v;
			x += lowbit(x);
		}
	}
	ll get(int x){
		ll ans = 0;
		while (x){
			ans += c[x];
			x -= lowbit(x);
		}
		return ans;
	}
}
namespace SUF{
	ll c[maxn << 2];
	void add(int x, int v){	
		while (x){
			c[x] += v;
			x -= lowbit(x);
		}
	}
	ll get(int x){
		ll ans = 0;
		while (x <= cs){
			ans += c[x];
			x += lowbit(x);
		}
		return ans;
	} 
}

ll play(int* x, int* y){
	rep(i, 1, n) SUF :: add(x[i], lis[x[i]]); 
	int ptrx = 1, ptry = 1;
	ll ans1 = -1; 
	//ll cx = -1;
	rep(i, 1, cs){
		while (ptrx <= n && x[ptrx] == i) SUF :: add(i, -lis[i]), ptrx++;
		while (ptry <= n && y[ptry] == i) PRE :: add(i, lis[i]), ptry++;
		ll d = SUF :: get(i) - (n - ptrx + 1) * (ll)lis[i] + (ptry - 1) * (ll)lis[i] - PRE :: get(i);
		//ll _ans1 = ans1;
		ans1 = (ans1 == -1) ? d : min(ans1, d);
		//if (ans1 != _ans1) cx = i;
	}
	rep(i, 1, cs) PRE :: c[i] = SUF :: c[i] = 0;
	//cerr << cx << ' ' << lis[cx] << endl;
	return ans1;
}

int main(){	  
	int T;
	scanf("%d", &T);
	while (T--){ 
		scanf("%d", &n);  
		rep(i, 1, n) scanf("%d%d%d%d", x + i, a + i, y + i, b + i), lis[++cs] = a[i], lis[++cs] = b[i], lis[++cs] = x[i], lis[++cs] = y[i];
		sort(lis + 1, lis + 1 + cs);
		cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
		rep(i, 1, n){
			x[i] = lower_bound(lis + 1, lis + 1 + cs, x[i]) - lis;
			y[i] = lower_bound(lis + 1, lis + 1 + cs, y[i]) - lis;
			a[i] = lower_bound(lis + 1, lis + 1 + cs, a[i]) - lis;
			b[i] = lower_bound(lis + 1, lis + 1 + cs, b[i]) - lis;
		}
		sort(x + 1, x + 1 + n);
		sort(y + 1, y + 1 + n);
		sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + n);
		
		ll ans1 = play(x, y), ans2 = play(a, b);
		printf("%lld\n", ans1 + ans2);
		//cerr << ans1 << ' ' << ans2 << endl;
		
		cs = 0;
	}
	return 0;
}
