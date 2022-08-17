#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
using namespace std;

int n;
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
int vec[30][9];
int num[9], use[30];
int ori[30];

bool on = 0;
char s[105];
int l1 = 0;
char anst1[100000], anst2[100000];
bool process(int* a, char* t, int& ct){
	rep(i, 2, 27) rep(j, 1, a[i]) t[++ct] = 'a' + i - 2;
		bool same = 1;
		if (ct != n) same = 0;
		if (same){
			rep(i, 1, ct){
				if (t[i] != s[i]) {
					same = 0;
					break;
				}
			}
		}
		if (same){
			bool go = 0;
			per(i, ct, 2){		
				if (t[i] != t[i - 1]) {
					swap(t[i], t[i - 1]);
					go = 1;
					break;
				}
			}
			if (go) return true;
			else return false;
		}
		else return true;
}
void DFS(int pos){
	if (pos == 1){	
		int l2 = 0;
		if (!process(use, anst2, l2)) return;
		if (!on){
			on = 1;
			l1 = 0;
			process(use, anst1, l1);
		}
		else {
			bool f = 0;
			rep(i, 1, min(l1, l2)){
				if (anst2[i] > anst1[i]) return;
				if (anst2[i] < anst1[i]) {f = 1; break;}
			}
			if (!f){
				if (l2 < l1) f = 1;
				else return;
			}
			l1 = 0;
			process(use, anst1, l1);
		}
		return;
	}
	if (pos == 4 || pos == 6 || pos == 8 || pos == 9 || pos == 10 || pos == 12 || pos == 16 || pos == 24) {DFS(pos - 1); return;}
	if (pos == 2 || pos == 3 || pos == 5 || pos == 7 || pos == 11 || pos == 13 || pos == 17 || pos == 19 || pos == 23){
		bool f = 1;
		use[pos] = num[lower_bound(p, p + 9, pos) - p];
		rep(j, 0, 8){
			num[j] -= vec[pos][j] * use[pos];
			if (num[j] < 0) f = 0;
		}
		if (f) DFS(pos - 1); 
		rep(j, 0, 8) num[j] += vec[pos][j] * use[pos];  
		use[pos] = 0;
		return;
	}
	DFS(pos - 1);
	int _num[9];
	rep(j, 0, 8) _num[j] = num[j];
	rep(i, 1, 10000){
		bool f = 1;
		use[pos]++;
		rep(j, 0, 8) {
			num[j] -= vec[pos][j];
			if (num[j] < 0) f = 0;
		}
		if (f) DFS(pos - 1);
		//use[pos]--;
		//rep(j, 0, 8) num[j] += vec[pos][j]; 
		if (!f) break;
	}
	use[pos] = 0;
	rep(j, 0, 8) num[j] = _num[j];
}


char t[100000];
int ct = 0;

int main(){

	//rep(i, 2, 27) printf("%d %c\n", i, 'a' + i - 2);
	
		freopen("D.in", "r", stdin);
		
	rep(i, 2, 27){
		int x = i;
		rep(j, 0, 8){
			vec[i][j] = vec[i - 1][j];
			while (x % p[j] == 0) {
				vec[i][j]++;
				x /= p[j];
			}
		}
	}
	
	int T;
	scanf("%d", &T);
	rep(TT, 1, T){
		on = 0;
		printf("Case %d: ", TT);
		scanf("%s", s + 1);
		n = strlen(s + 1);
		rep(i, 1, n){
			int x = s[i] - 'a' + 2;
			rep(j, 0, 8) num[j] += vec[x][j];
			ori[x]++;
		}
		DFS(27);
		rep(i, 2, 27) assert(use[i] == 0);
		
		
		if (!on) printf("Impossible");
		else rep(i, 1, l1) printf("%c", anst1[i]);
		
		
		
		printf("\n");
		rep(i, 2, 27) ori[i] = 0;
		rep(i, 0, 8) num[i] = 0;
		ct = 0;
	}
	return 0;
}


/*

2 a
3 b
4 c
5 d
6 e
7 f
8 g
9 h
10 i
11 j
12 k
13 l
14 m
15 n
16 o
17 p
18 q
19 r
20 s
21 t
22 u
23 v
24 w
25 x
26 y
27 z

*/
