#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 400020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;

int n, m, k;
int a[maxn];

struct ele{
	int id, num;
	ele(int id, int num) : id(id), num(num){}
	ele(){}
	bool operator < (const ele b) const{
		return (num == b.num) ? id < b.id : num > b.num;
	}
};
set<ele> s;

int main(){
	freopen("E.in", "r", stdin);
	
	scanf("%d%d%d", &n, &m, &k);
	int mx = 0;
	rep(i, 1, m) scanf("%d", &a[i]), mx = max(mx, a[i]), s.insert(ele(i, a[i]));
	if ((n - mx + 1) * (ll)k < (ll)mx) {
		printf("-1");
		return 0;
	}
	int last = -1, sum = 0;
	while (!s.empty()) {
		ele op = *s.begin(); s.erase(op);
		if (op.id != last) last = op.id, sum = 1;
		else {
			if (sum < k) sum++;
			else {
				ele _op = *s.begin(); s.erase(_op);
				s.insert(op);
				op.id = _op.id, op.num = _op.num;
				last = op.id, sum = 1;
			}
		}
		printf("%d ", op.id);
		op.num--;
		if (op.num) s.insert(op);
	}
	return 0;
}

