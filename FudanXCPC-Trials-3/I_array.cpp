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
#define maxn 133
#define maxm
using namespace std;

const int base = 30, nbase = 1 << base;

int bignum{
	int l, num[maxn];   
	void bignum(){
		l = 0; memset(num, 0, sizeof(num));
	}
	void bignum(int x){
		if (!x) return;
		num[0] = x % nbase, num[1] = x / nbase;
		if (num[1]) l = 2;
		else l = 1;
	}
	void mi2(int bit){
		l = bit / base + 1;
		num[l - 1] = 1 << (bit % base); 
	}
	bool operator < (bignum b) {
		if (l != b.l) return l < b.l;
		per(i, l - 1, 0) if (num[i] != b.num[i]) return num[i] < b.num[i];
		return false;
	}
}
bignum operator << (bignum& a, int k){
	
}
bignum operator + (bignum& a, bignum& b) {
	bignum c;
	c.l = max(a.l, b.l);
	srep(i, 0, c.l) {
		c.num[i] = a.num[i] + b.num[i];
		c.num[i + 1] += c.num[i] / nbase;
		c.num[i] %= nbase;
	}
	if (c.num[c.l]) c.l++;
	return c;
}
bignum operator * (bignum a, bignum b) {
	bignum c;
	c.l = a.l + b.l; 
	
}
bignum max(bignum a, bignum b) {	
	return (a < b) ? b : a;
}
bignum min(bignum a, bignum b) {
	return (a < b) ? a : b;
}

int main(){

	return 0;
}
