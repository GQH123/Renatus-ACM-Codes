#include <bits/stdc++.h>
#define maxn 150019
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0;
	while (!('0' <= ch && ch <= '9')) ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
}

int n, m;
int a[maxn];
set<int> s[maxn << 1];
set<int> :: iterator it;
int qx, qy, qd;
void add(int l, int r, int o){
    if (qx <= l && r <= qy) {
        s[o].insert(qd);
        return;
    }
    int mid = ((r - l) >> 1) + l;
    if (qx <= mid) add(l, mid, o << 1);
    if (qy > mid) add(mid + 1, r, o << 1 | 1);
}
int get(int l, int r, int o){
    it = s[o].lower_bound(qd);
    int ans = n + 1;
    if (it != s[o].end()) ans = *it;
    if (l == r) return ans;
    int mid = ((r - l) >> 1) + l;
    if (qx <= mid) ans = min(ans, get(l, mid, o << 1));
    else ans = min(ans, get(mid + 1, r, o << 1 | 1));
    return ans;
}
void init(int l, int r, int o){
    s[o].clear();
    if (l == r) return;
    int mid = ((r - l) >> 1) + l;
    init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
}

bool vis[maxn];
int lastans = 0;
void recover(){
    lastans = 0;
    init(1, n, 1);
    rep(i, 1, n) vis[i] = 0;
}

int main(){
    int T;
    read(T);
    while (T--){
        read(n), read(m);
        rep(i, 1, n) read(a[i]);
        rep(i, 1, n) {
            qx = 1, qy = i - 1, qd = a[i];
            if (qx <= qy) add(1, n, 1);
        }
        rep(i, 1, m){
            read(qx);
            if (qx == 1){
                read(qx);
                qx ^= lastans;
                if (vis[qx]) continue;
                vis[qx] = 1;
                qy = n, qd = a[qx];
                add(1, n, 1);
            }
            else if (qx == 2){
                read(qx), read(qd);
                qx ^= lastans, qd ^= lastans;
                printf("%d\n", lastans = get(1, n, 1));
            }
        }
        recover();
    }
    return 0;
}
