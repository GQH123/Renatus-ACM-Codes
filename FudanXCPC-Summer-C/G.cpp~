#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 2000020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define pc putchar
#define ll long long int 
#define ld long double 
#define lowbit(x) (x & -x)
#define M 
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

int num[maxn], _num[maxn], n;
int main(){
	while (scanf("%d", &n) == 1){
		rep(i, 1, n) num[i] = 0;
		int x;
		rep(i, 1, n) scanf("%d", &x), num[x]++;
		rep(i, 1, n) _num[i] = num[i];
		
		int ans = 0;
		rep(i, 1, n){
			if (num[i] & 1) ans += (num[i] - 1) / 2, num[i] = 1;
			else ans += num[i] / 2, num[i] = 0; 
		}
		rep(i, 1, n - 2){
			if (num[i] && num[i + 1]) {
				if (num[i + 2]) {
					num[i + 1]--, num[i + 2]--;
					ans++;
				}
				else {
					if (_num[i + 2] >= 2){ 
						num[i + 2] += 2;
						num[i + 1]--, num[i + 2]--; 
					}
				}
			}
			/*
			int nnum = min(min(num[i], num[i + 1]), num[i + 2]);
			ans += nnum;
			num[i] -= nnum, num[i + 1] -= nnum, num[i + 2] -= nnum;
			*/
		}
		rep(i, 1, n){
			ans += num[i] / 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}
