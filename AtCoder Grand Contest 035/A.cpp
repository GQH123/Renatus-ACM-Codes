#include <bits/stdc++.h>
#define maxn 100015
#define maxm
#define maxb
#define maxr 200000
#define maxs
#define M 
#define pii pair<int, int>
#define pdd pair<double, double>
#define uint unsigned int
#define ull unsigned long long int
#define ll long long int 
#define lowbit(x) x & -x
#define fi first
#define se second
#define pb push_back
#define next NEXT
#define hash HASH
#define ls ch[x][0]
#define rs ch[x][1]
#define pi 3.141592653589793
#define ei 2.718281828459045
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define END return 0
//#define ONLINE_JUDGE
//#define DEBUG
using namespace std;

char *p1, *p2, buffer[maxr];
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = gc();
    x = f ? x : -x;
}
set<int> s;
int n;
int a[maxn];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("A.in", "r", stdin);
    #endif
    read(n);
    rep(i, 1, n) read(a[i]), s.insert(a[i]);
    if (s.size() > 3) {printf("No"); END;}
    else {
        if (n % 3) {printf((s.size() == 1 && (*s.begin() == 0)) ? "Yes" : "No"); END;}
        else {
            if (s.size() == 1) {printf((*s.begin() == 0) ? "Yes" : "No"); END;}
            else if (s.size() == 3){
                int x = *s.begin(); s.erase(s.begin());
                int y = *s.begin(); s.erase(s.begin());
                int z = *s.begin(); s.erase(s.begin());
                if (x ^ y ^ z) {printf("No"); END;}
                else {
                    int cx = 0, cy = 0, cz = 0;
                    rep(i, 1, n) {
                        if (a[i] == x) cx++;
                        else if (a[i] == y) cy++;
                        else cz++;
                    }
                    if (cx == cy && cy == cz) {printf("Yes"); END;}
                    else {printf("No"); END;}
                }
            }
            else {
                int x = *s.begin(); s.erase(s.begin());
                int y = *s.begin(); s.erase(s.begin());
                if (x) {printf("No"); END;}
                int cx = 0, cy = 0;
                rep(i, 1, n) {
                    if (a[i] == x) cx++;
                    else cy++;
                }
                if (cy == (cx << 1)) {printf("Yes"); END;}
                else {printf("No");END;}
            }
        }
    }
    return 0;
}
