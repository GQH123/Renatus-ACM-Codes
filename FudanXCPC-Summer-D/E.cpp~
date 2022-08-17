#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 400020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define pc putchar
#define ll long long int 
#define ld long double 
#define lowbit(x) (x & -x)
#define M 
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

int n;
char s[maxn];
//xtCpc
int num[6];
int main(){
	while (scanf("%d", &n) == 1){ 
		scanf("%s", s + 1);
		int ans = 0;
		rep(i, 0, 5) num[i] = 0;
		rep(i, 1, n){
			if (s[i] == 'x') num[0]++;
			else if (s[i] == 't') {
				if (num[0]) num[0]--, num[1]++;
			}
			else if (s[i] == 'C') {
				if (num[1]) num[1]--, num[2]++;
			}
			else if (s[i] == 'p') {
				if (num[2]) num[2]--, num[3]++;
			}
			else if (s[i] == 'c') {
				if (num[3]) num[3]--, ans++;
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
