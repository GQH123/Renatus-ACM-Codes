#include <bits/stdc++.h>
#include <bitset>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 3000
using namespace std;

const int base = 30, nbase = 1 << base;

struct bignum{
	int l; bitset<maxn> num; 
	void reset(){ num.reset(); l = 0; }
	bignum(){ reset(); } 
	bignum(int x){ 
		reset();
		num = x;
		while (x) x >>= 1, l++;
	}
	bool operator < (bignum& b) { 
		if (l != b.l) return l < b.l; 
		srep(i, 0, l) if (num[i] != b.num[i]) return num[i] < b.num[i]; 
		return false; 
	} 
	bignum operator += (bignum b) {  
		l = max(l, b.l) + 5;
		int x = 0;
		srep(i, 0, l) {
			x += num[i] + b.num[i];
			num[i] = (x & 1);
			x >>= 1;
		}
		while (l && !num[l - 1]) l--;
		return *this;
	}
}one(1), ten(10);

bignum operator << (bignum& a, int k){	 
	if (!a.l) return a;
	bignum c = a; c.num <<= k, c.l += k;
	return c;
}
bignum operator >> (bignum& a, int k){
	bignum c = a; c.num >>= k, c.l -= k; c.l = max(c.l, 0);
	return c;
}
bignum operator + (bignum& a, bignum& b) {
	bignum c;
	c.l = max(a.l, b.l) + 5;
	int x = 0;
	srep(i, 0, c.l) {
		x += a.num[i] + b.num[i];
		c.num[i] = (x & 1);
		x >>= 1;
	}
	while (c.l && !c.num[c.l - 1]) c.l--;
	return c;
} 

int tmp[maxn];
bignum operator - (bignum& a, bignum& b){
	bignum c;
	c.l = max(a.l, b.l);
	srep(i, 0, c.l) tmp[i] = a.num[i] - b.num[i];
	srep(i, 0, c.l) if (tmp[i] < 0) tmp[i + 1]--, tmp[i] += 2; 
	c.num.reset();
	while (c.l && !tmp[c.l - 1]) c.l--;
	srep(i, 0, c.l) c.num[i] = tmp[i];
	return c;
}
bool operator >= (bignum a, bignum b){
	return !(a < b);
}
bignum operator * (bignum& a, bignum& b) {
	bignum c; c.l = a.l + b.l + 10;
	srep(i, 0, a.l) if (a.num[i]) c += (b << i); 
	while (c.l && !c.num[c.l - 1]) c.l--;
	return c;
}
bignum max(bignum a, bignum b) {	
	return (a < b) ? b : a;
}
bignum min(bignum a, bignum b) {
	return (a < b) ? a : b;
} 
bignum cal(bignum n, int bit){	////(abs(nowc - (bignum(1) << i) + 1) << 1); 
	bignum mi = bignum(1); mi = mi << bit;
	if (n < mi){
		if (!n.l) {
			n.l = bit + 1;
			n.num[bit] = 1;
			return n << 1;
		}
		n.l = bit;
		srep(i, 0, bit) {
			if (n.num[i]) n.num[i] = 0;
			else n.num[i] = 1; 
		}
		while (n.l && !n.num[n.l - 1]) n.l--; 
		n = n + one;
		return n << 1;
	} 
	else { 
		int flag = bit;
		srep(i, bit, n.l) {
			if (n.num[i]) {
				flag = i;
				break;
			}
		}
		assert(flag != -1);
		srep(i, bit, flag) n.num[i] = 1; 
		n.num[flag] = 0;
		while (n.l && !n.num[n.l - 1]) n.l--; 
		return n << 1;
	}
	
	/*
	if (n.num[bit]) {
		n.num[bit] = 0; 
		while (n.l && !n.num[n.l - 1]) n.l--;
		return n << 1;
	}
	else srep(i, 0, bit) {
		if (n.num[i]) n.num[i] = 0;
		else n.num[i] = 1;
		while (n.l && !n.num[n.l - 1]) n.l--;
		return n << 1;
	}
	*/
}

int num[maxn];
void print(bignum c){
	if (!c.l) {printf("0"); return;}
	int n = 0; num[0] = 0;
	per(bit, c.l - 1, 0) {
		srep(i, 0, n) num[i] = num[i] << 1;
		srep(i, 0, n) num[i + 1] += num[i] / 10, num[i] = num[i] % 10;
		n += 5; while (n && !num[n - 1]) n--;
		num[0] += c.num[bit];
		srep(i, 0, n) {
			if (num[i] < 10) break;
			num[i + 1] += num[i] / 10, num[i] = num[i] % 10;
		}
		n += 5; while (n && !num[n - 1]) n--;
	}
	per(i, n - 1, 0) printf("%d", num[i]);
	srep(i, 0, n) num[i] = 0;
}


char s[maxn]; int n;

int main(){
	while (scanf("%s", s + 1) == 1){
		n = strlen(s + 1);
		bignum c, bitn;
		rep(i, 1, n) c = c * ten, bitn = bignum(s[i] - '0'), c = c + bitn; 
		//print(c); printf("\n");
		bignum res, nowc, nowone(1), nowcc = c;
		srep(i, 0, c.l) { 
			if (c.num[i]) nowc += nowone;
			//print(nowc); printf(" ");
			bignum con; 
			con = cal(nowc + one, i);
			//cout << "$" << con.l << "$";
			//print(con); printf(" ");
			/*
			if (nowc < ((bignum(1) << i) - bignum(1))){
				con = (bignum(1) << i) - n - 
			}
			else {
				con += n - (bignum(1) << i) + 1;
			}
			*/
			nowcc = nowcc >> 1, con = con * nowone;
			res += con * nowcc;
			if (nowc >= nowone) res += con;
			//print(res); printf("\n");
			nowone = nowone << 1;
		}
		c = c << 1;
		res = res - c;
		print(res); printf("\n");
		//printf("\n");printf("\n");
	}
	return 0;
}
