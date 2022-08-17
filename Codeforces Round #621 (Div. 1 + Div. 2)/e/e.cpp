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
#define maxn 6020
#define maxm
#define maxs
#define maxb
#define M 1000000007
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
	if (!x) {putchar('0'), putchar(' '); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(' ');
}

int power(int x, int y){
	int ans = 1, con = x % M;
	while (y){
		if (y & 1) ans = (ll)ans * con % M;
		con = (ll)con * con % M;
		y >>= 1;
	}
	return ans;
}
int getinv(int x){
	return power(x, M - 2);
}

int n, k, f[maxn], a[maxn];
vector<int> pos[maxn];
vector<int> l[maxn];
vector<int> r[maxn]; 
set<int> pre, suf; 
int nump[2][maxn], nums[2][maxn];

void add(int x){	 
	if (pre.count(x)) nums[1][f[x]]++, nump[0][f[x]]--, nump[1][f[x]]++;
	else nums[0][f[x]]++;
	suf.insert(x);  
}
void del(int x){
	if (suf.count(x)) nums[1][f[x]]--, nums[0][f[x]]++, nump[1][f[x]]--;
	else nump[0][f[x]]--;
	pre.erase(x); 
} 

int main(){
	
		//freopen("in2.txt", "r", stdin);
		
	//ios :: sync_with_stdio(false), cin.tie(0);
		
	int x, y;
	read(n), read(k);
	rep(i, 1, n) read(a[i]), pos[a[i]].pb(i);
	rep(i, 1, k){
		read(x), read(y), f[i] = x;
		if (y > pos[x].size()) continue;
		l[pos[x][y - 1]].pb(i);
		r[pos[x][pos[x].size() - y]].pb(i);
		pre.insert(i);
		nump[0][x]++;
	}
	ll ans = 0, mx = 0; 
	per(i, n, 1){
		if (!l[i].empty()){
			int sumx = 0;
			ll asum = 1, tsum = 0;
			rep(j, 1, n){ 
				if (!(nump[0][j] + nums[0][j] + nump[1][j])) continue;  
				int p0 = (nump[0][j]) ? 1 : 0;
				int s0 = (nums[0][j]) ? 1 : 0;
				int b1 = (nump[1][j]) ? 1 : 0;
				int Add = min(2, p0 + s0 + b1);
				sumx += Add;
				if (Add == 1){
					if (p0) tsum = nump[0][j];
					if (s0) tsum = nums[0][j];
					if (b1) tsum = nump[1][j] << 1, tsum %= M;
				}
				else {
					if (p0 + s0 == Add) tsum += (ll)((nump[0][j]) ? nump[0][j] : 1) * ((nums[0][j]) ? nums[0][j] : 1), tsum %= M;
					if (p0 + b1 == Add) tsum += (ll)((nump[0][j]) ? nump[0][j] : 1) * ((nums[1][j]) ? nums[1][j] : 1), tsum %= M; 
					if (s0 + b1 == Add) tsum += (ll)((nums[0][j]) ? nums[0][j] : 1) * ((nump[1][j]) ? nump[1][j] : 1), tsum %= M;  
				} 
				asum = asum * tsum % M;
			}
			if (sumx > mx) mx = sumx, ans = asum;
			else ans += asum, ans %= M;
		}
		int si = l[i].size();
		srep(j, 0, si) del(l[i][j]);
		si = r[i].size();
		srep(j, 0, si) add(r[i][j]); 
	}
	if (mx) write(mx), write(ans);
	else write(mx), write(1);
	return 0;
}

