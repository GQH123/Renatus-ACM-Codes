#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 200020
#define ll long long int 
using namespace std;

int n, k, s;
int ans[maxn], cs = 0;

int main(){
	
		//freopen("C.in", "r", stdin);
	
	cin >> n >> k >> s;
	rep(i, 1, k) printf("%d ", s);
	if (s > n - k) rep(i, 1, n - k) printf("1 ");
	else rep(i, 1, n - k) printf("1000000000 ");
	return 0;
}
