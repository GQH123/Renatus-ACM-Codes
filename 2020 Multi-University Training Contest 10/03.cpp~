#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
using namespace std;

void small(int S){
	if (!S) printf("1 1\n.\n");
	else if (S & 1){
		printf("1 %d\n", S + 1);
		rep(i, 1, (S + 1 >> 1)) printf("X.");
		printf("\n");
	}
	else {
		printf("1 %d\n", S + 1);
		printf(".");rep(i, 1, (S >> 1)) printf("X.");
		printf("\n");
	}
}

char g[30][30];
void big(int S){
	printf("25 25\n");
	rep(i, 0, 24) rep(j, 0, 24) g[i][j] = '.'; 
	if (S % 8 == 1){	
		S -= 8;
		rep(j, 0, 2) g[24][j] = 'X';
	}
	else if (S % 8 == 2){
		S -= 16;
		rep(j, 0, 5) g[24][j] = 'X';
	}
	else if (S % 8 == 3){
		g[24][24] = 'X';
	}
	else if (S % 8 == 4){	
		S -= 8;
		rep(j, 0, 3) g[24][j] = 'X';
	}
	else if (S % 8 == 5){
		g[24][12] = 'X';
	}
	else if (S % 8 == 6){
		g[24][0] = g[24][24] = 'X';
	}
	else if (S % 8 == 7){
		S -= 8;
		rep(j, 0, 4) g[24][j] = 'X';
	}  
	S = S / 8 * 8;
	for (register int i = 1; i < 25; i += 2){
		for (register int j = 1; j < 25; j += 2){
			if (!S) break;
			g[i][j] = 'X';
			S -= 8;
		}
	}
	rep(i, 0, 24) {rep(j, 0, 24) printf("%c", g[i][j]); printf("\n");} 
}

int main(){
	int T, S; scanf("%d", &T);
	while (T--){
		scanf("%d", &S);
		if (S <= 20) small(S);
		else big(S);
	}
	return 0;
}
