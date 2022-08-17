#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 200020
#define M 1000000007
using namespace std;

int fib[maxn];
void init(){
	fib[0] = fib[1] = 1;
	srep(i, 2, maxn) fib[i] = (fib[i - 1] + fib[i - 2]) % M; 
}
int n;
struct ele{
	char s[20];
	int l;
	void read(){
		scanf("%s", s);
		l = strlen(s);
	}
	bool operator == (const ele b) {
		if (l != b.l) return false;
		srep(i, 0, l) if (s[i] != b.s[i]) return false; 
		return true;
	}
}op1, op2; 
int main(){
	init();
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		int res = n;
		rep(i, 1, n) {
			op1.read();
			if (i == 1) {
				op2 = op1;
				continue;
			}
			if (op1 == op2) res--;
			op2 = op1;
		}
		printf("%d\n", fib[res]);
	}
	return 0;
}
