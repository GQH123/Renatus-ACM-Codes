#include <bits/stdc++.h>
#include <bits/extc++.h>
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
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn
#define maxm
#define maxs 70020
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;
using namespace __gnu_pbds;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

//unordered_map<ll, ll> dp;
ll lis[maxs], dp[maxs];
class Solution {
public:
    /**
     * @param n: n players
     * @param p: Show time p
     * @param v: Evaluation time v
     * @return: How soon will the evaluation be completed
     */
    //ll bfs[maxn]; head = tail = 0; 
    int cs = 0;
    long long shortestTime(long long n, int p, int v) {
        // write your code here
        cs = 0;
        if (n == 1) return p + v;
        for (register int i = 1; i <= n; i++){
        	if (n % i == 0) {
        		lis[++cs] = i;
        		if (1ll * i * i != n) lis[++cs] = n / i;
        	}
        	if (1ll * i * i > n) break;
        }
        //cerr << "NUM: " << cs << endl;
        sort(lis + 1, lis + 1 + cs);
        assert(lis[1] == 1);
        rep(i, 1, cs) {
        	dp[i] = 1ll * lis[i] * p + v;
        	rep(j, 2, i) {
        		if (lis[i] % lis[j] == 0) dp[i] = min(dp[i], dp[j] + lis[i] / lis[j] * p + v);
        	}
        }
        return dp[cs];
    }
};

int main(){
	ll n; int p, v;
	while (1) {
		cin >> n >> p >> v;
		cout << Solution().shortestTime(n, p, v) << endl;
	} 
	return 0;
}

