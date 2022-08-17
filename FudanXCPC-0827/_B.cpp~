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
#define maxn 
#define maxm
#define T 400
using namespace std;

bool judge(int n){
    rep(A, 1, T){
        rep(B, 1, T){
            if ((1ll * A * A * B + 1) % n != 0) continue;
            if ((1ll * A * A + B) % n != 0) return false;
        }
    }
    return true;
}

int main(){
    rep(n, 1, 5000) {
        if (judge(n)) printf("%d Yes\n", n);
        else printf("%d No\n", n);
    }
	return 0;
}
