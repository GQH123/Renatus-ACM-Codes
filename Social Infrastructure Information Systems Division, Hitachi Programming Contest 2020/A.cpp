#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
using namespace std;

int main(){
	char s[220];
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	if (n & 1){
		printf("No");
		return 0;
	}
	for (register int i = 1; i <= n; i += 2) {
		if (s[i] != 'h') {
			printf("No");
			return 0;
		}
	}
	for (register int i = 2; i <= n; i += 2) {
		if (s[i] != 'i') {
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}
