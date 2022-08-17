#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define maxn 2020
using namespace std;



ll M = (1ll << 40) - 1;

set<ll> s;

int ceil(ll x, ll y){
	return (x - 1) / y + 1;
}

inline ll getnxt(ll S, int& ct){
	ll a = S >> 20;
	ll b = S - (a << 20);
	int t = ceil((1 << 20) - b, a + 12345);//ceil(1.0 * ((1 << 20) - b) / (a + 12345));
	ct += t;
	ll _S = (a << 20) + b + t * (a + 12345);
	_S &= M;
	return _S;
}

int a[maxn], b[maxn];
int cc = 0;

int main(){
	
	ll S0 = 0x600DCAFE;
	s.insert(S0);
	int ct = 0;
	ll last = S0;
	//int bound = 530000000;
	int sum = 0;
	sum += ((S0 & 1) ? 0 : 1);
	++cc, a[cc] = sum, b[cc] = 0;
	while (1){ 
		ll S = getnxt(last, ct);
		sum += ((S & 1) ? 0 : 1);
		if (ct > cc * 700250) {
			++cc, a[cc] = sum, b[cc] = ct;
		}
		
		if (ct == 350125354){
			++cc, a[cc] = sum, b[cc] = ct;
			break;
		}
		last = S;
		//if (S == 1060094) cerr << ct << endl;
		//if (ct > bound) cerr << ct << ' ' << S << endl;
		//if (s.count(S)) break;
		//else s.insert(S), last = S;
		//cout << ct << endl;
	}
	//cout << ct << ' ' << last << endl;
	printf("%d\n\n", cc);
	rep(i, 1, cc){
		printf("%lld,", a[i]);
	}
	printf("\n\n");
	rep(i, 1, cc){
		printf("%lld,", b[i]);
	}
	
	
	/*
	ll S0 = 1060094;
	int ct = 0;
	ll last = S0;
	//int bound = 530000000;
	++cc, a[cc] = S0, b[cc] = 0;
	while (1){ 
		ll S = getnxt(last, ct);
		if (ct > cc * 364258) {
			++cc, a[cc] = S, b[cc] = ct;
		}
		
		if (ct == 182129209){
			++cc, a[cc] = S, b[cc] = ct;
			break;
		}
		last = S; 
	} 
	printf("%d\n\n", cc);
	rep(i, 1, cc){
		printf("%lldll,", a[i]);
	}
	printf("\n\n");
	rep(i, 1, cc){
		printf("%lldll,", b[i]);
	}
	*/
	return 0;
}

// 119527910 516914

// 350125354 -> 532254563 : 182129209 1060094

// 18712 1000

// 13496 1000
