#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 300020
#define maxm 
#define M 
#define ll long long int 
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define fi first
#define se second
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define lowbit(x) (x & -x)
#define maxr 1000000
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') ch = gc(), f = 0;
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
void reads(char* s){
	char ch = gc(); int l = 0;
	while (!('a' <= ch && ch <= 'z')) ch = gc();
	while ('a' <= ch && ch <= 'z') s[l++] = ch, ch = gc();
	s[l] = '\0';
}

int n, l, k;
int res[maxn << 2], a[maxn];
pii lis[maxn];

int sum[maxn << 2], qx, qd;
void init(int l, int r, int o){
	sum[o] = 0;
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
}
void add(int l, int r, int o){
	sum[o] += qd;
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) add(l, mid, o << 1);
	else add(mid + 1, r, o << 1 | 1); 
}
int get(int l, int r, int o){
	if (l == r) return l;
	int mid = ((r - l) >> 1) + l;
	if (sum[o << 1 | 1] >= qd) return get(mid + 1, r, o << 1 | 1);
	else {qd -= sum[o << 1 | 1]; return get(l, mid, o << 1);}
}


int temp[maxn];
ll cal(){

	//int left = n / l * l;
	//rep(i, 1, l) swap(res[left - i + 1], res[l - i + 1]);
	
	//int left = n / l * l;
	//rep(i, 1, l) temp[i] = res[i];
	//rep(i, 1, left - l) res[i] = res[i + l];
	//rep(i, left - l + 1, left) res[i] = temp[i - left + l];
	
	//int left = n / l * l, rest = n - left;
	//rep(i, left + 1, n) temp[i - left] = res[i];
	//per(i, n, n - left + 1) res[i] = res[i - n + left];
	//rep(i, 1, n - left) res[i] = temp[i];
	
	ll ans = 0;
	init(1, n, 1);
	rep(i, 1, n) lis[i] = pii(res[i], i);
	sort(lis + 1, lis + 1 + n);
	rep(i, 1, n) res[i] = lower_bound(lis + 1, lis + 1 + n, pii(res[i], i)) - lis;
	rep(i, 1, l){
		qx = res[i], qd = 1;
		add(1, n, 1);
	}
	rep(i, 1, n + 1 - l){
		qd = k;
		ans += lis[get(1, n, 1)].fi;
		qx = res[i], qd = -1, add(1, n, 1);
		if (i + l <= n) qx = res[i + l], qd = 1, add(1, n, 1);
	}
	return ans;
	
	/*
	ll num = (n - l + 1) / l, res = 0;
	rep(i, 1, num) res += 1ll * l * a[i];
	res += 1ll * k * a[num + 1];
	*/
	
}
int main(){
	//ios :: sync_with_stdio(false);
	//cin.tie(0);
	read(n), read(l), read(k);
	rep(i, 1, n) read(res[i]);
	cout << cal();
	return 0;
}
