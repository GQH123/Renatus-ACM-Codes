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

#define maxn 1020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int rten[] = {1, 3, 2, 6, 4, 5}, prten[] = {1, 4, 6, 12, 16, 21};

int num[10], rnum[10];
char s[maxn];


namespace DP{
	int rem[3];
	bool dp[maxn][5][5][5][7];
	int vis[maxn][5][5][5][7];
	int idx;
	bool DP(int pos, int r1, int r2, int r3, int r) {
		if (pos == -1) {
			if (!r1 && !r2 && !r3 && !r) return true;
			return false;
		}
		if (vis[pos][r1][r2][r3][r] == idx) return dp[pos][r1][r2][r3][r];
		vis[pos][r1][r2][r3][r] = idx;
		bool& ans = dp[pos][r1][r2][r3][r];
		ans = false;
		ans |= DP(pos - 1, r1, r2, r3, r);
		if (r1) {
			ans |= DP(pos - 1, r1 - 1, r2, r3, (r + 7 - rten[pos % 6] * rem[0] % 7) % 7);
		}
		if (r2) {
			ans |= DP(pos - 1, r1, r2 - 1, r3, (r + 7 - rten[pos % 6] * rem[1] % 7) % 7);
		}
		if (r3) {
			ans |= DP(pos - 1, r1, r2, r3 - 1, (r + 7 - rten[pos % 6] * rem[2] % 7) % 7);
		}
		return ans;
	}
	int r[3];
	bool work(int rest, int rr){
		idx++;
		return DP(rest - 1, r[0], r[1], r[2], rr);
	}
}
bool judge(int rest, int r) {
	int ct = 0, mx = 0;
	rep(i, 1, 6) {
		mx = max(mx, rnum[i]);
		if (rnum[i]) ct++;
	}
	if (ct >= 4) return true;
	if (ct == 3) {
		if (mx >= 5) return true;
		DP :: rem[0] = DP :: rem[1] = DP :: rem[2] = 0;
		DP :: r[1] = DP :: r[2] = DP :: r[0] = 0;
		
		int cc = 0;
		rep(i, 1, 6) {
			if (rnum[i]) {
				DP :: rem[cc] = i;
				DP :: r[cc] = rnum[i];
				cc++;
			}
		}
		
		return DP :: work(rest, r);
	}
	if (ct == 2) {
		int a = -1, b = -1, ta = -1, tb = -1;
		rep(i, 1, 6) {
			if (rnum[i]) {
				if (a == -1) a = rnum[i], ta = i;
				else b = rnum[i], tb = i;
			}
		} 
		if (a < b) swap(a, b);
		if (a >= 5 && b >= 2) return true;
		
		if (a < 5) {
			int cc = 0;
			rep(i, 1, 6) {
				if (rnum[i]) {
					DP :: rem[cc] = i;
					DP :: r[cc] = rnum[i];
					cc++;
				}
			}
			
			return DP :: work(rest, r);
		}
		else if (b == 1) {
			int rr = (a + b) % 6;
			rr = prten[rr] * ta % 7;
			return rr != r;
		}
	}
	if (ct == 1) {
		rep(i, 1, 6) {
			if (rnum[i]) {
				int rr = rnum[i] % 6;
				return prten[rr] * i % 7 == r;
			}
		}
		assert(false);
		return false;
	}
	if (ct == 0) {
		return r == 0;
	}
}

char res[maxn];

int main(){
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	rep(i, 1, n) num[s[i] - '0']++, rnum[(s[i] - '0') % 7]++;
	
	int nowr = 0;
	per(i, n, 1) {
		bool work = false;
		per(j, 9, 0) {
			if (!num[j]) continue;
			if (i == n && j == 0) {
				printf("-1");
				return 0;
			}
			res[i] = '0' + j, num[j]--, rnum[j % 7]--; nowr += j * rten[(i - 1) % 6] % 7; nowr %= 7;
			if (judge(i - 1, (7 - nowr) % 7)) {
				//nowr += j * rten[(i - 1) % 6] % 7;
				//nowr %= 7;
				work = 1;
				break;
			}
			res[i] = 0, num[j]++, rnum[j % 7]++; nowr += 7 - j * rten[(i - 1) % 6] % 7; nowr %= 7;
		}
		if (!work) {
			printf("-1");
			return 0;
		}
	}
	reverse(res + 1, res + 1 + n);
	printf("%s", res + 1);
	return 0;
}

