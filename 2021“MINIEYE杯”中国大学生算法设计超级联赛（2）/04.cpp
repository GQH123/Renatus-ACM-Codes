#pragma GCC optimize(3)

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

#define maxn 200021
#define maxm
#define maxs
#define maxb 17
#define inf 
#define eps
#define M 
#define ll long long int 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

int n, a[maxn], m;

namespace Trie{
	int ch[2][maxn];
	tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> v[maxn];
	int root, ct = 0;
	int create(){
		++ct; 
		return ct;
	}
	void insert(int vv, int idx) {
		if (!root) root = create();
		int now = root;
		v[now].insert(idx);
		per(i, maxb - 1, 0) {
			if (!ch[vv >> i & 1][now]) ch[vv >> i & 1][now] = create();
			now = ch[vv >> i & 1][now];
			v[now].insert(idx);
		} 
	}
	void erase(int vv, int idx){ 
		int now = root;
		v[now].erase(idx);
		per(i, maxb - 1, 0) { 
			now = ch[vv >> i & 1][now];
			v[now].erase(idx);
		} 
	}
	int l, r, a, b;
	int query(int d, int now, int op) {
		if (!now) return 0;
		if (d == -1 || !op) {
			return v[now].order_of_key(r + 1) - v[now].order_of_key(l);
		}
		else {
			if (b >> d & 1) {
				return query(d - 1, ch[a >> d & 1][now], 0) + 
					   query(d - 1, ch[!(a >> d & 1)][now], 1);
			}
			else {
				return query(d - 1, ch[a >> d & 1][now], 1);
			}
		}
	}
};

struct ele{
	int l, r, a, b, id;
	ele(int l, int r, int a, int b, int id) : l(l), r(r), a(a), b(b), id(id){}
	ele(){}
	bool operator < (const ele b) const{
		return r == b.r ? l < b.l : r < b.r;
	}
}q[maxn];

int ans[maxn], last[maxn];

int main(){
	read(n); rep(i, 1, n) read(a[i]);
	int x, y, z, w;
	read(m); rep(i, 1, m) read(x, y, z, w), q[i] = ele(x, y, z, w, i);
	sort(q + 1, q + 1 + m);
	int ptr = 0;
	rep(i, 1, m) {
		while (ptr < q[i].r) {
			++ptr;
			int lastp = last[a[ptr]];
			if (lastp) Trie :: erase(a[ptr], lastp);
			Trie :: insert(a[ptr], ptr);
			last[a[ptr]] = ptr;
		}
		Trie :: l = q[i].l;
		Trie :: r = q[i].r;
		Trie :: a = q[i].a;
		Trie :: b = q[i].b;
		
		ans[q[i].id] = Trie :: query(maxb - 1, Trie :: root, 1);
	}
	rep(i, 1, m) printf("%d\n", ans[i]);
	return 0;
}

