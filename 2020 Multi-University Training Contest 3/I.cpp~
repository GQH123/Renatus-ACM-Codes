#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 200020
using namespace std;

int n; char s[maxn];
int main(){
	int T; scanf("%d", &T);
	while (T--){
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		int star = 0, val = 0, mi = 0;
		rep(i, 1, n) {	
			if (s[i] == '*') star++;
			else if (s[i] == '(') val++;
			else val--;
			if (val < 0 && star < (-val)) {
				printf("No solution!\n");
				goto done;
			}
			mi = min(mi, val);
		}
		if (mi < 0) {
			rep(i, 1, n) {
				if (!mi) break;
				if (s[i] == '*') {
					s[i] = '(';
					val++;
					mi++;
				}
			}
		} 
		if (val >= 0) {
			per(i, n, 1) {
				if (!val) break;
				if (s[i] == '*') {
					s[i] = ')';
					val--; 
				}
			}
		}
		else {
			//assert(false);
			printf("%d\n", 0 / 0);
		}
		val = 0, mi = 0;
		rep(i, 1, n) {
			if (s[i] == ')') val--;
			else if (s[i] == '(') val++; 
			mi = min(mi, val);
		}
		if (val || mi < 0) printf("No solution!\n");
		else {
			rep(i, 1, n) if (s[i] != '*') printf("%c", s[i]);
			printf("\n");
		}
		done:;
	}
	return 0;
}
