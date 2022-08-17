#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 3020
#define ll long long int 
using namespace std;

int n;
ll pre[maxn], suf[maxn], num[maxn];
int f[maxn], m[maxn];
int dp1[maxn][maxn];
int s[maxn][maxn];

void DP1(){
	rep(i, 1, n) {
		s[i][i] = i;
		if (m[i] == 0) dp1[i][i] = 0;
		else dp1[i][i] = (f[i] + m[i] - 1) << 1;
	}
	rep(len, 2, n){
		rep(i, 1, n){
			if (i + len - 1 > n) break;
			int l = i, r = i + len - 1;
			if (num[r] - num[l - 1] == 0) dp1[l][r] = 0, s[l][r] = r;
			else {
				dp1[l][r] = -1;
				rep(k, max(l, s[l][r - 1]), min(r, s[l + 1][r])){
					ll v = (suf[l] - suf[k] - (num[k - 1] - num[l - 1]) * (n - k + 1)) + 
						   (pre[r] - pre[k] - (num[r] - num[k]) * k) + 
						   (f[k] + num[r] - num[l - 1] - 1); 
					if (v < dp1[l][r] || dp1[l][r] == -1) dp1[l][r] = v, s[l][r] = k;
				}
			}
		}
	}
}

ll dp2[maxn];
void DP2(){
	per(i, n, 1){	
		dp2[i] = -1;
		rep(k, i, n) dp2[i] = (dp2[i] == -1) ? (dp1[i][k] + dp2[k + 1]) : min(dp2[i], dp1[i][k] + dp2[k + 1]); 
	}
	printf("%lld\n", dp2[1]);
}


int main(){
	
		freopen("E.in", "r", stdin);
	
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d%d", &m[i], &f[i]);
	rep(i, 1, n) pre[i] = pre[i - 1] + (ll)m[i] * i;
	per(i, n, 1) suf[i] = suf[i + 1] + (ll)m[i] * (n - i + 1);
	rep(i, 1, n) num[i] = num[i - 1] + m[i];
	DP1(), DP2(); 
	return 0;
}
