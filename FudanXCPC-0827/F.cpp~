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
#define maxn 16
#define maxs 500
using namespace std;

const int inf = 2000000000;

int n, m, k, ct = 0, a[maxn * maxn];
struct ele{
    int num[maxn];
    ele(){ memset(num, 0, sizeof(num)); } 
    bool operator < (const ele& b) const{
        rep(i, 1, m) if (num[i] != b.num[i]) return num[i] < b.num[i];
        return false;
    }
};
map<int, ele> st;
map<ele, int> id;
inline int getx(int id){
    return (id - 1) / m + 1;
}
inline int gety(int id){    
    return (id - 1) % m + 1;
}
set<int> tmp;
int upd(int pos, int s, bool hav){
    int x = getx(pos), y = gety(pos); ele op = st[s];
    int left = (y == 1) ? 0 : op.num[1];
    int up = (x == 1) ? 0 : op.num[m];
    if (hav) {
        if (left && up) {
            ele _op; int mi = min(left, up);
            rep(i, 2, m) {
                _op.num[i] = op.num[i - 1];
                if (_op.num[i] == left || _op.num[i] == up) _op.num[i] = mi;
            }
            _op.num[1] = mi;
            if (!id.count(_op)) id[_op] = ++ct, st[ct] = _op;
            return id[_op];
        }
        else if (!left && !up){
            int mi = -1;
            tmp.clear();
            rep(i, 1, m) if (op.num[i]) tmp.insert(op.num[i]);
            int f = -1;
            rep(i, 1, m) {
                if (!tmp.count(i)) {
                    f = i; break;
                }
            }
            assert(f != -1);
            ele _op;
            rep(i, 2, m) _op.num[i] = op.num[i - 1];
            _op.num[1] = f;
            if (!id.count(_op)) id[_op] = ++ct, st[ct] = _op;
            return id[_op];
        }
        else {
            ele _op;
            rep(i, 2, m) _op.num[i] = op.num[i - 1];
            _op.num[1] = left + up;
            if (!id.count(_op)) id[_op] = ++ct, st[ct] = _op;
            return id[_op];
        }
        
    }
    else {
        if (up) return -1;
        ele _op;
        rep(i, 2, m) _op.num[i] = op.num[i - 1];
        _op.num[1] = 0;
        if (!id.count(_op)) id[_op] = ++ct, st[ct] = _op;
        return id[_op];
    }
}

bool check(int s){
    ele op = st[s];
    tmp.clear();
    rep(i, 1, m) if (op.num[i]) tmp.insert(op.num[i]);
    return tmp.size() <= 1;
}

int idx;
int dp[maxn * maxn][maxs][maxn * maxn];
int vis[maxn * maxn][maxs][maxn * maxn];
int DP(int pos, int s, int rest){
    if (!rest || pos == n * m + 1) return (check(s)) ? 0 : -inf; 
    if (vis[pos][s][rest] == idx) return dp[pos][s][rest];
    vis[pos][s][rest] = idx;
    int& ans = dp[pos][s][rest]; ans = 0;
    int _s = upd(pos, s, 0);
    if (_s != -1) ans = max(ans, DP(pos + 1, _s, rest));
    if (rest) {
        _s = upd(pos, s, 1);
        if (_s != -1) ans = max(ans, DP(pos + 1, _s, rest - 1) + a[pos]);
    }
    return ans;
}

int main(){
    while (scanf("%d%d%d", &n, &m, &k) == 3){
        id.clear(), st.clear(); ct = 0;
        idx++; printf("Oil : ");
        rep(i, 1, n) rep(j, 1, m) scanf("%d", a + (i - 1) * m + j);
        ele op;
        id[op] = ++ct, st[ct] = op;
        printf("%d\n", DP(1, 1, k)); 
    }
	return 0;
}
