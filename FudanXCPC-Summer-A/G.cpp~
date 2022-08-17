#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 9
#define maxm 
#define M  
#define ull unsigned long long int 
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int> 
#define pdd pair<double, double>
#define fi first
#define se second
#define lowbit(x) (x & -x)
#define fixed FIXED
using namespace std;

ull mat[maxn * maxn], _mat[maxn * maxn];
bool b[maxn * maxn], fixed[maxn * maxn], sta[maxn * maxn];
bool Gauss(int n, ull* mat, ull* _mat){
	int now = 0;
	srep(i, 0, n) _mat[i] = 1ull << i;
	srep(j, 0, n){
		int f = -1;
		srep(i, now, n) if (mat[i] & (1ull << j)) {f = i; break;}
		if (f == -1) continue;
		swap(mat[now], mat[f]), swap(_mat[now], _mat[f]);
		srep(i, 0, n){
			if (i == now) continue;
			if (mat[i] & (1ull << j)) mat[i] ^= mat[now], _mat[i] ^= _mat[now];
		}
		now++;
	}
	return now == n;
}
ull col[maxn][maxn * maxn];
ull Getans(int n, ull* col, bool* b){
	ull ans = 0;
	srep(i, 0, n) if (b[i]) ans ^= col[i];
	return ans;
}

ull sav[maxn][maxn * maxn];
bool Gauss(int n, ull* mat, bool* b, bool* fixed){
	int now = 0;
	srep(i, 0, n) fixed[i] = 0;
	srep(j, 0, n){
		int f = -1;
		srep(i, now, n) if (mat[i] & (1ull << j)) {f = i; break;}
		if (f == -1) continue;
		swap(mat[now], mat[f]), swap(b[now], b[f]);
		srep(i, 0, n){
			if (i == now) continue;
			if (mat[i] & (1ull << j)) mat[i] ^= mat[now], b[i] ^= b[now];
		}
		now++;
		fixed[j] = 1;
	}
	srep(i, 0, n) if (!mat[i] && b[i]) return false;
	return true;
}

inline bool ok(int n, int x, int y){
	return 0 <= x && x < n && 0 <= y && y < n;
}
inline int id(int n, int x, int y){
	return x * n + y;
}
/*
void debug(int n, ull* mat){
	srep(i, 0, n * n){
		ull x = mat[i];
		srep(j, 0, n * n){
			cout << (x & 1) << " ";
			x >>= 1;
		}
		cout << endl;
	}
	cout << endl;
}
*/
void init(){
	rep(n, 1, 8){
		//cout << "=====================================" << endl;
		//cout << "n = " << n << endl << endl;
		srep(i, 0, n * n) mat[i] = _mat[i] = 0;
		srep(i, 0, n * n){
			int x = i / n, y = i % n;
			mat[i] |= (1ull << i);
			for (register int k = -1; k <= 1; k += 2){
				if (ok(n, x + k, y)) mat[i] |= (1ull << id(n, x + k, y));
				if (ok(n, x, y + k)) mat[i] |= (1ull << id(n, x, y + k));
			}
		}
		srep(i, 0, n * n) sav[n][i] = mat[i];
		//cout << "Sav: " << endl; debug(n, sav[n]);
		
		if (Gauss(n * n, mat, _mat)){
			//cout << "Success: " << n << endl;
			//debug(n, mat), debug(n, _mat);
			srep(i, 0, n * n) {
				int now = 0;
				ull x = _mat[i];
				while (x){
					if (x & 1) col[n][now] |= (1ull << i);
					x >>= 1; 
					now++;
				}
			}
			//cout << "Col: " << endl; debug(n, col[n]);
		}
		else {
			//cout << "Fail: " << n << endl;
			//debug(n, mat), debug(n, _mat);
		} 
	}
}
int lis[maxn], cs = 0;
void work(){
	int T, x, n;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n); 
		srep(i, 0, n * n) b[i] = 0;
		rep(i, 1, n) {
			scanf("%d", &x);
			int nowb = 0;
			while (x){
				if (x & 1) b[(i - 1) * n + n - 1 - nowb] = 1; 
				nowb++;
				x >>= 1; 
			}
		}
		if (n != 4 && n != 5) {
			srep(i, 0, n * n) mat[i] = col[n][i];
			ull res = Getans(n * n, mat, b);
			int ans = 0;
			while (res){
				if (res & 1) ans++;
				res >>= 1;
			}
			printf("%d\n", ans);
		}
		else {
			srep(i, 0, n * n) mat[i] = sav[n][i];
			if (!Gauss(n * n, mat, b, fixed)) printf("-1\n");
			else {
				int ans = n * n;
				cs = 0;
				srep(i, 0, n * n) if (!fixed[i]) lis[cs++] = i; 
				srep(i, 0, (1ull << cs)){ 
					int res = 0;
					srep(k, 0, cs) if (i & (1ull << k)) res++;
					srep(j, 0, n * n) {
						if (!fixed[j]) continue;
						bool nowb = b[j];
						srep(k, 0, cs) if ((mat[j] & (1ull << lis[k])) && (i & (1ull << k))) nowb ^= 1; 
						if (nowb) res++;
					}
					ans = min(ans, res);
				}
				printf("%d\n", ans);
			} 
		}
	}
}
int main(){
	init();
	work();
	return 0;
}
