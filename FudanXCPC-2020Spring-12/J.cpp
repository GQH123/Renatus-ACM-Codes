#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define maxn 500020
#define ms(a, b) memset(a, b, sizeof(a))
//#define DEBUG
using namespace std;

namespace PRE{
	int t1[maxn], t2[maxn], cnt[maxn], sa[maxn];
	void init(char* s, int n, int m){
		int *x = t1, *y = t2;
		srep(i, 0, n) cnt[x[i] = s[i] - 'a']++;
		srep(i, 1, m) cnt[i] += cnt[i - 1];
		per(i, n - 1, 0) sa[--cnt[x[i]]] = i;
		for (register int k = 1; k <= n; k <<= 1){
			int p = 0;
			per(i, n - 1, n - k) y[p++] = i;
			srep(i, 0, n) if (sa[i] >= k) y[p++] = sa[i] - k;
			ms(cnt, 0);
			srep(i, 0, n) cnt[x[y[i]]]++;
			srep(i, 1, m) cnt[i] += cnt[i - 1];
			per(i, n - 1, 0) sa[--cnt[x[y[i]]]] = y[i];
			swap(x, y), p = 0;
			srep(i, 0, n) x[sa[i]] = (!i || y[sa[i]] != y[sa[i - 1]] || y[sa[i] + k] != y[sa[i - 1] + k]) ? p++ : p - 1;
			m = p;
			if (m >= n) break;
		}
		srep(i, 0, n) rank[sa[i]] = i;
		int h = 0;
		srep(i, 0, n){
			if (h) h--;
			if (!rank[i]) continue;
			int j = sa[rank[i] - 1];
			while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
			height[rank[i]] = h;
		}
	}
	int mi[maxn << 2]; 
	inline void pu(int o){
		mi[o] = min(mi[o << 1], mi[o << 1 | 1]);
	}
	void _init(int l, int r, int o){
		if (l == r) {mi[o] = height[l]; return;}
		int mid = ((r - l) >> 1) + l;
		_init(l, mid, o << 1), _init(mid + 1, r, o << 1 | 1);
		pu(o);
	}
	int get(int l, int r, int o, int qx, int qy){
		if (qx <= l && r <= qy) return mi[o];
		int mid = ((r - l) >> 1) + l, ans = maxn;
		if (qx <= mid) ans = min(ans, get(l, mid, o << 1, qx, qy));
		if (qy > mid) ans = min(ans, get(mid + 1, r, o << 1 | 1, qx, qy));
		return ans;
	}
}

namespace SUF{
	int t1[maxn], t2[maxn], cnt[maxn], sa[maxn];
	void init(char* s, int n, int m){
		int *x = t1, *y = t2;
		srep(i, 0, n) cnt[x[i] = s[i] - 'a']++;
		srep(i, 1, m) cnt[i] += cnt[i - 1];
		per(i, n - 1, 0) sa[--cnt[x[i]]] = i;
		for (register int k = 1; k <= n; k <<= 1){
			int p = 0;
			per(i, n - 1, n - k) y[p++] = i;
			srep(i, 0, n) if (sa[i] >= k) y[p++] = sa[i] - k;
			ms(cnt, 0);
			srep(i, 0, n) cnt[x[y[i]]]++;
			srep(i, 1, m) cnt[i] += cnt[i - 1];
			per(i, n - 1, 0) sa[--cnt[x[y[i]]]] = y[i];
			swap(x, y), p = 0;
			srep(i, 0, n) x[sa[i]] = (!i || y[sa[i]] != y[sa[i - 1]] || y[sa[i] + k] != y[sa[i - 1] + k]) ? p++ : p - 1;
			m = p;
			if (m >= n) break;
		}
		srep(i, 0, n) rank[sa[i]] = i;
		int h = 0;
		srep(i, 0, n){
			if (h) h--;
			if (!rank[i]) continue;
			int j = sa[rank[i] - 1];
			while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
			height[rank[i]] = h;
		}
	}
	int mi[maxn << 2]; 
	inline void pu(int o){
		mi[o] = min(mi[o << 1], mi[o << 1 | 1]);
	}
	void _init(int l, int r, int o){
		if (l == r) {mi[o] = height[l]; return;}
		int mid = ((r - l) >> 1) + l;
		_init(l, mid, o << 1), _init(mid + 1, r, o << 1 | 1);
		pu(o);
	}
	int get(int l, int r, int o, int qx, int qy){
		if (qx <= l && r <= qy) return mi[o];
		int mid = ((r - l) >> 1) + l, ans = maxn;
		if (qx <= mid) ans = min(ans, get(l, mid, o << 1, qx, qy));
		if (qy > mid) ans = min(ans, get(mid + 1, r, o << 1 | 1, qx, qy));
		return ans;
	}
}

char s[maxn]; int n; 
int mi[maxn << 2], mx[maxn << 2];
inline void pu(int o){
	mi[o] = min(mi[o << 1], mi[o << 1 | 1]);
	mx[o] = max(mx[o << 1], mx[o << 1 | 1]);
}
void init(int l, int r, int o){
	if (l == r) {mi[o] = maxn, mx[o] = -1; return;}
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	pu(o);
}
int getmi(int l, int r, int o, int qx){
	if (
}
int getmx(int l, int r, int o, int qx){
	
}
void add(int id, bool op, int l, int r){
	if (l < r) res++,
	else {
	}
	
}
void del(int id, bool op, int l, int r){
	
}
void recover(){
	
}

void work(int k){ 
	int ans = 0;
	rep(i, 1, k) add(i, 1, 1, i - 1);
	ans = max(ans, res);
	rep(i, 2, n - k + 1){
		del(i - 1, 0, i - 1, i + k - 2);
		add(i - 1 + k, 1, i, i + k - 2);
		ans = max(ans, res);
	}
	printf("%d\n", ans);
	recover();
}

int main(){
	scanf("%s", s);
	n = strlen(s);
	
	reverse(s, s + n);
	PRE :: init(s, n, 26), PRE :: _init(0, n - 1, 1);
	reverse(s, s + n);
	SUF :: init(s, n, 26), SUF :: _init(0, n - 1, 1);
	
	int T, k;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &k);
		work(k);
	}
}
