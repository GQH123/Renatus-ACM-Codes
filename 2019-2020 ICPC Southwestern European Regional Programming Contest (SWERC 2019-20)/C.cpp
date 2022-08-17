#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() getchar()
using namespace std;

int n; 
set<int> s; 
int main(){
	scanf("%d", &n);
	rep(i, 1, n){
		char ch = gc(); int x = 0; bool f = 1;
		while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
		if (ch == '-') f = 0, ch = gc();
		while ('0' <= ch && ch <= '9') {
			x = x * 10 + ch - '0', ch = gc();
			if (x > (n << 1)) f = 0;
		}
		if (f) s.insert(x);
	}
	rep(i, 0, n + 1){
		if (!s.count(i)){
			printf("%d", i);
			return 0;
		}
	} 
	assert(false);
	return 0;
}
