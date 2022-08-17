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
#define maxn 2000020
#define maxm
using namespace std;

char s[maxn];
int main(){
	while (scanf("%s", s + 1) == 1){
		int n = strlen(s + 1), val = 0, mi = n + 1;
		if (n & 1){
			printf("None\n");
			continue;
		}
		rep(i, 1, n) {
			if (s[i] == '(') val++;
			else if (s[i] == ')') val--;
			mi = min(mi, val);
		}
		if (mi < 0) {
			int rest = -mi;
			rep(i, 1, n) {
				if (!rest) break;
				if (s[i] == '?') {
					s[i] = '(';
					rest--;
				}
			}
		}
		mi = n + 1, val = 0;
		rep(i, 1, n) {
			if (s[i] == '(') val++;
			else if (s[i] == ')') val--;
			mi = min(mi, val);
		}
		if (mi < 0) {
			printf("None\n");
			continue;
		}
		
		if (val > 0) {	
			int rest = val;
			per(i, n, 1) { 
				if (!rest) break;
				if (s[i] == '?') {
					s[i] = ')';
					rest--;
				} 
			}
		}
		
		val = 0, mi = n + 1;
		rep(i, 1, n) {
			if (s[i] == '(') val++;
			else if (s[i] == ')') val--;
			mi = min(mi, val);
		}
		if (mi < 0 || val > 0) {
			printf("None\n");
			continue; 
		}
		int ct = 0;
		rep(i, 1, n) {
			if (s[i] == '?') ct++; 
		}
		assert(!(ct & 1));
		if (ct <= 2) printf("Unique\n");
		else printf("Many\n");
		done:;
	}
	return 0;
}
