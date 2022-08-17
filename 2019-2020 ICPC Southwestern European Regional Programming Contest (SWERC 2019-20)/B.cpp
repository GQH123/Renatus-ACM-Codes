#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
using namespace std;

int n;

struct ele{
	int l = 0;
	char s[22];
	bool operator < (const ele b) const{
		if (l != b.l) return l < b.l;
		rep(i, 1, l){
			if (s[i] != b.s[i]) return s[i] < b.s[i];
		}
		return false;
	}
}op;

map<ele, int> s;

int main(){
	scanf("%d", &n);
	rep(i, 1, n){
		scanf("%s", op.s + 1);
		op.l = strlen(op.s + 1);
		s[op]++;
		if (s[op] > n / 2){
			printf("%s", op.s + 1);
			return 0;
		}
	}
	printf("NONE");
	return 0;
}
