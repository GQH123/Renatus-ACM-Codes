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
#define maxn 2020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

int n, m;

struct player{
	char name[25];
}line[maxn << 1], op;

struct state{
	char WO[25], BO[25], WD[25], BD[25];
}State;
//O -> D, D -> quit

int cs = 0;
struct team{
	char P1[25], P2[25];
	int dynas;
}lis[maxn << 1], W, B;
int TW, TB;

char s[maxn], t[25];

int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("B.in", "r", stdin);
		#endif
	
	scanf("%d", &n);
	rep(i, 1, n) scanf("%s", line[i].name);
	scanf("%s", s + 1);
	m = strlen(s + 1);
	
	strcpy(State.WO, line[1].name);
	strcpy(State.BO, line[2].name);
	strcpy(State.WD, line[3].name);
	strcpy(State.BD, line[4].name);
	
	strcpy(W.P1, line[1].name);
	strcpy(W.P2, line[3].name);
	strcpy(B.P1, line[2].name);
	strcpy(B.P2, line[4].name);
	lis[++cs] = W, lis[++cs] = B;
	TW = 1, TB = 2;
	lis[TW].dynas = lis[TB].dynas = 0;
	
	int ptr = 4;
	rep(i, 1, m){
		if (s[i] == 'W') {
			lis[TW].dynas++;
			strcpy(t, State.WO);
			strcpy(State.WO, State.WD);
			strcpy(State.WD, t);
			
			strcpy(op.name, State.BD);
			line[++n] = op;
			strcpy(State.BD, State.BO);
			strcpy(State.BO, line[++ptr].name);
			
			strcpy(B.P1, State.BD);
			strcpy(B.P2, State.BO);
			lis[++cs] = B;
			TB = cs;
			lis[TB].dynas = 0;
		}
		else if (s[i] == 'B'){
			lis[TB].dynas++;
			strcpy(t, State.BO);
			strcpy(State.BO, State.BD);
			strcpy(State.BD, t);
			
			strcpy(op.name, State.WD);
			line[++n] = op;
			strcpy(State.WD, State.WO);
			strcpy(State.WO, line[++ptr].name);
			
			strcpy(W.P1, State.WD);
			strcpy(W.P2, State.WO);
			lis[++cs] = W;
			TW = cs;
			lis[TW].dynas = 0;
		}
		else printf("(=_=)???\n");
	}
	int mx = 0;
	rep(i, 1, cs) mx = max(mx, lis[i].dynas); 
	rep(i, 1, cs) if (lis[i].dynas == mx) printf("%s %s\n", lis[i].P1, lis[i].P2); 
	return 0;
}
