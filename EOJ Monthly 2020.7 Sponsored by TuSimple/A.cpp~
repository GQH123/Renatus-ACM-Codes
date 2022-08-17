#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long int 
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define maxn 2000020
#define maxm
using namespace std;

char s[maxn];
int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		int sum = 0, mx = 0;
		int last = -1;
		per(i, n, 1) if (s[i] == 'b') {last = i; break;} 
		rep(i, 1, n){
			if (s[i] == 'a') sum++;
			else sum--;
			mx = max(mx, sum);
			if (sum < 0) {printf("Dead Fang\n"); goto done;}
			if (i == last){
				if (sum) {printf("Sad Fang\n"); goto done;}
			}
		}
		printf("Happy Fang\n");
		done:;
	}
	return 0;
}
