#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define ull unsigned long long int 
using namespace std;

char s[1000000]; int n;
int a[1000000];

int main(){
	
	/*
	long double now = 2, res = 0;
	rep(i, 1, n){
		if (s[i] - '0') res += now;
		now = now / 2.0;
	}
	printf("%.30Lf", res);
	*/ 
	/*
	scanf("%s", s + 1); n = strlen(s + 1);
	rep(i, 1, n){
		int now = s[i], _i = i;
		while (i <= n && s[i] == now) i++; i--;
		printf("%d\n", i - _i + 1);
	}
	*/
	/*
	int ct = 0;
	while (++ct, scanf("%d", a + ct) == 1); ct--;
	rep(i, 1, ct){
		int now = a[i], _i = i;
		while (i <= ct && a[i] == now) i++; i--;
		printf("%d %d\n", now, i - _i + 1);
	}
	*/
	
	scanf("%s", s + 1); n = strlen(s + 1);
	for (register int i = 1; i <= n; i += 64){
		ull x = 0;
		srep(j, i, i + 64){
			x = (x << 1) + s[j] - '0';
		}
		printf("%llu\n", x);
	}
	return 0;
}
