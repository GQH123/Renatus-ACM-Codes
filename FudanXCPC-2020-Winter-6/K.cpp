#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 10020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

using namespace std;

int n;

int p = 0;
ll num[maxn], _num[maxn];
void multi(int x){ // multipled 1 x
	p++;
	rep(i, 1, p) _num[i] = num[i - 1];
	rep(i, 0, p) num[i] = num[i] * x, num[i] += _num[i];
}
char s[20020];

int main(){
	freopen("K.in", "r", stdin);
	
	num[0] = 1;
	
	scanf("%s", s + 1);
	n = strlen(s + 1);
	rep(i, 2, n){
		int sol = 2 * i - 1;
		if (s[i - 1] != s[i]) multi(-sol); 
	}
	if (p & 1){
		if (s[1] == 'H') rep(i, 0, p) num[i] = -num[i];
	}
	else{
		if (s[1] == 'A') rep(i, 0, p) num[i] = -num[i];
	}
	printf("%d\n", p);
	per(i, p, 0) printf("%lld ", num[i]);
	return 0;
}

