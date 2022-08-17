#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define maxr 100000
#define maxn 40020
#define maxm
#define M 100007
#define Renatus
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1; int t = 0;
	while (!('0' <= ch && ch <= '9') && ch != '-') {
		ch = gc();
		t++;
		if (t > 100) {
			x = -1;
			return;
		}
	}
	if (ch == '-') f = 0, ch = gc();
	t = 0;
	while ('0' <= ch && ch <= '9') {
		x = (x << 1) + (x << 3) + ch - '0', ch = gc();
		t++;
		if (t > 100) {
			x = -1;
			return;
		}
	}
	x = (f) ? x : -x;
}

template <class T> void readc(T& x){
	char ch = gc();
	int t = 0;
	while (ch != 'a' && ch != 'b') {
		ch = gc();
		t++;
		if (t > 100) {
			x = 'c';
			return;
		}
	}
	x = ch;
}

int n, m;
ll sum[maxn << 2][2], add[maxn << 2][2];
int qx, qy, qd, qd2;
void pd(int l, int r, int o){
	if (add[o][0] && l < r){
		ll& k = add[o][0];
		add[o << 1][0] += k, add[o << 1 | 1][0] += k;
		int mid = ((r - l) >> 1) + l;
		sum[o << 1][0] += k * (mid + 1 - l), sum[o << 1 | 1][0] += k * (r - mid);
		k = 0;
	}
	if (add[o][1] && l < r){
		ll& k = add[o][1];
		add[o << 1][1] += k, add[o << 1 | 1][1] += k;
		int mid = ((r - l) >> 1) + l;
		sum[o << 1][1] += k * (mid + 1 - l), sum[o << 1 | 1][1] += k * (r - mid);
		k = 0;
	}
}
void pu(int o){
	sum[o][0] = sum[o << 1][0] + sum[o << 1 | 1][0];
	sum[o][1] = sum[o << 1][1] + sum[o << 1 | 1][1];
}
void Add(int l, int r, int o){
	pd(l, r, o);
	if (qx <= l && r <= qy) {add[o][qd2] += qd, sum[o][qd2] += (ll)qd * (r - l + 1); return;}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) Add(l, mid, o << 1);
	if (qy > mid) Add(mid + 1, r, o << 1 | 1);
	pu(o);
}
ll get(int l, int r, int o){
	pd(l, r, o);
	if (l == r) return sum[o][qd2];
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) return get(l, mid, o << 1);
	else return get(mid + 1, r, o << 1 | 1);
}


struct mat{
	int num[7][7];
	int r, c;
	void operator = (const mat b)  {
		r = b.r, c = b.c;
		rep(i, 1, r) rep(j, 1, c) num[i][j] = b.num[i][j];
	}
};


mat operator * (mat a, mat b){
	assert(a.c == b.r);
	mat res;
	res.r = a.r, res.c = b.c;
	rep(i, 1, res.r) rep(j, 1, res.c) res.num[i][j] = 0;
	rep(i, 1, a.r) rep(j, 1, b.c) rep(k, 1, a.c)
		res.num[i][j] += ((ll)a.num[i][k] * b.num[k][j]) % M, mo(res.num[i][j]); 
	return res;
}
mat power(mat x, ll y){
	mat ans, con = x;
	ans.r = ans.c = x.r;
	rep(i, 1, ans.r) rep(j, 1, ans.c) ans.num[i][j] = 0;
	rep(i, 1, ans.r) ans.num[i][i] = 1;
	while (y){
		if (y & 1) ans = ans * con;
		con = con * con;
		y >>= 1;
	}
	return ans;
}

ll a[maxn], b[maxn];
ll get_f(ll a, ll b){ //b = 0 ~ 6
	if (a <= b) return 1;
	if (!b) return 0;
	mat dp;
	dp.r = 1, dp.c = b;
	rep(i, 1, b) dp.num[1][i] = 1;
	mat trans;
	trans.r = trans.c = b;
	rep(i, 1, b) rep(j, 1, b) trans.num[i][j] = 0;
	rep(i, 1, b) trans.num[i][1] = 1;
	rep(j, 2, b) trans.num[j - 1][j] = 1;
	trans = power(trans, a - b);
	dp = dp * trans;
	return dp.num[1][1];
}

int main(){
	
	int x, y, z; char op;
	read(n), read(m);
	qx = 1, qy = n, qd2 = 0, qd = 1;
	Add(1, n, 1);
	qd2 = 1;
	Add(1, n, 1);
	ll ans = 0;
	rep(i, 1, m){
		readc(op), read(x), read(y), read(z);
		if (op == 'a') qd2 = 0;
		else if (op == 'b') qd2 = 1;
		else qd2 = 2;
		qd = z;
		if (x <= y) {
			qx = x, qy = y;
			if (qd2 != 2 && x != -1 && y != -1) Add(1, n, 1);
			else goto jump;
		}
		else {
			qx = 1, qy = y;
			if (qd2 != 2 && x != -1 && y != -1) Add(1, n, 1);
			else goto jump;
			qx = x, qy = n;
			if (qd2 != 2 && x != -1 && y != -1) Add(1, n, 1);
			else goto jump;
		}
	}
	
	qd2 = 0;
	rep(i, 1, n) qx = i, a[i] = get(1, n, 1); //printf("%lld ", a[i]);
	//printf("\n");
	qd2 = 1;
	rep(i, 1, n) qx = i, b[i] = get(1, n, 1) % 7; //printf("%lld ", b[i]), b[i] %= 7;
	//printf("\n");
	
	rep(i, 1, n) ans += get_f(a[i], b[i]); 
	printf("%lld\n", ans);
	
	return 0;
	jump: printf("0");
	return 0;
}
