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

#define maxn 200020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 


struct ele{
	int num[26];
	ele(){memset(num, 0, sizeof num);}
	bool operator < (const ele b) const{
		srep(i, 0, 26) {
			if (num[i] != b.num[i]) return num[i] < b.num[i];
		}
		return false;
	}
};
ele get_ele(vector<char>& s){
	ele res;
	for (auto it: s) {
		res.num[it - '0']++;
	}
	return res;
}

int n, m;
vector<char> s[maxn];
char tmp[maxn];
map<ele, int> h;


int lis[maxn], cs = 0;

int ufs[maxn], siz[maxn];
int find_root(int x){
	return ufs[x] = (x == ufs[x]) ? x : find_root(ufs[x]);
}

bool merge(int x, int y) {
	x = find_root(x), y = find_root(y);
	if (x == y) return false;
	ufs[x] = y;
	siz[y] += siz[x];
	return true;
}


vector<int> cla[maxn];


namespace PRE{
	int ct = 0, ch[maxa][maxsig], num[maxa];
	int nod[maxn];
	void insert(vector<char> s, int id) {
		int now = 0;
		num[now]++;
		for (auto it: s){
			if (!ch[now][it - 'a']) ch[now][it - 'a'] = ++ct;
			now = ch[now][it - 'a'];
			num[now]++;
		}
		nod[id] = now;
	}
	int dfs[maxa], idx = 0, idfs[maxa], siz[maxa];
	void DFS(int now) {
		dfs[now] = ++idx;
		idfs[idx] = now;
		siz[now] = 1;
		srep(i, 0, maxsig) {
			if (ch[now][i]) DFS(ch[now][i]), siz[now] += siz[ch[now][i]];
		}
	}
	void recover(){
		rep(i, 0, ct) ch[i][0] = ch[i][1] = num[i] = 0;
		ct = 0;
	}
};

namespace SUF{
	int ct = 0, ch[maxa][maxsig], num[maxa];
	int nod[maxn];
	void insert(vector<char> s, int id) {
		int now = 0;
		//num[now]++;
		for (auto it: s){
			if (!ch[now][it - 'a']) ch[now][it - 'a'] = ++ct;
			now = ch[now][it - 'a'];
			//num[now]++;
		}
		nod[id] = now;
		num[now]++;
	}
	int dfs[maxa], idx = 0, siz[maxa];
	void DFS(int now) {
		dfs[now] = idx;
		siz[now] = num[now];
		idx += num[now];
		srep(i, 0, maxsig) {
			if (ch[now][i]) DFS(ch[now][i]), siz[now] += siz[ch[now][i]];
		}
	}
	void recover(){
		rep(i, 0, ct) ch[i][0] = ch[i][1] = num[i] = 0;
		ct = 0;
	}
};


pii seg[maxn];
pii pre[maxn];
pii suf[maxn];

int main(){
	int n; read(n);
	rep(i, 1, n) ufs[i] = i, siz[i] = 1;
	char ch;
	rep(i, 1, n) {
		m = reads(tmp);
		srep(j, 0, m) s[i].pb(tmp[j]);
	}
	rep(i, 1, n) {
		ele op = get_ele(s[i]);
		if (h.count(op)) merge(i, h[op]);
		h[op] = i;
	}
	rep(i, 1, n) if (find_root(i) == i) lis[++cs] = siz[i];
	int sum = n; ll res = 0;
	rep(i, 1, cs) {
		sum -= lis[i];
		res += 1ll * lis[i] * sum;
	}
	assert(!sum);
	res = 1ll * res * 1337;
	
	rep(i, 1, cs) {
		res += 2ll * siz[i] * (siz[i] - 1) / 2;
	}
	
	rep(i, 1, n) cla[find_root(i)].pb(i); 
	rep(id, 1, n) {
		if (id != find_root(id)) continue;
		for (auto it: cla[id]) {
			PRE :: insert(s[it], it);
			reverse(s[it].begin(), s[it].end());
			SUF :: insert(s[it], it);
			reverse(s[it].begin(), s[it].end());
		}
		PRE :: DFS(0), SUF :: DFS(0);
		
		for (auto it: cla[id]) {
			cs = 0;
			srep(j, 0, m) {
				int _j = j;
				while (j < m && (!j || s[it][j] >= s[it][j - 1])) j++; j--;
				seg[++cs] = pii(_j, j);
			}
			
			int now = 0, ptr = 0;
			rep(i, 1, cs) {
				while (ptr < seg[i].fi) { 
					now = PRE :: ch[now][s[it][ptr] - 'a'];
					ptr++;
				}
				pre[i] = pii(PRE :: dfs[now], PRE :: dfs[now] + PRE :: siz[now] - 1);
			}
			
			now = 0, ptr = m - 1;
			per(i, cs, 1) {
				while (ptr > seg[i].se) {
					now = SUF :: ch[now][s[it][ptr] - 'a'];
					ptr--;
				}
				suf[i] = pii(SUF :: dfs[now], SUF :: dfs[now] + SUF :: siz[now] - 1);
			}
			
			rep(i, 1, cs) {
				
			}
		} 
		
		PRE :: recover();
		SUF :: recover();
	}
	
	printf("%lld", res);
	return 0;
}

