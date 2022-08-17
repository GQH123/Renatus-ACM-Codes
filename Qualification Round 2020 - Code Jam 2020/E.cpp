#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define ll long long int
#define ld long double
#define pb push_back
#define pc putchar 
#define cf cout << endl << flush
#define ms(x, a) memset(x, a, sizeof(x))
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define maxn 120
#define maxm
#define maxr 2000000
#define maxs
#define maxb 
using namespace std;

//Don't use read() when doing interactive problems !!!
char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){	
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

//Don't use write() when doing interactive problems !!!
char _num[30];
template <class T> void write(T x, char sep = ' '){
	if (!x) {pc('0'), pc(sep); return;}
	if (x < 0) pc('-'), x = -x;
	int cn = 0;
	while (x) _num[++cn] = x % 10 + '0', x /= 10;
	while (cn) pc(_num[cn--]); pc(sep);
} 

int n;
bool ans[maxn];
bool b1, b2;
int f1 = -1, f2 = -1;

void absorb(int pos, int& now){
	cout << pos; cf; now++;
	cin >> ans[pos];
	cout << n + 1 - pos; cf; now++;
	cin >> ans[n + 1 - pos];
	if (b1) ans[pos] ^= 1, ans[n + 1 - pos] ^= 1;
	if (b2) swap(ans[pos], ans[n + 1 - pos]);
	if (ans[pos] != ans[n + 1 - pos]){
		if (f2 == -1) f2 = pos; 
	}
	else {
		if (f1 == -1) f1 = pos; 
	}
}

void check(int& now){	
	bool op1, op2;
	
	if (f1 != -1){
		cout << f1, cf, now++;
		cin >> op1;
		b1 = (op1 != ans[f1]);
	}
	else cout << 1, cf, now++, cin >> op1;
	
	if (f2 != -1){
		cout << f2, cf, now++;
		cin >> op2; 
		b2 = (b1 ^ (op2 != ans[f2]));
	}
	else cout << 1, cf, now++, cin >> op2;
}

void process(int pos){
	if (b1) ans[pos] ^= 1, ans[n + 1 - pos] ^= 1;
	if (b2) swap(ans[pos], ans[n + 1 - pos]);
}

void recover(){
	rep(i, 1, n) ans[i] = 0;
	b1 = b2 = 0, f1 = f2 = -1;
}

char s[maxn];

int main(){

	//freopen(".in", "r", stdin);
	//ios :: sync_with_stdio(false), cin.tie(0);

	int T;
	//read(T), read(n);
	cin >> T >> n;
	while (T--){
		int now = 1;
		rep(i, 1, (n + 1) >> 1){
			if (now % 10 == 1){
				if (now == 1) absorb(1, now); 
				else check(now), i--;
			}
			else absorb(i, now);
		}
		rep(i, 1, (n + 1) >> 1) process(i);
		rep(i, 1, n) s[i - 1] = ans[i] + '0';
		cout << s, cf;
		char res;
		cin >> res;
		if (res == 'N') return 0;
		recover();
	}
	return 0;
}
