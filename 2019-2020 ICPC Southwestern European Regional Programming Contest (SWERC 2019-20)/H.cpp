#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define maxn 2020
using namespace std; 

ll M = (1ll << 40) - 1; 

inline ll getnxt(ll S, int& ct){
	ct++;
	return ((S + (S >> 20) + 12345) & M);
}

int a[maxn], b[maxn]; ll c[maxn];
int cc = 0;


int main(){
	
	ll S = 0x600DCAFE; 
	int ct = 0;
	int sum = 0;
	sum += ((S & 1) ? 0 : 1);
	++cc, a[cc] = sum, b[cc] = 0, c[cc] = S;
	while (1){ 
		S = getnxt(S, ct); 
		sum += ((S & 1) ? 0 : 1);
		if (ct > cc * 700250) {
			++cc, a[cc] = sum, b[cc] = ct, c[cc] = S;
		}
		
		if (ct == 350125354){
			++cc, a[cc] = sum, b[cc] = ct, c[cc] = S;
			break;
		} 
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
	printf("\n\n");
	rep(i, 1, cc){
		printf("%lldll,", c[i]);
	}
	
	
	
	/*
	ll S = 1060094;
	int ct = 0; 
	//int bound = 530000000;
	int sum = 0;
	sum += ((S & 1) ? 0 : 1);
	++cc, a[cc] = sum, b[cc] = 0, c[cc] = S;
	while (1){ 
		S = getnxt(S, ct);
		sum += ((S & 1) ? 0 : 1);
		if (ct > cc * 364258) {
			++cc, a[cc] = sum, b[cc] = ct, c[cc] = S;
		}
		
		if (ct == 182129209){
			++cc, a[cc] = sum, b[cc] = ct, c[cc] = S;
			break;
		} 
	} 
	printf("%d\n\n", cc);
	rep(i, 1, cc){
		printf("%lld,", a[i]);
	}
	printf("\n\n");
	rep(i, 1, cc){
		printf("%lld,", b[i]);
	}
	printf("\n\n");
	rep(i, 1, cc){
		printf("%lldll,", c[i]);
	}
	*/
	return 0;
}
