#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 500020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

using namespace std;

int n, k;
char s[maxn << 1];

int tot = 1, last = 1, pre[maxn << 1], son[maxn << 1][30], ml[maxn << 1];
void extend(int w){
	int p = ++tot, x = last, r, q;
	for (ml[last = p] = ml[x] + 1; x && !son[x][w]; x = pre[x]) son[x][w] = p;
	if (!x) pre[p] = 1;
	else if (ml[x] + 1 == ml[q = son[x][w]]) pre[p] = q;
	else {
		pre[r = ++tot] = pre[q]; memcpy(son[r], son[q], sizeof son[r]);
		ml[r] = ml[x] + 1; pre[p] = pre[q] = r;
		for (; x && son[x][w] == q; x = pre[x]) son[x][w] = r;
	}
}

int main(){
	freopen("G.in", "r", stdin);
	
	scanf("%s", s + 1);
	n = strlen(s + 1);
	rep(i, 1, n) extend(s[i] - 'A' + 1); 
	scanf("%d", &k);
	//rep(i, 1, 26) printf("%d ", son[1][i]); printf("\n");
	rep(i, 1, k){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int ans = 0, now = 1;
		rep(j, 1, n){
			if (now != 1){
				if (son[now][s[j] - 'A' + 1]) now = son[now][s[j] - 'A' + 1];
				else now = 1;
			}
			if (now == 1) {
				if (!son[now][s[j] - 'A' + 1]) {
					ans = -1;
					break;
				}
				else ans++, now = son[now][s[j] - 'A' + 1];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

