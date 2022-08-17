#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll __int128
using namespace std;

char str[20]; int n;

int isope(char ch){
	if (ch == '+') return 1;
	if (ch == '-') return 2;
	if (ch == '*') return 3;
	if (ch == '/') return 4;
	if (ch == '=') return -1;
	return 0;
}
int getval(char ch) {
	if ('0' <= ch && ch <= '9') return ch - '0';
	else return ch - 'A' + 10; 
}
int main(){
	while (scanf("%s", str + 1) == 1) {
		int n = strlen(str + 1);
		int mx = 2;
		rep(i, 1, n) {
			if (isope(str[i])) continue;
			mx = max(mx, getval(str[i]) + 1);
		}
		rep(kk, mx, 16) {	
			ll a = 0, b = 0, c = 0;
			int op = -1, ptr = 1;
			while (ptr <= n && !isope(str[ptr])) {
				a = a * kk + getval(str[ptr]);
				ptr++;
			}
			op = isope(str[ptr]), ptr++;
			while (ptr <= n && !isope(str[ptr])) {
				b = b * kk + getval(str[ptr]);
				ptr++;
			}
			ptr++;
			while (ptr <= n && !isope(str[ptr])) {
				c = c * kk + getval(str[ptr]);
				ptr++;
			}
			if (op == 1){
				if (a + b == c) {printf("%d\n", kk); goto done;}
			}
			else if (op == 2){
				if (a - b == c) {printf("%d\n", kk); goto done;}
			}
			else if (op == 3){
				if (a * b == c) {printf("%d\n", kk); goto done;}
			}
			else {
				if (a == b * c) {printf("%d\n", kk); goto done;}
			}
		}
		printf("-1\n");
		done:;
	}
	return 0;
}
