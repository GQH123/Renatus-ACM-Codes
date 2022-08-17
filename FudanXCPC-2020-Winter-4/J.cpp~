#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define maxr 100000
#define maxn
#define maxm
#define M
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

char s[10];

int cp = 0;
struct ele{
	int x, y, op;
	ele(int x, int y, int op) : x(x), y(y), op(op){}
	ele(){}
}p[10];

int lis[10];

bool judge(){
	rep(i, 1, cp){
		int x = p[i].x, y = p[i].y, op = p[i].op;
		if (op == 2){
			if (lis[x] < lis[y]) return false;
		}
		else {
			if (lis[x] > lis[y]) return false;
		}
	}
	return true;
}



int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("J.in", "r", stdin);
		#endif
	
	
	rep(i, 1, 5){
		scanf("%s", s + 1);
		int x = s[1] - 'A' + 1;
		int y = s[3] - 'A' + 1;
		int op = (s[2] == '>') ? 2 : 1;
		p[++cp] = ele(x, y, op);
	}
	
	rep(i, 1, 5) lis[i] = i;
	if (judge()){
		rep(i, 1, 5) {
			rep(j, 1, 5){
				if (lis[j] == i) {
					printf("%c", 'A' - 1 + j);
					break;
				}
			}
		}
		return 0;
	}
	while (next_permutation(lis + 1, lis + 6)){
		if (judge()){
			rep(i, 1, 5) {
				rep(j, 1, 5){
					if (lis[j] == i) {
						printf("%c", 'A' - 1 + j);
						break;
					}
				}
			}
			return 0;
		}
	}
	printf("impossible");
	return 0;
}
