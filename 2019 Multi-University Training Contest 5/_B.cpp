#include <bits/stdc++.h>
#define maxr 100000
#define maxb 30
#define maxn 110019
#define pii pair<int, int>
#define fi first
#define se second
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
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
int n;
int c[maxn];
int nc;
struct Trie{
	int go[maxn * maxb][2];
	int num[maxn * maxb];
	int sz = 1, root = 1;
	void insert(int x){
		int now = root;
		num[now]++;
		per(i, maxb - 1, 0){
			if (x & (1 << i)) {
				if (!go[now][1]) go[now][1] = ++sz; 
				now = go[now][1], num[now]++;
			}
			else {
				if (!go[now][0]) go[now][0] = ++sz;
				now = go[now][0], num[now]++;
			}
		}
	}
	int find_min(int x){
		int now = root, ans = 0;
		per(i, maxb - 1, 0){
			if (x & (1 << i)) {
				if (num[go[now][1]]) now = go[now][1], ans |= (1 << i);  
				else now = go[now][0];
			}
			else {
				if (num[go[now][0]]) now = go[now][0]; 
				else now = go[now][1], ans |= (1 << i); 
			}
		}
		return ans;
	}
	void del(int x){
		int now = root;
		num[now]--;
		per(i, maxb - 1, 0){
			if (x & (1 << i)) now = go[now][1], num[now]--; 
			else now = go[now][0], num[now]--; 
		}
	}
	void clear(){
		rep(i, 1, sz) num[i] = go[i][0] = go[i][1] = 0;
		sz = root = 1;
	}
}A, B;

pii sta[maxn * 3];
int head = 0;
int main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
	#endif
	int T, x;
	read(T);
	while (T--){
		nc = 0;
		read(n);
		rep(i, 1, n) read(x), A.insert(x);
		rep(i, 1, n) read(x), B.insert(x);
		while (A.num[1] || B.num[1]){
			if (!head) sta[++head] = pii(0, A.find_min(0)), A.del(sta[head].se);
			while (1){
				pii op = sta[head];
				if (!op.fi){
					if (!B.num[1]){
						c[++nc] = sta[head].se ^ sta[head - 1].se;
						head -= 2;
						break;
					}
					else {
						int x = B.find_min(op.se);
						if (head == 1) sta[++head] = pii(1, x), B.del(x); 
						else {
							if ((x ^ sta[head].se) > (sta[head].se ^ sta[head - 1].se)){
								c[++nc] = sta[head].se ^ sta[head - 1].se;
								head -= 2;
								break;
							}
							else sta[++head] = pii(1, x), B.del(x); 
						}
					}
				}
				else {
					if (!A.num[1]){
						c[++nc] = sta[head].se ^ sta[head - 1].se;
						head -= 2;
						break;
					}
					else {	
						int x = A.find_min(op.se);
						if (head == 1) sta[++head] = pii(0, x), A.del(x);
						else {
							if ((x ^ sta[head].se) > (sta[head].se ^ sta[head - 1].se)) {
								c[++nc] = sta[head].se ^ sta[head - 1].se;
								head -= 2;
								break;
							}
							else sta[++head] = pii(0, x), A.del(x);
						}
					}
				}
			}
		}
		while (head){
			c[++nc] = sta[head].se ^ sta[head - 1].se;
			head -= 2;
		}
		sort(c + 1, c + 1 + nc);
		printf("%d", c[1]); rep(i, 2, nc) printf(" %d", c[i]); printf("\n");
		A.clear(), B.clear();
	}
	return 0;
}
