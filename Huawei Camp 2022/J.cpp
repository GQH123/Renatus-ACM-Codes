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

#define maxn 200022
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, a[maxn];

int _cnt = 0, _m = 0;
vector<int> que;
int getsum(){
    _m += 1;
    _cnt += que.size();
    int sum = 0;
    for (auto it: que) sum += a[it];
    que.clear();
    return sum;
}
int query(int l, int r) {
    rep(i, l, r) que.pb(i);
    return getsum();
}

int bound = 1000;
int bs = 4;

void play3(int l, int r, int v) {
    if (l == r || v == 0 || v == (r - l + 1)) return;
    assert(0 <= v && v <= (r - l + 1));
    int mid = ((r - l) >> 1) + l;
    int _v = query(l, mid);
    play3(l, mid, _v);
    play3(mid + 1, r, v - _v);
}

void play2(int l, int r, int v, int bs) {
    if (l == r || v == 0 || v == (r - l + 1)) return;
    assert(0 <= v && v <= (r - l + 1));
    int sum = 0;
    for (int i = l; i <= r; i += bs){
        int l_ = i, r_ = min(r, i+bs-1);
        if (r_ == r) {   
            play3(l_, r_, v - sum);
        }
        else {
            int _v = query(l_, r_);
            sum += _v;
            play3(l_, r_, _v);
        } 
    }
}

void play(int l, int r, int v) {
    if (l == r || v == 0 || v == (r - l + 1)) return;
    assert(0 <= v && v <= (r - l + 1));
    //if ((r - l + 1) > bound){
        int mid = ((r - l) >> 1) + l;
        int _v = query(l, mid);
        play(l, mid, _v);
        play(mid + 1, r, v - _v);
    //}
    //else {
        //play2(l, r, v, bs);
    //}
}



// int bs = 17;

int main(){
    int n = 25000;
    srand(time(NULL));
    rep(i, 1, n) a[i] = ((rand() % 4) <= 0);
    //play(1, n, query(1, n));
    // play(1, n, query(1, n));
    play2(1, n, query(1, n), bs);
    
    
    cerr << n << ':' << _m << ' ' << _cnt << ' ' << endl;
	return 0;
}

