#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define erep(i, x) for (int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (int& i = cur[x]; i; i = e[i].next)
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
#define maxbuf 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxbuf, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

namespace Fast_Read{
    char buffer[maxbuf], *p1, *p2;
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

#define maxn 2000022
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, a[maxn], b[maxn];

bool vis[maxn];
int ccnt[maxn];
int onloop[maxn], cl = 0;

set<int> visp;
int root = -1;
void dfs(int x) {
    if (vis[x]) {   
        if (visp.count(x))
            root = x;
        else 
            root = -1;
        return;
    }
    vis[x] = 1;
    visp.insert(x);
    dfs(b[x]);
}
void tag(int x) {
    if (onloop[x]) return;
    onloop[x] = cl;
    tag(b[x]);
}
int lis[maxn], cs = 0;

set<int> bel[maxn];

int main(){
    int T;
    read(T);
    while (T--) {
        read(n);
        rep(i, 1, n) read(a[i]), lis[++cs] = a[i];
        sort(lis + 1, lis + 1 + cs);
        cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
        rep(i, 1, n) a[i] = lower_bound(lis + 1, lis + 1 + cs, a[i]) - lis;
        rep(i, 1, n) ccnt[a[i]]++;
        rep(i, 1, n) read(b[i]);
        rep(i, 1, n) {  
            if (vis[i]) continue;
            root = -1;
            visp.clear();
            dfs(i);
            if (root != -1 && !onloop[root]) {
                cl++;
                tag(root);
            }
        }
        rep(i, 1, n) {
            //cerr << onloop[i] << ' ';
            if (onloop[i]) {
                bel[a[i]].insert(onloop[i]);
            }
        }
        //cerr << endl;
        int ans = -1;
        rep(i, 1, n) {  
            if (bel[i].size() == cl) {
                int d = n - ccnt[i];
                ans = (ans == -1) ? d : min(ans, d);
            }
        }
        printf("%d\n", ans);
        rep(i, 1, n) ccnt[i] = onloop[i] = vis[i] = 0, bel[i].clear(); cs = cl = 0;
    }
	return 0;
}

