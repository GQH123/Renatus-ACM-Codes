#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 300020
#define maxm 
#define M 
#define ll long long int 
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define fi first
#define se second
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define lowbit(x) (x & -x)
#define maxr 1000000
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') ch = gc(), f = 0;
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
void reads(char* s){
	char ch = gc(); int l = 0;
	while (!('0' <= ch && ch <= '1')) ch = gc();
	while ('0' <= ch && ch <= '1') s[l++] = ch, ch = gc();
	s[l] = '\0';
}

int n;
char a[maxn], b[maxn];
int num0[maxn], num1[maxn];
int num[maxn];
int main(){
	//ios :: sync_with_stdio(false);
	//cin.tie(0);
	int T; read(T);
	while (T--){
		read(n);
		reads(a + 1), reads(b + 1); //a -> b;
		num[n + 1] = 0;
		per(i, n, 1){
			num[i] = num[i + 1];
			if (a[i] != b[i]) num[i]++;
		}
		num0[0] = num1[0] = 0;
		rep(i, 1, n){
			num0[i] = num0[i - 1];
			num1[i] = num1[i - 1];
			if (b[i] == '0') num0[i]++;
			else num1[i]++;
		}
		int res = num[1], ct = 0;
		rep(i, 1, n + 1){	 
			//while (i <= n && a[i] == '1') i++;
			if (i == n + 1 || a[i] == '0'){
				if (i == n + 1){
					int offset = 1;
					res = min(res, ct + offset + num1[i - 1] + 1);
				}
				else {
					int offset = (b[i] == '0') ? 1 : 0;
					res = min(res, ct + num[i + 1] + offset + num1[i - 1] + 1);
				}
				ct++;
			}
			else {
				int offset = (b[i] == '0') ? 1 : 0;
				res = min(res, ct + num[i + 1] + offset + num1[i - 1] + 2);
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
