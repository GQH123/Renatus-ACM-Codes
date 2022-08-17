#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++) 
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

#define maxn 200020
#define maxm
#define maxp 32
#define maxb 2020
#define maxs 
#define inf 
#define eps
#define M 
#define ll long long int 

int n, q, p, a[maxn], bid[maxn];

int pos[maxn];
int num[maxp][maxb];
int per[maxp][maxb];
int _per[maxp];
int iper[maxp][maxb];
int _iper[maxp];

int getreal(int i){ return per[a[i]][bid[i]]; }
int getrev(int v, int i){ return iper[v][bid[i]]; }

void updadd(int i, int k){ num[a[i]][bid[i]]--, a[i] = getrev((getreal(i) + k) % p, i), num[a[i]][bid[i]]++; }
void add(int l, int r, int k){
	int bl = bid[l], br = bid[r];
	if (bl == br || br - bl == 1){
		rep(i, l, r) updadd(i, k);
	}
	else {
		int ptr = l;
		while (bid[ptr] == bl) {
			updadd(ptr, k);
			ptr++;
		}
		ptr = r;
		while (bid[ptr] == br) {
			updadd(ptr, k); 
			ptr--;
		}
		rep(i, bl + 1, br - 1){
			srep(j, 0, p) _per[j] = (per[j][i] + k) % p, _iper[_per[j]] = j;
			srep(j, 0, p) per[j][i] = _per[j], iper[j][i] = _iper[j];
		}
	}
}
void updmul(int i, int k){ num[a[i]][bid[i]]--, a[i] = getrev(1ll * getreal(i) * k % p, i), num[a[i]][bid[i]]++; }
void mul(int l, int r, int k){
	int bl = bid[l], br = bid[r];
	if (bl == br || br - bl == 1){
		rep(i, l, r) updmul(i, k);
	}
	else {
		int ptr = l;
		while (bid[ptr] == bl) {
			updmul(ptr, k);
			ptr++;
		}
		ptr = r;
		while (bid[ptr] == br) {
			updmul(ptr, k); 
			ptr--;
		} 
		rep(i, bl + 1, br - 1){
			srep(j, 0, p) _per[j] = (1ll * per[j][i] * k) % p, _iper[_per[j]] = j;
			srep(j, 0, p) per[j][i] = _per[j], iper[j][i] = _iper[j];
		}
	}
}
int power(int x, int y){
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = 1ll * ans * con % p;
		con = 1ll * con * con % p;
		y >>= 1;
	}
	return ans;
}
void updpow(int i, int k){ num[a[i]][bid[i]]--, a[i] = getrev(power(getreal(i), k), i), num[a[i]][bid[i]]++; }
void pow(int l, int r, int k){
	int bl = bid[l], br = bid[r];
	if (bl == br || br - bl == 1){
		rep(i, l, r) updpow(i, k);
	}
	else {
		int ptr = l;
		while (bid[ptr] == bl) {
			updpow(ptr, k);
			ptr++;
		}
		ptr = r;
		while (bid[ptr] == br) {
			updpow(ptr, k); 
			ptr--;
		}
		rep(i, bl + 1, br - 1){
			srep(j, 0, p) _per[j] = power(per[j][i], k), _iper[_per[j]] = j;
			srep(j, 0, p) per[j][i] = _per[j], iper[j][i] = _iper[j];
		}
	}
}
#define mo(x) (x = (x >= p) ? (x - p) : x)
int ppow[maxp];
int spow(int l, int r, int k){
	int bl = bid[l], br = bid[r];
	int ans = 0;
	srep(i, 0, p) ppow[i] = power(i, k);
	if (bl == br || br - bl == 1){
		rep(i, l, r) ans += ppow[getreal(i)], mo(ans);
	}
	else {
		int ptr = l;
		while (bid[ptr] == bl) {
			ans += ppow[getreal(ptr)], mo(ans);
			ptr++;
		}
		ptr = r;
		while (bid[ptr] == br) {
			ans += ppow[getreal(ptr)], mo(ans);
			ptr--;
		} 
		rep(i, bl + 1, br - 1) srep(j, 0, p) ans += 1ll * num[j][i] * ppow[per[j][i]] % p, mo(ans); 
	}
	return ans;
}
int prod(int l, int r) {
	int bl = bid[l], br = bid[r];
	int ans = 1;
	if (bl == br || br - bl == 1){
		rep(i, l, r) ans = 1ll * ans * getreal(i) % p;
	}
	else {
		int ptr = l, ans = 1;
		while (bid[ptr] == bl) {
			ans = 1ll * ans * getreal(ptr) % p;
			ptr++;
		}
		ptr = r;
		while (bid[ptr] == br) {
			ans = 1ll * ans * getreal(ptr) % p;
			ptr--;
		}
		rep(i, bl + 1, br - 1) srep(j, 0, p) ans = 1ll * ans * power(per[j][i], num[j][i]) % p, mo(ans); 
	}
	return ans;
}


int main(){
	read(n, p);
	rep(i, 1, n) read(a[i]), a[i] %= p;
	read(q);
	int bsiz = (int)sqrt(30ll * n);
	rep(i, 1, n) {
		bid[i] = (i - 1) / bsiz + 1; 
		num[a[i]][bid[i]]++;
	}
	int bnum = bid[n];
	
	rep(i, 1, bnum) srep(j, 0, p) per[j][i] = j, iper[j][i] = j; 
	
	int t, l, r, k;
	rep(i, 1, q) {
		read(t, l, r, k); 
		switch(t) {
			case 1:
				add(l, r, k);
				break;
			case 2:
				mul(l, r, k);
				break;
			case 3:
				pow(l, r, k);
				break;
			case 4:
				printf("%d\n", spow(l, r, k));
				break;
			case 5:
				printf("%d\n", prod(l, r));
				break;
		}
	}
	return 0;
}
