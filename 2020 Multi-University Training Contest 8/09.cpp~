#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 7000020
#define maxr 20000000
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	x = 0; char ch = gc();
	while (!('0' <= ch && ch <= '9')) ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
}
void reads(char* s){
	int l = 0; char ch = gc();
	while (!('a' <= ch && ch <= 'z')) ch = gc();
	while ('a' <= ch && ch <= 'z') s[l++] = ch, ch = gc();
	s[l] = '\0';
}

inline int ope(int n, char* s){ //[l, r)
	int i = 0, j = 1, k = 0, t;
	while (i < n && j < n && k < n) if (t = s[(i + k) >= n ? (i + k - n) : (i + k)] - s[(j + k) >= n ? (j + k - n) : (j + k)]){
		if (t > 0) i += k + 1; else j += k + 1;
		if (i == j) j++;
		k = 0;
	}else k++;
	return i < j ? i : j;
}

int n;
char s[maxn], _s[maxn];
int lis[maxn], cs = 0;
inline bool play(int num){
	if (num == 1) return false;
	cs = 0; 
	int len = n / num;
	for (register int i = 1; i <= n; i += len){
		int res = i + ope(len, s + i);
		srep(j, res, i + len) lis[++cs] = j;
		srep(j, i, res) lis[++cs] = j;
	}
	rep(i, 1, len) {
		char now = s[lis[i]];
		int ptr = i;
		rep(j, 1, num){
			if (now != s[lis[ptr]]) return false;
			ptr += len;
		}
	}
	return true;
	/*
	ll has = 0;
	rep(i, 1, x){
		has = 
	}
	*/
}

int main(){
	int T; read(T);
	while (T--){
		read(n), reads(s + 1);
		rep(i, 1, n){
			if (i * i > n) break;
			if (n % i) continue;
			if (play(i)) {
				printf("Yes\n");
				goto done;
			}
			if (i != n / i) {
				if (play(n / i)){
					printf("Yes\n");
					goto done;
				}
			}
		}
		printf("No\n");
		done:;
	}
	return 0;
}
