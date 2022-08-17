#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define maxn 2020
#define maxm
using namespace std;

int n; char g[maxn][maxn];
set<int> dp[maxn][maxn];

inline int id(char ch){
    if ('a' <= ch && ch <= 'z') return ch - 'a';
    else return ch - 'A' + 26;
}

set<int> pos[maxn << 1][60];


int main(){
    while (scanf("%d", &n) == 1 && n){
        rep(i, 1, n) scanf("%s", g[i] + 1);
        int offset = n - 1;
        /*
        rep(d, -n + 1, n - 1){
            rep(i, 1, n) {
                if (i + d < 1 || i + d > n) continue;
                pos[d + offset][id(g[i][i + d])].pb(i);
            }
        }
        */
        int res = 0;
        rep(i, 1, n) rep(j, 1, n){
            int left, up;
            //if (j == 1) left = 0; else left = dp[i][j - 1];
            //if (i == 1) up = 0; else up = dp[i - 1][j];
            //int mi = min(left, up), idd = id(g[i][j]);
            //int mx = *lower_bound(pos[j - i + offset][idd].begin(), pos[j - i + offset][idd].end(), i - mi);
            int idd = id(g[i][j]);
            pos[j - i + offset][idd].insert(i);
            int si1 = pos[j - i + offset][idd].size();
            int si2 = dp[i - 1][j].size();
            int si3 = dp[i][j - 1].size();
            if (si1 <= si2 && si1 <= si3){
                for (set<int> :: reverse_iterator it = pos[j - i + offset][idd].rbegin(); it != pos[j - i + offset][idd].rend(); it++){
                    
                }
            }
            if (si2 <= si1 && si2 <= si3){
                for (set<int> :: reverse_iterator it = pos[j - i + offset][idd].rbegin(); it != pos[j - i + offset][idd].rend(); it++){
                    
                }
            }
            if (si3 <= si1 && si3 <= si2){
                for (set<int> :: reverse_iterator it = pos[j - i + offset][idd].rbegin(); it != pos[j - i + offset][idd].rend(); it++){
                    
                }
            }
            //dp[i][j] = i - mx + 1;
            //res = max(res, dp[i][j]);
        }
        //rep(i, 1, n){ rep(j, 1, n) cout << dp[i][j] << ' '; cout << endl;}
        //rep(d, -n + 1, n - 1) rep(i, 0, 52) pos[d + offset][i].clear();
       // rep(i, 1, n) rep(j, 1, n) dp[i][j].clear();
        printf("%d\n", res);
    }
	return 0;
}
