#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxr 100000
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

void init(){
}

int cp = 9;
int p[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23};

struct vector{
	int a[10];
}let[27];


int mat[maxn][maxn];
void Gauss(int r, int c){
	while (
}

int main(){
	/*
		#ifndef ONLINE_JUDGE
			freopen("D.in", "r", stdin);
		#endif
	*/
	rep(i, 1, 9) let[0].a[i] = 0;
	rep(i, 1, 26){
		rep(j, 1, 9) let[i].a[j] = let[i - 1].a[j];
		int x = i;
		rep(j, 1, cp){ 
			while (x % p[j] == 0){
				let[i].a[j]++;
				x /= p[j];
			}
		}
	}
	
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%s", s);
		
	}
	return 0;
}
