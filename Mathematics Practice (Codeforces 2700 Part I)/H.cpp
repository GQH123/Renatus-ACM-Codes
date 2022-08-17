#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 600020
#define pi 3.141592653589793
using namespace std;

typedef struct complex{
	double r, i;
	complex(double r, double i) : r(r), i(i){}
	complex(){}
}cd;
cd operator + (cd a, cd b){
	return cd(a.r + b.r, a.i + b.i);
}
cd operator - (cd a, cd b){
	return cd(a.r - b.r, a.i - b.i);
}
cd operator * (cd a, cd b){
	return cd(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r);
}
cd operator / (cd a, int k){
	return cd(a.r / k, a.i / k);
}
cd ex(double theta){
	return cd(cos(theta), sin(theta));
}
int rev[maxn << 2];
void init(int bit){
	srep(i, 1, (1 << bit)) rev[i] = rev[i >> 1] >> 1 | ((i & 1) << (bit - 1));
}
void FFT(cd* a, int n, int dft){
	srep(i, 0, n) if (rev[i] > i) swap(a[rev[i]], a[i]);
	for (register int step = 1; step < n; step <<= 1){
		cd wn = ex(pi * dft / step);
		for (register int i = 0; i < n; i += (step << 1)){
			cd wnk = cd(1, 0);
			for (register int j = i; j < i + step; j++){
				cd x = a[j], y = wnk * a[j + step];
				a[j] = x + y, a[j + step] = x - y, wnk = wnk * wn;
			}
		}
	}
	if (dft == -1) srep(i, 0, n) a[i] = a[i] / n;
}

cd a[maxn << 2], b[maxn << 2];
int num[maxn], ans[maxn], cs = 0;

int n;
char s[maxn];
int main(){
	
		freopen("H.in", "r", stdin);
		
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		scanf("%s", s);
		srep(i, 0, n){
			if (s[i] == 'V') a[i].r = 1;
			if (s[i] == 'K') b[n - 1 - i].r = 1;
		}
		int len = (n << 1), s = 0;
		while (len) s++, len >>= 1;
		len = (1 << s), init(s);
		FFT(a, len, 1), FFT(b, len, 1);
		srep(i, 0, len) a[i] = a[i] * b[i];
		FFT(a, len, -1);
		rep(i, n, 2 * n - 2) num[i - n + 1] += (int)(a[i].r + 0.5); 
		rep(i, 0, n - 2) num[n - 1 - i] += (int)(a[i].r + 0.5);
		rep(i, 1, n){
			bool f = 1;
			for (register int j = i; j < n; j += i){
				if (num[j]) {f = 0; break;}  
			}
			if (f) ans[++cs] = i;
		}
		printf("%d\n", cs);
		rep(i, 1, cs) printf("%d ", ans[i]);
		printf("\n");
		
		srep(i, 0, len) a[i].r = a[i].i = b[i].r = b[i].i = 0;
		srep(i, 1, n) num[i] = 0;
		cs = 0;
	}
	return 0;
}
