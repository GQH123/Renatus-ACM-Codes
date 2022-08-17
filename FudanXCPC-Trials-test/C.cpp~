#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 220
using namespace std;

int n, m;
struct ele{
	int l; char s[maxn];
	bool operator < (const ele b) const{
		if (l != b.l) return l < b.l;
		srep(i, 0, l - 1) {
			if (s[i] != b.s[i]) return s[i] < b.s[i];
		}
		return false;
	}
	void read(){
		scanf("%s", s);
		l = strlen(s) + 1;
	}
};
set<ele> s;
ele op;
int main(){
	scanf("%d%d", &n, &m), n++;
	rep(i, 1, m) {
		op.read();
		s.insert(op);
	}
	int ans = 0;
	while (!s.empty()) {
		int l = s.begin() -> l;
		s.erase(s.begin());
		if (n >= l) n -= l;
		else break;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
