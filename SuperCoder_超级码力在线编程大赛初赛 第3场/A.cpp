#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int gcd(int x, int y){
    if (!y) return x;
    return gcd(y, x % y);
}
int main(){
    int x = a, y = b;
    if (y & 1) return 1ll * y * (y - 1) * (y - 2); 
    if (x == y - 2) return 1ll * y * (y - 1) * (y - 2) / 2;
    ll res = 1;
    res = max(res, 1ll * y * (y - 1) * (y - 2) / gcd(y, y - 2));
    res = max(res, 1ll * y * (y - 1) * (y - 3) / gcd(y, y - 3));
    res = max(res, 1ll * (y - 1) * (y - 2) * (y - 3));
    return res; 
}
