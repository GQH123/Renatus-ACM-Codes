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

#define maxn 4020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n;
bool rest[maxn];
int cr;

int flag = -1;
vector<int> lis;
int query(int x) {
	cout << "? " << 1 << " " << cr - 1 << endl;
	cout << x << endl;
	rep(i, 1, n) {
		if (i == x) continue;
		if (rest[i]) cout << i << " ";
	}
	cout << endl;
	int res; cin >> res;
	if (!res) rest[x] = 0, lis.pb(x), cr--;
	else flag = x;
	return res;
}

bool judge(int x) {
	cout << "? " << 1 << " " << x << endl;
	cout << flag << endl;
	srep(i, 0, x) {
		cout << lis[i] << " ";
	}
	cout << endl;
	int res; cin >> res;
	if (!res) return true;
	else return false;
}
int solve(int l, int r, int bound) {
	while (l != r) {
		int mid = ((r - l) >> 1) + l;
		if (!judge(mid)) r = mid;
		else l = mid + 1;
		//cerr << l << " " << r << endl;
	}
	if (l == bound) return -1;
	else return lis[l - 1];
}
int main(){
	int T; cin >> T;
	while (T--){
		cin >> n; cr = n; lis.clear();
		rep(i, 1, n) rest[i] = 1;
		rep(i, 1, n) query(i); 
		int k = solve(1, lis.size() + 1, lis.size() + 1); //cerr << k << endl;
		cout << "! " << ((k == -1) ? lis.size() : lis.size() - 1);
		for (auto it : lis){
			if (it == k) continue;
			cout << " " << it;
		}
		cout << endl;
	}
	return 0;
}

