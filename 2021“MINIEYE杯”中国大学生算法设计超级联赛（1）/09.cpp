#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define maxn 6000021
#define ll long long int 
using namespace std;

int n, m, k, cnt;
struct edge{
    int x, y, c;
    edge(int x, int y, int c) : x(x), y(y), c(c){}
    edge(){}
    bool operator < (const edge b) const{
        return c < b.c;
    }
}e[maxn << 1];

int ufs[maxn], siz[maxn];

int find_root(int x) {
    return ufs[x] = (ufs[x] == x) ? x : find_root(ufs[x]);
}
void merge(int x, int y) {
    x = find_root(x), y = find_root(y);
    if (x == y) return;
    ufs[x] = y;
    siz[y] += siz[x];
    cnt--;
}

void work(){
    int x, y, z;
    scanf("%d%d%d",&n, &m, &k); cnt = n;
    rep(i, 1, n) ufs[i] = i;
    rep(i, 1, m) scanf("%d%d%d", &x, &y, &z), e[i] = edge(x, y, z);
    sort(e + 1, e + 1 + m);

	/*
	rep(i, 1, m) {
		merge(e[i].x, e[i].y);
	}
	if (cnt != 1) {
		printf("???\n");
		return;
	}
	rep(i, 1, n) ufs[i] = i; cnt = n;
	
	graph may not be connected...
	*/
    
    if (k == n) {
        printf("%d\n", 0);
        return;
    }
    
    rep(i, 1, m) {
        int v = e[i].c;
        while (i <= m && e[i].c == v) {
            merge(e[i].x, e[i].y);
            i++;
        }i--;
        if (cnt == k) {
            printf("%d\n", v);
            return;
        }
        else if (cnt < k) {
            printf("-1\n");
            return;
        }
    }
    printf("-1\n");
    return; 
}


int main(){
    int T; scanf("%d", &T);
    while (T--){
        work();
    }
    return 0;
}
