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

#define maxn 300021
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, k, a[maxn]; bool vis[maxn];

priority_queue<int, vector<int>, greater<int>> pq;
int res[maxn];

int main(){
	/*
	rep(i, 1, 5) pq.push(i); 
	while (!pq.empty()) cerr << pq.top() << ' ', pq.pop(); cerr << endl;
	return 0;
	*/
	read(n, k);
	rep(i, 1, k) read(a[i]), vis[a[i]] = 1;
	rep(i, 1, n) if (!vis[i]) pq.push(i);
	int cs = 0, _n = n, x;
	rep(i, 1, k) {
		if (i == k) {
			if (!pq.empty()) {
				x = pq.top();
				if (x > a[i] || res[cs] < x) goto workk;
				res[++cs] = x;
				pq.pop();
			}
			workk:;
			pq.push(a[k]);
			while (!pq.empty()) res[_n--] = pq.top(), pq.pop();
		}
		else if (i == 1){
			res[++cs] = a[i];
		}
		else {
			if (!pq.empty()) {
				x = pq.top();
				if (x > a[i] || res[cs] < x) { res[++cs] = a[i]; continue; }
				res[++cs] = x;
				pq.pop();
			}
			res[++cs] = a[i]; 
		}
		
	}
	//assert(cs == _n);
	rep(i, 1, n) printf("%d ", res[i]);
	printf("\n");
	
	return 0;
}

