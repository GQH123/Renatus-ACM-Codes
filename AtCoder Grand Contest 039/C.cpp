#include <bits/stdc++.h>
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n;
char s[maxn];
int num[maxn];

int div[maxn];
int ct = 0;

int main(){
	#ifndef ONLINE_JUDGE
		freopen(".in", "r", stdin);
	#endif
	scanf("%d", &n);
	scanf("%s", s + 1);
	rep(i, 1, n) num[i] = s[i] - '0';
	rep(i, 1, n) if (n % i == 0) div[ct++] = i; 
	rep(i, 1, ct){
		int x = div[i];
		//1 +
		bool d = 1;
		for (register int j = 1; j <= n; j += x){
			srep(k, j, j + x){
				if (d){
					
				}
				else {
					
				}
			}
			d ^= 1;
		}
		
		//0 -
		for (register int j = 1; j <= n; j += x){
			srep(k, j, j + x){
				
			}
		}
	}
	return 0;
}
