#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 300020
#define maxm 
#define M 
#define ll long long int 
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define fi first
#define se second
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define lowbit(x) (x & -x)
#define maxr 1000000
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') ch = gc(), f = 0;
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
void reads(char* s){
	char ch = gc(); int l = 0;
	while (!('a' <= ch && ch <= 'z')) ch = gc();
	while ('a' <= ch && ch <= 'z') s[l++] = ch, ch = gc();
	s[l] = '\0';
}

int n, l, k;
int res[maxn << 2], a[maxn];
pii lis[maxn];

int sum[maxn << 2], qx, qd;
void init(int l, int r, int o){
	sum[o] = 0;
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
}
void add(int l, int r, int o){
	sum[o] += qd;
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) add(l, mid, o << 1);
	else add(mid + 1, r, o << 1 | 1); 
}
int get(int l, int r, int o){
	if (l == r) return l;
	int mid = ((r - l) >> 1) + l;
	if (sum[o << 1 | 1] >= qd) return get(mid + 1, r, o << 1 | 1);
	else {qd -= sum[o << 1 | 1]; return get(l, mid, o << 1);}
}


int temp[maxn], _res[maxn];
ll cal3(bool op){ 
	rep(i, 1, n) res[i] = _res[i];
	int left = n / l * l, rest = n - left;
	rep(i, left + 1, n) temp[i - left] = res[i];
	per(i, n, n - left + 1) res[i] = res[i - n + left];
	rep(i, 1, n - left) res[i] = temp[i];
	int ptr = n - left + 1;
	rep(i, 1, n / l){
		reverse(res + ptr, res + ptr + l);
		ptr += l;
	}
	if (op){
		int ptr = 1;
		rep(i, 1, n / l){
			reverse(res + ptr + k - 1, res + ptr + l);
			ptr += l;
		}
	} 
	ll ans = 0;
	init(1, n, 1);
	rep(i, 1, n) lis[i] = pii(res[i], i);
	sort(lis + 1, lis + 1 + n);
	rep(i, 1, n) res[i] = lower_bound(lis + 1, lis + 1 + n, pii(res[i], i)) - lis;
	rep(i, 1, l){
		qx = res[i], qd = 1;
		add(1, n, 1);
	}
	rep(i, 1, n + 1 - l){
		qd = k;
		ans += lis[get(1, n, 1)].fi;
		qx = res[i], qd = -1, add(1, n, 1);
		if (i + l <= n) qx = res[i + l], qd = 1, add(1, n, 1);
	}
	if (!op) return ans;
	else return ans; 
}
ll cal2(bool op){
	rep(i, 1, n) res[i] = _res[i];
	int left = n / l * l;
	rep(i, 1, l) swap(res[left - i + 1], res[l - i + 1]);  
	if (op){
		int ptr = 1;
		rep(i, 1, n / l){
			reverse(res + ptr + k - 1, res + ptr + l);
			ptr += l;
		}
	} 
	ll ans = 0;
	init(1, n, 1);
	rep(i, 1, n) lis[i] = pii(res[i], i);
	sort(lis + 1, lis + 1 + n);
	rep(i, 1, n) res[i] = lower_bound(lis + 1, lis + 1 + n, pii(res[i], i)) - lis;
	rep(i, 1, l){
		qx = res[i], qd = 1;
		add(1, n, 1);
	}
	rep(i, 1, n + 1 - l){
		qd = k;
		ans += lis[get(1, n, 1)].fi;
		qx = res[i], qd = -1, add(1, n, 1);
		if (i + l <= n) qx = res[i + l], qd = 1, add(1, n, 1);
	}
	if (!op) return max(cal3(0), ans);
	else return min(cal3(1), ans); 
}
ll cal(){
	/*
	rep(i, 1, n) _res[i] = res[i]; 
		int ptr = 1;
		rep(i, 1, n / l){
			reverse(res + ptr + k - 1, res + ptr + l);
			ptr += l;
		} 
	*/
	ll ans = 0;
	init(1, n, 1);
	rep(i, 1, n) lis[i] = pii(res[i], i);
	sort(lis + 1, lis + 1 + n);
	rep(i, 1, n) res[i] = lower_bound(lis + 1, lis + 1 + n, pii(res[i], i)) - lis;
	rep(i, 1, l){
		qx = res[i], qd = 1;
		add(1, n, 1);
	}
	rep(i, 1, n + 1 - l){
		qd = k;
		ans += lis[get(1, n, 1)].fi;
		qx = res[i], qd = -1, add(1, n, 1);
		if (i + l <= n) qx = res[i + l], qd = 1, add(1, n, 1);
	}
	//if (!op) return max(cal2(0), ans);
	//else return min(cal2(1), ans); 
	return ans;
}
int main(){
	//ios :: sync_with_stdio(false);
	//cin.tie(0);
	int T; read(T);
	while (T--){
		read(n), read(l), read(k);
		rep(i, 1, n) read(a[i]);
		sort(a + 1, a + 1 + n);
		
		
		int lptr = 1, rptr = n, ptr = 0, _ptr;
		while (lptr <= rptr){
			rep(i, 1, l - k) {
				res[++ptr] = a[lptr++];
				if (lptr > rptr) goto done2;
			}
			_ptr = ptr;
			rep(i, 1, k){
				res[++ptr] = a[rptr--];
				if (lptr > rptr){
					//reverse(res + _ptr + 1, res + ptr + 1);
					goto done2;
				}
			}
			//reverse(res + _ptr + 1, res + ptr + 1);
		}
		
		done2: printf("%lld ", cal());
		#ifdef Renatus
		cerr << endl; rep(i, 1, n) cerr << res[i] << ' '; cerr << endl;
		#endif
		
		lptr = 1, rptr = n, ptr = 0, _ptr;
		while (lptr <= rptr){
			rep(i, 1, k - 1) {
				res[++ptr] = a[rptr--];
				if (lptr > rptr) goto done;
			}
			_ptr = ptr;
			rep(i, 1, l - k + 1){
				res[++ptr] = a[lptr++];
				if (lptr > rptr){
					//reverse(res + _ptr + 1, res + ptr + 1);
					goto done;
				}
			}
			//reverse(res + _ptr + 1, res + ptr + 1);
		}
		
		done: printf("%lld\n", cal()); 
		#ifdef Renatus
		rep(i, 1, n) cerr << res[i] << ' '; cerr << endl;
		#endif
		
		
	}
	
	return 0;
}

/*
56 21
15 10
15 10
54 34
*/
