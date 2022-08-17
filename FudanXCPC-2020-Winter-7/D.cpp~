#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 400020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

using namespace std;


char s[maxn];

int main(){
	freopen("D.in", "r", stdin);
	
	int n;
	scanf("%d", &n);
	scanf("%s", s + 1);
	int a = 0, b = 0, na = 0, nb = 0;
	rep(i, 1, (n >> 1)) {
		if (s[i] == '?') na++;
		else a += s[i] - '0';
	}
	rep(i, (1 + (n >> 1)), n){
		if (s[i] == '?') nb++;
		else b += s[i] - '0';
	}
	if (a < b) swap(a, b), swap(na, nb);
	if (a == b){
		if (na == nb) {printf("Bicarp"); return 0;}
		else {printf("Monocarp"); return 0;}
	}
	else {
		if (na >= nb) {printf("Monocarp"); return 0;}
		else {
			int d = a - b;
			int k = d / 9;
			int r = d % 9;
			int nd_2 = (nb - na) >> 1;
			if (nd_2 != k) {printf("Monocarp"); return 0;}
			else {
				if (r) {printf("Monocarp"); return 0;}
				else {printf("Bicarp"); return 0;}
			}
		}
	}
	//Bicarp {printf("Bicarp"); return 0;}
	//Monocarp {printf("Monocarp"); return 0;}
	assert(false);
	return 0;
}

