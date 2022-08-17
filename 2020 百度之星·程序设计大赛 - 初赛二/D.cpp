#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 
#define maxm 
#define M 
#define ll long long int 
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define lowbit(x) (x & -x)
using namespace std;



int main(){
	int T, n; char s[10]; int num[11], day[7];
	scanf("%d", &T);
	while (T--){
		rep(i, 0, 9) num[i] = 0;
		scanf("%d", &n);
		rep(i, 1, n) { 
			scanf("%s", s + 1);
			num[s[5] - '0']++;
		}
		int res = n + 1;
		rep(i, 1, 5) day[i] = n;
		rep(a, 1, 5) {
			day[a - 1] += num[0], day[a] -= num[0];
			rep(b, 1, 5){
				day[b - 1] += num[1], day[b] -= num[1];
				rep(c, 1, 5) {
					day[c - 1] += num[2], day[c] -= num[2];
					rep(d, 1, 5) {
						day[d - 1] += num[3], day[d] -= num[3];
						rep(e, 1, 5) {
							day[e - 1] += num[4], day[e] -= num[4];
							rep(f, 1, 5) {
								day[f - 1] += num[5], day[f] -= num[5];
								rep(g, 1, 5) {
									day[g - 1] += num[6], day[g] -= num[6];
									rep(h, 1, 5) {
										day[h - 1] += num[7], day[h] -= num[7];
										rep(i, 1, 5){
											day[i - 1] += num[8], day[i] -= num[8];
											rep(j, 1, 5){
												day[j - 1] += num[9], day[j] -= num[9];
												int mx = 0;
												rep(dayy, 1, 5) mx = max(mx, day[dayy]);
												res = min(res, mx);
											}
											day[5] += num[9];
										}
										day[5] += num[8];
									}
									day[5] += num[7];
								}
								day[5] += num[6];
							}
							day[5] += num[5];
						}
						day[5] += num[4];
					}
					day[5] += num[3];
				}
				day[5] += num[2];
			}
			day[5] += num[1];
		}
		day[5] += num[0];
		printf("%d\n", res);
	} 
	return 0;
}
