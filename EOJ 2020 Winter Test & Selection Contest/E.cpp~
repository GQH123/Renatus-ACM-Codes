#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define lowbit(x) (x & -x) 
#define eps 5e-3
using namespace std;

char ch[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .";
int num[64], sum; 

double cal(){
	double res = 0;
	rep(i, 0, 63) {
		if (!num[i]) continue;
		double p = 1.0 * num[i] / sum;
		res -= p * log(p) / log(2);
	}
	return res;
}

int main(){
	
		//freopen("E.in", "r", stdin);
	
	//for (register double H = 0.00; H <= 6.00; H += 0.01){
	double H;
	scanf("%lf", &H);
	
		int s = (H == (double)((int)H)) ? (int)H : ((int)H + 1), x = (1 << s);
		if (1 - H > eps){
			//srep(i, 0, 2) num[i] = 500;
			num[0] = 1000, num[1] = 0;
			sum = 1000; 
			while (sum && fabs(cal() - H) > eps) {
				//printf("%.8lf\n", cal());
				num[0]--, num[1]++; 
			}
			//if (fabs(cal() - H) > eps) printf("%.6lf\n", H);
			//printf("%.8lf\n", cal());
			//srep(i, 0, 2) printf("%d ", num[i]); printf("\n");
			srep(i, 0, 2) rep(j, 1, num[i]) printf("%c", ch[i]);
		}
		else { 
			srep(i, 0, x) num[i] = 1000 / x;
			sum = num[0] * x;
			int ptr = 0;
			while (sum && ptr < (x - 1) && fabs(cal() - H) > eps) {
				//printf("%.8lf\n", cal());
				num[ptr]--, num[ptr + 1]++;//sum--;
				if (!num[ptr]) ptr++;
			}
			//printf("%.8lf\n", cal());
			//srep(i, 0, x) printf("%d ", num[i]); printf("\n");
			//if (fabs(cal() - H) > eps) printf("%.6lf\n", H);
			srep(i, 0, x) rep(j, 1, num[i]) printf("%c", ch[i]);
		}
		
	//}	
	//double H;
	//scanf("%lf", &H);
	
	
	return 0;
}
