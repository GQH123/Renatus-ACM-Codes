#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define PII pair<int, int>
const int MAXN = 300005;
int n, a[MAXN];
LL sm[MAXN];
LL ans;
PII mx[MAXN << 2];
#define MID ((l + r) >> 1)
void Build(int i, int l, int r) {
    if(l == r) {
        mx[i] = PII(a[l], l);
        return;
    }
    Build(i << 1, l, MID);
    Build(i<<1|1,MID+1,r);
    mx[i] = max(mx[i << 1], mx[i<<1|1]);
}
PII Find(int i, int l, int r, int L, int R) {
    if(l > R || L > r) return PII(0, 0);
    if(L <= l && r <= R) return mx[i];
    return max(Find(i << 1, l, MID, L, R),
        Find(i << 1 | 1, MID + 1, r, L, R));
}
int BSl(int L, int p, int R) {
    int l = L, r = p, mid, ans = p + 1;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(sm[R] - sm[mid-1] < (LL)a[p] * 2) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return ans;
}
int BSr(int L, int p, int R) {
    int l = p, r = R, mid, ans = p - 1;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(sm[mid] - sm[L-1] < (LL)a[p] * 2) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    return ans;
}
void work(int l, int r) {
    if(l > r) return;
    PII tmp = Find(1, 1, n, l, r);
    int p = tmp.second;
    if(p - l <= r - p) {
        for(int i = l; i <= p; ++ i)
            ans += r - BSr(i, p, r);
    } else {
        for(int i = p; i <= r; ++ i)
            ans += BSl(l, p, i) - l;
    }
    work(l, p-1);
    work(p+1, r);
}
int main() {
    //freopen("input", "r", stdin);
    int T; cin >> T;
    while(T --) {
        ans = 0;
        cin >> n;
        for(int i = 1; i <= n; ++ i) {
            scanf("%d", a + i);
            sm[i] = sm[i-1] + a[i];
        }
        Build(1, 1, n);
        work(1, n);
        cout << ans << endl;
    }
    return 0;
}
