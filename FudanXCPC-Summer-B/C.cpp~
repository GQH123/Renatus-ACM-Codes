#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define ll long long int
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define lowbit(x) (x & -x)
#define maxn 200020
#define maxm 
#define maxb 
#define maxs 
#define M  
using namespace std;

int n; 
char g[maxn];
int allh = 0, allt = 0; 

int main(){
	while (scanf("%d", &n) == 1 && n){
	
		scanf("%s", g + 1);
		allt = 0, allh = 0;
		rep(i, 1, n){
			if (g[i] == 'H') allh++;
			else allt++;
		}
		if (allt & 1 || allh & 1) printf("-1\n");
		else { 
			int len = (allt >> 1) + (allh >> 1);
			int h = 0, t = 0; 
			
			h = t = 0;
			rep(i, 1, len){
				if (g[i] == 'H') h++;
				else t++;
			}
			if (h == (allh >> 1) && t == (allt >> 1)){
				printf("1\n%d\n", len); 
				goto done;
			}
			
			h = t = 0;
			rep(i, n - len + 1, n){
				if (g[i] == 'H') h++;
				else t++;
			}
			if (h == (allh >> 1) && t == (allt >> 1)){
				printf("1\n%d\n", n - len);
				goto done;
			}
			
			h = t = 0;
			rep(i, 1, len){
				if (g[i] == 'H') h++;
				else t++;
			}
			if (h == (allh >> 1) && t == (allt >> 1)){
				printf("1\n%d\n", len); 
				goto done;
			}
			
			srep(i, 2, n - len + 1){
				if (g[i - 1] == 'H') h--;
				else t--;
				if (g[i + len - 1] == 'H') h++;
				else t++;
				if (h == (allh >> 1) && t == (allt >> 1)){
					printf("2\n%d %d\n", i - 1, i + len - 1);
					goto done;
				}
			}
			assert(false);
			done:;
		} 
	}
	return 0;
}
