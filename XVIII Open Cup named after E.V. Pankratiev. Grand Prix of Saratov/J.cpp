#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

namespace Fast_Read{
    char buffer[maxr], *p1, *p2;
    template<class T> void read_signed(T& x){
        char ch = gc(); x = 0; bool f = 1;
        while (!isdigit(ch) && ch != '-') ch = gc();
        if (ch == '-') f = 0, ch = gc();
        while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
        x = (f) ? x : -x;
    }
    template<class T, class... Args> void read_signed(T& x, Args&... args){
        read_signed(x), read_signed(args...);
    }
    template<class T> void read_unsigned(T& x){
        char ch = gc(); x = 0;
        while (!isdigit(ch)) ch = gc(); 
        while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = gc(); 
    }
    template<class T, class... Args> void read_unsigned(T& x, Args&... args){
        read_unsigned(x), read_unsigned(args...);
    }
    #define isletter(ch) ('a' <= ch && ch <= 'z')
    int read_string(char* s){
        char ch = gc(); int l = 0;
        while (!isletter(ch)) ch = gc();
        while (isletter(ch)) s[l++] = ch, ch = gc();
        s[l] = '\0'; return l;
    }
}using namespace Fast_Read; 

int _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

#define read read_signed
#define reads read_string 
#define writes puts

#define maxn 400020
#define maxm 25
#define maxs
#define maxb
#define inf 
#define eps
#define M 1000000007
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define ll long long int 

/*
int c[maxd][maxn];
int get(int mod, int x) {
    int res = 0
    while (x <= n) {
        res += c[mod][x];
        mod(res);
        x += lowbit(x);
    }
    return res;
}
void add(int mod, int x, int v) {
    while (x) {
        c[mod][x] += v;
        mo(c[mod][x]);
        x -= lowbit(x);
    }
}
*/ 
int n, m, k, a[maxn];
pii q[maxn];
int res[maxn];
vector<int> tag[maxn];

int qx, qy, qd;
void put(int l, int r, int o) {
    int mid = ((r - l) >> 1) + l;
    if (qx <= mid && mid < qy) {tag[o].pb(qd); return;}
    if (qx <= mid) put(l, mid, o << 1);
    else put(mid + 1, r, o << 1 | 1); 
}

int suf[maxm][maxn], pre[maxm][maxn];
void solve(int l, int r, int o) {
    if (l == r) return;
    int mid = ((r - l) >> 1) + l;
    solve(l, mid, o << 1), solve(mid + 1, r, o << 1 | 1);
    rep(i, l - 1, r + 1) srep(j, 0, m) pre[j][i] = suf[j][i] = 0;
    pre[0][mid] = suf[0][mid + 1] = 1;
    per(i, mid, l) {
        srep(j, 0, m) suf[j][i] = suf[j][i + 1];
        //suf[a[i]][i]++;
        //mo(suf[a[i]][i]);
        srep(j, 0, m) {
            suf[(a[i] + j) % m][i] += suf[j][i + 1];
            mo(suf[(a[i] + j) % m][i]);
        }
    }
    rep(i, mid + 1, r) {
        srep(j, 0, m) pre[j][i] = pre[j][i - 1];
        //pre[a[i]][i]++;
        //mo(pre[a[i]][i]);
        srep(j, 0, m) {
            pre[(a[i] + j) % m][i] += pre[j][i - 1];
            mo(pre[(a[i] + j) % m][i]);
        }
    }
    for (auto it: tag[o]) {
        srep(j, 0, m) {
            res[it] += 1ll * suf[j][q[it].fi] * pre[(m - j) % m][q[it].se] % M;
            mo(res[it]);
        }
    }
}


int main(){
    int x, y;
    read(n, m);
    rep(i, 1, n) read(a[i]), a[i] %= m;
    /*
    per(i, n, 1) {
        add(a[i], i, 1);
        srep(j, 0, m) {
            int num = get(j, i + 1);
            add((a[i] + j) % m, i, num);
        }
    }
    */
    read(k);
    rep(i, 1, k) {
        read(x, y);
        q[i] = pii(x, y);
        if (x == y) {
            res[i] = 1 + (!a[x]);
        }
        else {
            qx = x, qy = y, qd = i;
            put(1, n, 1);
        }
    }
    solve(1, n, 1);
    rep(i, 1, k) printf("%d\n", res[i]);
	return 0;
}

