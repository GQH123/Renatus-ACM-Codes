#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 1048576
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int inf = 2000000000;

int n, L, R, a[maxn], pre[maxn], dp[maxn];

vector<int> s[maxn << 1];
int he[maxn << 1];
// (dp, id), id < nowid - R then pop
int qx, qy, qd, nowid;
void init(int l, int r, int o){ 
    s[o].clear(); he[o] = 0;
    if (l == r) return;
    int mid = ((r - l) >> 1) + l;
    init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
} 
inline void upd(int o){ 
    while (he[o] < s[o].size() && qd >= dp[s[o].back()]) s[o].pop_back();
    s[o].push_back(nowid - L);
} 
inline int get(int o){ 
    while (he[o] < s[o].size() && s[o][he[o]] < nowid - R) he[o]++;
    
    if (he[o] == s[o].size()) return -inf;
    return dp[s[o][he[o]]];
}
void add(int l, int r, int o){
    upd(o);
    if (l == r) return;
    int mid = ((r - l) >> 1) + l;
    if (qx <= mid) add(l, mid, o << 1);
    else add(mid + 1, r, o << 1 | 1);
}
int get(int l, int r, int o){ 
    if (qx <= l && r <= qy) return get(o);
    int mid = ((r - l) >> 1) + l, ans = -inf;
    if (qx <= mid) ans = max(ans, get(l, mid, o << 1));
    if (qy > mid) ans = max(ans, get(mid + 1, r, o << 1 | 1));
    return ans;
}
int offset = 0, lis[maxn << 1], cs = 0;
int main(){
    int T; scanf("%d", &T);
    while (T--){
        scanf("%d%d%d", &n, &L, &R);
        rep(i, 1, n) scanf("%d", a + i), pre[i] = pre[i - 1] + a[i]; 
        dp[0] = 0; rep(i, 1, n) dp[i] = -inf;
        
        offset = cs = 0;
        rep(i, 1, n) { offset += a[i]; if (i >= L)  lis[++cs] = pre[i] - pre[i - L] - offset; lis[++cs] = -offset; }
        sort(lis + 1, lis + 1 + cs);
        cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
        
        offset = 0;
        init(1, cs, 1);
        rep(i, 1, n){
            offset += a[i], nowid = i;
            if (i >= L) {
                qx = pre[i] - pre[i - L] - offset, qd = dp[i - L];
                qx = lower_bound(lis + 1, lis + 1 + cs, qx) - lis;
                add(1, cs, 1); 
            }
            int zero = lower_bound(lis + 1, lis + 1 + cs, -offset) - lis;
            qx = 1, qy = zero - 1;
            if (qx <= qy) dp[i] = max(dp[i], get(1, cs, 1) - 1);
            qx = qy = zero;
            dp[i] = max(dp[i], get(1, cs, 1));
            qx = zero + 1, qy = cs;
            if (qx <= qy) dp[i] = max(dp[i], get(1, cs, 1) + 1);
        }
        printf("%d\n", dp[n]); 
    }
    return 0;
}
