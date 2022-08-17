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

#define maxn 300020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

bool judge(int* a, int n, int* c, int m) {
    int ptr = 1;
    rep(i, 1, n) {
        if (a[i] == c[ptr]) {
            ptr++;
        }
        if (ptr == m + 1) return true;
    }
    return false;
}
int n, m, l;
int a[maxn], b[maxn], c[maxn];
int prea[maxn], sufa[maxn], preb[maxn], sufb[maxn];
set<int> s;
int main(){
    while (scanf("%d%d%d", &n, &m, &l) == 3) {
        rep(i, 1, n) scanf("%d", a + i);
        rep(i, 1, m) scanf("%d", b + i);
        rep(i, 1, l) scanf("%d", c + i);
        int ptr = -1;
        if (!judge(a, n, c, l) || !judge(b, m, c, l)) {
            printf("NO\n");
            goto done;
        }
        ptr = 0;
        rep(i, 1, n) {
            if (ptr == l) break;
            if (a[i] == c[ptr + 1]) {
                prea[++ptr] = i;
            }
        }
        prea[0] = 0, prea[l + 1] = n + 1;
        
        ptr = 0;
        rep(i, 1, m) {
            if (ptr == l) break;
            if (b[i] == c[ptr + 1]) {
                preb[++ptr] = i;
            }
        }
        preb[0] = 0, preb[l + 1] = m + 1;
        
        ptr = l + 1;
        per(i, n, 1) {
            if (ptr == 1) break;
            if (a[i] == c[ptr - 1]) {
                sufa[--ptr] = i;
            }
        }
        sufa[0] = 0, sufa[l + 1] = n + 1;
        
        ptr = l + 1;
        per(i, m, 1) {
            if (ptr == 1) break;
            if (b[i] == c[ptr - 1]) {
                sufb[--ptr] = i;
            }
        }
        sufb[0] = 0, sufb[l + 1] = m + 1;
        
        rep(i, 1, l + 1) {
            int la = prea[i - 1], ra = sufa[i];
            int lb = preb[i - 1], rb = sufb[i];
            s.clear();
            srep(j, la + 1, ra) {
                s.insert(a[j]);
            }
            srep(j, lb + 1, rb) {
                if (s.count(b[j])) {
                    printf("NO\n");
                    goto done;
                }
            }
        }
        printf("YES\n");
        done:;
    }
	return 0;
}

