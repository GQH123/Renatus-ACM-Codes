#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 300020
using namespace std;

int cs, a[maxn]; int n; char s[maxn], b[maxn];
int main(){
	scanf("%s", s + 1);
	n = strlen(s + 1), cs = 0;
	rep(i, 1, n) {
		char ch = s[i]; int _i = i;
		while (i <= n && s[i] == ch) i++;
		++cs, a[cs] = i - _i, b[cs] = ch, i--;
	}
	if (cs % 2 == 0) {
		printf("%d\n", cs >> 1);
		rep (i, 1, cs){
			rep(j, 1, a[i]) printf("%c", b[i]);
			rep(j, 1, a[i + 1]) printf("%c", b[i + 1]);
			printf("\n");
			i++;
		}
	}
	else {
		int mx = 0;
		rep(i, 1, cs) mx = max(mx, a[i]);
		if (mx == 1){
			set<int> s;
			rep(i, 1, cs) s.insert(b[i]);
			if (s.size() <= 2) printf("-1\n");
			else {
				int res = (cs - 3) / 2 + 1;
				printf("%d\n", res);
				bool f = 0;
				rep(i, 1, cs) {
					if (!f) {
						if (b[i] != b[i + 2]) {
							printf("%c%c%c\n", b[i], b[i + 1], b[i + 2]);
							f = 1;
							i++;
						}
						printf("%c%c\n", b[i], b[i + 1]);
					}
					else printf("%c%c\n", b[i], b[i + 1]);
					i++;
				}
			}
		}
		else {
			int f = -1;
			rep(i, 2, cs){
				if (a[i] > 1) {
					f = i;
					break;
				}
				i++;
			}
			if (f != -1){
				printf("%d\n", (cs + 1) / 2);
				rep(i, 1, cs) {
					if (i + 1 == f){
						rep(j, 1, a[i]) printf("%c", b[i]); printf("%c", b[i + 1]);
						a[i + 1]--;
						printf("\n"); 
					}
					else {
						rep(j, 1, a[i]) printf("%c", b[i]);
						rep(j, 1, a[i + 1]) printf("%c", b[i + 1]);
						printf("\n"); 
						i++;
					} 
				}
			}
			else {
				
			}
		} 
	}
	return 0;
}
