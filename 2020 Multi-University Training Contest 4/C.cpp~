#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 2020
#define maxs 2000020
#define inf 0x3f3f3f3f3f3f3f3fll
#define ll long long int 
using namespace std;



int n, m;
int w[maxn], v[maxn];
int lisa[maxs], _lisa[maxs], ca = 0;
ll mxa[maxs];
int lisb[maxs], _lisb[maxs], cb = 0;
ll mxb[maxs];

int tmp[maxs];
void merge(int* lis, int& cs, int* _lis, int _cs){
	if (!_cs) return;
	int ptra = 1, ptrb = _cs, ptr = 0;
	while (ptra <= cs && ptrb >= 1){	
		if (lis[ptra] < _lis[ptrb]) tmp[++ptr] = lis[ptra], ptra++; 
		else tmp[++ptr] = _lis[ptrb], ptrb--; 
	}
	while (ptra <= cs) tmp[++ptr] = lis[ptra], ptra++;
	while (ptrb >= 1) tmp[++ptr] = _lis[ptrb], ptrb--;
	cs = ptr;
	rep(i, 1, cs) lis[i] = tmp[i];
}
void merge2(int* lis, int& cs, int* _lis, int _cs){
	if (!_cs) return;
	int ptra = 1, ptrb = 1, ptr = 0;
	while (ptra <= cs && ptrb <= _cs){	
		if (lis[ptra] < _lis[ptrb]) tmp[++ptr] = lis[ptra], ptra++; 
		else tmp[++ptr] = _lis[ptrb], ptrb++; 
	}
	while (ptra <= cs) tmp[++ptr] = lis[ptra], ptra++;
	while (ptrb <= _cs) tmp[++ptr] = _lis[ptrb], ptrb++;
	cs = ptr;
	rep(i, 1, cs) lis[i] = tmp[i];
}
int main(){
	int T; scanf("%d", &T);
	srep(i, 0, maxs) mxa[i] = mxb[i] = -inf;
	while (T--){
		scanf("%d%d", &n, &m);
		rep(i, 1, n + m) scanf("%d%d", w + i, v + i);
		
		lisa[++ca] = 0, mxa[0] = 0;
		rep(i, 1, n) {
			int _ca = 0;
			per(j, ca, 1){
				int k = lisa[j] + w[i];
				if (mxa[k] == -inf) _lisa[++_ca] = k; 
				mxa[k] = max(mxa[k], mxa[lisa[j]] + v[i]);
			}
			merge(lisa, ca, _lisa, _ca);
		}
		
		//lisb[++cb] = 0, mxb[0] = 0;
		int sum = 0;
		rep(i, n + 1, n + m) sum += w[i];
		rep(i, n + 1, n + m){
			int _ca = 0;
			int st = lower_bound(lisa + 1, lisa + 1 + ca, w[i]) - lisa;
			int ed = upper_bound(lisa + 1, lisa + 1 + ca, sum) - lisa;
			sum -= w[i];
			srep(j, st, ed){ 
				int k = lisa[j] - w[i]; 
				if (mxa[k] == -inf) _lisa[++_ca] = k; 
				mxa[k] = max(mxa[k], mxa[lisa[j]] + v[i]);
			}
			merge2(lisa, ca, _lisa, _ca);
		}
		
		/*
		int ptr = 1;
		ll res = -inf;
		rep(i, 1, ca) {
			while (ptr <= cb && lisb[ptr] < lisa[i]) ptr++;
			if (lisb[ptr] == lisa[i]) res = max(res, mxb[lisb[ptr]] + mxa[lisa[i]]);
		}
		*/
		printf("%lld\n", mxa[0]);
		rep(i, 1, ca) mxa[lisa[i]] = -inf; ca = 0;
		//rep(i, 1, cb) mxb[lisb[i]] = -inf; cb = 0;
	}
	return 0;
}
