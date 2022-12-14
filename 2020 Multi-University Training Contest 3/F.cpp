#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxb 22
#define maxs 20020
#define ll long long int 
using namespace std;

int num[maxb];

struct ele{
	int num[maxb];
}lis[maxb][maxs], op;
int l[maxb]; 

void DFS(int n, int pos, int rest, int num_rest){
	if (pos == n + 1) {
		if (rest) return;
		per(i, maxb - 1, 0) {
			if (op.num[i]) {
				if (op.num[i] != 1) return;
				break;
			}
		}
		lis[n][++l[n]] = op;
		return;
	}
	if (rest && (rest < pos || !num_rest)) return;
	rep(i, 0, n) {
		if (rest < pos * i || num_rest < i) return;
		num[pos] = i;
		DFS(n, pos + 1, rest - i * pos, num_rest - i);
	}
}

ll C[maxb][maxb];
void init(){
	C[0][0] = 1;
	srep(i, 1, maxb) {
		C[i][0] = 1;
		srep(j, 1, maxb) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);
		}
	}
	rep(n, 1, 19) DFS(n, 1, n, 10);//cerr << l[n] << endl;
}

namespace CAL{
	int nnum[maxb], ct = 0, d;
	void dep(ll x){
		ct = 0;
		while (x) nnum[ct++] = x % 10, x /= 10;
	}

	int times[maxb], _num[maxb];
	inline ll play(ll x){ 
		if (x < 10) {
			return (d <= x) ? 1 : 0;
		}
		ll res = 0;
		dep(x);
		per(i, ct - 1, 0) {
			srep(j, 0, nnum[i]) {
				if (times[j]) _num[times[j]]--;
				times[j]++;
				_num[times[j]]++;
				rep(k, 1, l[i]) {
					bool first = 1;
					per(_l, i, 0) {
						if (lis[i][k].num[_l]) {
							if (first) {
								if (lis[i][k].num[_l] < _num
							}
							else first = 0;
						}
					}
				} 
			}
		}
		return res;
	}
}

int main(){
	init();
	int T; scanf("%d", &T);
	while (T--){
		scanf("%lld%lld", &x, &y);
		printf("%lld\n", play(y) - play(x - 1));
	}
	return 0;
}
