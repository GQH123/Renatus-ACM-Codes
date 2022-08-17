#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxb 20
#define maxn 600020
#define pb push_back
#define ll long long int 
using namespace std;  

int n, k, root;
int fa[maxb][maxn], d[maxn], num[maxn];
bool ok[maxn]; 

void init(){
	srep(j, 1, maxb) rep(i, 1, n) fa[j][i] = fa[j - 1][fa[j - 1][i]];
}
int getd(int x){
	if (x == root) return 0;
	int ans = 0;
	per(i, maxb - 1, 0){
		if (fa[i][x] == root) continue;
		x = fa[i][x], ans += (1 << i);
	}
	ans++;
	return ans;
}
void mod(int x){
	while (!ok[x] && x != root){
		ok[x] = 1;
		x = fa[0][x];
	}
	ok[x] = 1;
}
int findh(int x){
	if (ok[x]) return x;
	per(i, maxb - 1, 0){
		if (ok[fa[i][x]]) continue;
		x = fa[i][x];
	}
	return x;
}

int isfa[maxn], numbro[maxn], bro[maxn];

int ex[maxn];

int main(){  
	scanf("%d%d", &n, &k);
	rep(i, 1, n) {
		scanf("%d", &fa[0][i]);
		if (fa[0][i] == -1) root = i, fa[0][i] = i;
		else {
			if (isfa[fa[0][i]]) bro[isfa[fa[0][i]]] = i, bro[i] = isfa[fa[0][i]];
			else isfa[fa[0][i]] = i;
		}
	}
	init();
	int mxd = 0;
	rep(i, 1, n) {
		d[i] = getd(i), num[d[i]]++, mxd = max(mxd, d[i]);
		if (bro[i]) numbro[d[i]]++;
	}
	rep(i, 1, mxd) num[i] += num[i - 1], ex[i] = numbro[i];
	//rep(i, 1, n) cerr << d[i] << ' ';
	int _k = k;
	rep(i, 1, n){
		if (!k) break;
		if (ok[i]) continue;
		if (i == root) {ok[i] = 1, k--; continue;}
		int vv = num[d[i] - 1] + 1;
		vv -= (numbro[d[i] - 1] >> 1);
		if (bro[fa[0][i]]) vv++;
		if (vv > _k) continue;
		ex[d[i] - 1] = min(ex[d[i] - 1], _k - vv);
		if (bro[i]){
			if (ok[bro[i]]){
				if (!ex[d[i]]) continue;
				else ex[d[i]]--, numbro[d[i]] -= 2;
			}
		} 
		int hei = findh(i);
		if (d[i] - d[hei] + 1 > k) continue;
		k -= (d[i] - d[hei] + 1);
		mod(i);
	}
	rep(i, 1, n){
		if (ok[i]) printf("1");
		else printf("0");
	}
	return 0;
}


/*
9 7
2
3 
4
-1
3
4
6
2
6
*/


