#include<bits/stdc++.h>
#define maxn 2000005
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
//#define M 998244353
//#define M 1000000007
//#define M 1000000009
using namespace std;

int n;
char s[maxn];
bool vis[maxn];
/*int num[maxn];
int pos[3][maxn];
int len[3];
int lk[maxn];*/
int main(){
    #ifndef ONLINE_JUDGE    
        freopen("E.in", "r", stdin);
    #endif
    scanf("%s", s + 1); n = strlen(s + 1);
    /*rep(i, 1, n) pos[s[i] - 'a'][++len[s[i] - 'a']] = i; 
    rep(i, 0, 2){
    	int l = 1, r = len[i];
    	while (l <= len[i]){
    		int x = min(pos[i][l], pos[i][r]);
    		int y = max(pos[i][l], pos[i][r]);
    		lk[x] = y;
    		lk[y] = x;
    		num[x]++, num[y + 1]--;
    		l++, r--; 
    	}
    }
    rep(i, 1, n + 1) num[i] += num[i - 1];
    int mx = 0, mxp = -1;
    rep(i, 1, n) if (num[i] > mx) mx = num[i], mxp = i; 
    if (mx < (n >> 1)) {
    	printf("IMPOSSIBLE");
    	return 0;
    }
    rep(i, 1, n){
    	int x = min(i, lk[i]), y = max(i, lk[i]);
    	if (x <= mxp && mxp <= y) printf("%c", s[i]);
    }*/
    int l = 1, r = n, ans = 0;
    while (l <= r){
    	if (s[l] == s[r]) vis[l] = vis[r] = 1, ans += 2, l++, r--;
		else if (l + 1 < r && s[l + 1] == s[r]) vis[l + 1] = vis[r] = 1, ans += 2, l += 2, r--;
		else if (r - 1 > l && s[l] == s[r - 1]) vis[l] = vis[r - 1] = 1, ans += 2, r -= 2, l++;
		else if (l + 1 < r - 1 && s[l + 1] == s[r - 1]) vis[l + 1] = vis[r - 1] = 1, ans += 2, l += 2, r -= 2;
		else l++, r--;
    }
    if (l == r) ans++, vis[l] = 1;
    if (ans < (n >> 1))  {
    	printf("IMPOSSIBLE");
    	return 0;
    }
    rep(i, 1, n) if (vis[i]) printf("%c", s[i]); 
    return 0;
}

