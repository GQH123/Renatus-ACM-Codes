#include <bits/stdc++.h>
#define maxr 100005
#define maxb 35
#define maxn 200005
#define ll long long int
#define pii pair<int, int>
#define fi first
#define se second
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (ch != '-' && !('0' <= ch && ch <= '9')) ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}

int n;
int a[maxn], b[maxn], c[maxn], two[maxb], nc = 0;
pii solve(int d, int la, int ra, int lb, int rb){
    //printf("%d %d %d\n", d, l, r);
    if (la > ra || lb > rb){
        if (la <= ra) return pii(ra - la + 1, 0);
        if (lb <= rb) return pii(0, rb - lb + 1);
        return pii(0, 0);
    }
    if (!d){
        int mid1 = ra, mid2 = rb;
        rep(i, la, ra){
            if (a[i] & two[d]) {
                mid1 = i - 1;
                break;
            }
        }
        rep(i, lb, rb){
            if (b[i] & two[d]) {
                mid2 = i - 1;
                break;
            }
        }
        int pa = la, pb = lb, ca = 0, cb = 0;
        while (pa <= mid1 && pb <= mid2){
            c[++nc] = a[pa] ^ b[pb];
            pa++, pb++;
        }
        while (pa <= mid1){
            a[la + ca] = a[pa];
            ca++, pa++;
        }
        while (pb <= mid2){
            b[lb + cb] = b[pb];
            cb++, pb++;
        }
        pa = mid1 + 1, pb = mid2 + 1;
        while (pa <= ra && pb <= rb){
            c[++nc] = a[pa] ^ b[pb];
            pa++, pb++;
        }
        while (pa <= ra){
            a[la + ca] = a[pa];
            ca++, pa++;
        }
        while (pb <= rb){
            b[lb + cb] = b[pb];
            cb++, pb++;
        }
        pa = la, pb = lb;
        while (pa <= la + ca - 1 && pb <= lb + cb - 1){
            c[++nc] = a[pa] ^ b[pb];
            pa++, pb++;
        }
        int _ca = 0, _cb = 0;
        while (pa <= la + ca - 1){
            a[la + _ca] = a[pa];
            _ca++, pa++;
        }
        while (pb <= lb + cb - 1){
            b[lb + _cb] = b[pb];
            _cb++, pb++;
        }
        return pii(_ca, _cb);
    }
    else {
        /*int left = r, right = l;
        rep(i, l, r){
            if ((a[i] & two[d]) || (b[i] & two[d])) {
                left = i - 1;
                break;
            }
        }
        per(i, r, l){
            if (!(a[i] & two[d]) || !(b[i] & two[d])) {
                right = i + 1;
                break;
            }
        }
        solve(d - 1, l, left);
        solve(d - 1, right, r);
        solve(d - 1, left + 1, right - 1);*/
        int mid1 = ra, mid2 = rb;
        rep(i, la, ra){
            if (a[i] & two[d]) {
                mid1 = i - 1;
                break;
            }
        }
        rep(i, lb, rb){
            if (b[i] & two[d]) {
                mid2 = i - 1;
                break;
            }
        }
        pii A = solve(d - 1, la, mid1, lb, mid2);
        pii B = solve(d - 1, mid1 + 1, ra, mid2 + 1, rb);
        rep(i, la + A.fi, la + A.fi + B.fi - 1) a[i] = a[mid1 + i - la - A.fi + 1];
        rep(i, lb + A.se, lb + A.se + B.se - 1) b[i] = b[mid2 + i - lb - A.se + 1];
        return solve(d - 1, la, la + A.fi + B.fi - 1, lb, lb + A.se + B.se - 1);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("B.in", "r", stdin);
    #endif
    int T;
    two[0] = 1;
    rep(i, 1, 29) two[i] = two[i - 1] << 1;
    read(T);
    while (T--){
        read(n);
        rep(i, 1, n) read(a[i]);
        rep(i, 1, n) read(b[i]);
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);
        solve(29, 1, n, 1, n);
        sort(c + 1, c + 1 + nc);
        printf("%d", c[1]); rep(i, 2, nc) printf(" %d", c[i]);
        printf("\n");
        nc = 0;
    }
    return 0;
}
