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
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 220
#define maxm 100020
#define maxs
#define maxb
#define M 
#define eps 1e-8
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

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

int n, m;
struct edge{
	int next, to; long double times;
	edge(int next, int to, long double times) : next(next), to(to), times(times){}
	edge(){}
}e[maxm << 1];
int h[maxn], cnt = 1, in[maxn];
void Add_Edge(int x, int y, long double times){
	e[++cnt] = edge(h[x], y, times);
	h[x] = cnt; 
	in[y]++;
}
long double s;
long double val[maxn];
int _in[maxn];
int lis[maxn], head = 0, tail = 0;
void process(){
	rep(i, 1, n) _in[i] = in[i], val[i] = 0; head = tail = 0;
	lis[++head] = 1, val[1] = 1.0;
	long double mx = 0;
	while (head != tail){	
		int x = lis[++tail];
		mx = max(mx, val[x]);
		if (val[x] >= s - eps) return true;
		erep(i, x){
			int op = e[i].to;
			val[op] += e[i].times * val[x];
			if (val[op] >= s - eps) return true;
			_in[op]--;
			if (!_in[op]) lis[++head] = op;
		}
	}
	//cout << head << ' ' << tail << endl;
	//assert(head == n && tail == n);
	return false;
}
/*
long double solve(long double l, long double r){
	int T = 200;
	while (T--){
		long double mid = (r + l) / 2.0;
		if (judge(mid)) r = mid;
		else l = mid;
	}
	return l;
}
*/
void recover(){
	rep(i, 1, n) h[i] = in[i] = 0; cnt = 1;
}
class Solution {
public:
    /**
     * @param n: the number of loudspeaker
     * @param minVolume: the minVolume the micro 
     * @param maxVolume: the maxVolume the micro 
     * @param edges: the edges
     * @param times: the times of edge
     * @param s: the volume you need
     * @return: return the min volume the micro need 
     */
    double minMicro(int _n, int minVolume, int maxVolume, vector<vector<int>> edges, vector<double> times, double _s) {
        // write your code here
        n = _n, m = edges.size(), s = _s;
        srep(i, 0, m){
        	int x = edges[i][0], y = edges[i][1];
        	Add_Edge(x, y, times[i]);
        }
        //long double res = solve(minVolume, maxVolume);
        process();
        long double mx = 0;
        rep(i, 1, n) mx = max(mx, val[i]); 
        if (!judge(res)) {recover(); return -1;}
        else {recover(); return res; }
    }
};

int main(){ 
	cout << Solution().minMicro(4, 1, 3, {{1,2},{1,3},{2,3},{3,4},{1,4}}, {2.0,3.0,1.0,2.0,1.0}, 8.0) << endl;
	
	return 0;
}

