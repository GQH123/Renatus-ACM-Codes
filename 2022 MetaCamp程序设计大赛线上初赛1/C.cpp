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

#define maxn 222
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n;
char a[maxn], b[maxn];

struct sta{
    int pa, pb, r, s;
    sta(){}
    sta(int pa, int pb, int r, int s) : pa(pa), pb(pb), r(r), s(s){}
    bool operator < (const sta b) const{
        return pa == b.pa ? pb == b.pb ? r == b.r ? s < b.s : r < b.r : pb < b.pb : pa < b.pa;
    }
};
map<sta, int> dp;

int DP(int pa, int pb, int r, int s) { //r + s + p = 0
    sta x = sta(pa, pb, r, s);
    if (pa == n + 1) return -(abs(r)+abs(s)+abs(-r-s))/2;
    if (dp.count(x)) return dp[x];
    int& ans = dp[x];
    int offset = pa - pb;
    //move
    char ed = b[n - offset];
    char st = a[pa];
    int _r = r, _s = s;
    
    if (st == 'r') _r++;
    else if (st == 's') _s++;
    if (ed == 'r') _r--;
    else if (ed == 's') _s--;
    
    int ans1 = DP(pa + 1, pb, _r, _s); 
    
    //not move
    int ans2 = DP(pa + 1, pb + 1, r, s) + (a[pa] == b[pb]);
    
    ans = max(ans1, ans2);
    return ans;
}

/*
bool mov[maxn];
int DP2(int pa, int pb, int r, int s) { //r + s + p = 0
    sta x = sta(pa, pb, r, s);
    if (pa == n + 1) return -(abs(r)+abs(s)+abs(-r-s))/2;
    if (dp.count(x)) return dp[x];
    int& ans = dp[x];
    int offset = pa - pb;
    //move
    char ed = b[n - offset];
    char st = a[pa];
    int _r = r, _s = s;
    if (st == 'r') _r++;
    else if (st == 's') _s++;
    if (ed == 'r') _r--;
    else if (ed == 's') _s--;
    int ans1 = DP(pa + 1, pb, _r, _s); 
    
    //not move
    int ans2 = DP(pa + 1, pb + 1, r, s) + (a[pa] == b[pb]);
    
    if (ans == ans1) {
        mov[pa] = 1;
        DP2(pa + 1, pb, _r, _s); 
    }
    else {
        mov[pa] = 0;
        DP2(pa + 1, pb + 1, r, s)
    }
}
*/

int main(){
    read(n);
    reads(a + 1);
    reads(b + 1);
    rep(i, 1, n) {
        if (b[i] == 's') {
            b[i] = 'r';
        }
        else if (b[i] == 'p') {
            b[i] = 's';
        }
        else {
            b[i] = 'p';
        }
    }
    
    printf("%d\n", DP(1, 1, 0, 0));
	return 0;
}

