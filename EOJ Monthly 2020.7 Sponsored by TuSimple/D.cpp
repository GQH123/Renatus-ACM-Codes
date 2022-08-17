#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long int 
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define maxn 500020 
#define M 998244353
#define rank RANK
#define ms(a, b) memset(a, b, sizeof(a))
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define maxr 200000
using namespace std;

char buffer[maxr], *p1, *p2;
void reads(char* s){ //本处以字符集为 lower-case 为示例
	char ch = gc();
	while ('0' <= ch && ch <= '9') *(s++) = ch, ch = gc();
} 

char s[maxn];
int t1[maxn], t2[maxn], cnt[maxn], rank[maxn], sa[maxn], height[maxn];
//t1, t2, cnt为基数排序辅助数组，其余为后缀数组算法标准包含数组，注意 height 数组有意义下标从 1 开始
void build(int n, int m){ //串长为 n, 字符集大小为 m， 字符串下标从 0 开始
	int *x = t1, *y = t2;
	srep(i, 0, n) cnt[x[i] = s[i] - '0']++; //本处以字符集为 lower-case 为示例
	srep(i, 1, m) cnt[i] += cnt[i - 1];
	per(i, n - 1, 0) sa[--cnt[x[i]]] = i; 
	for (register int k = 1; k <= n; k <<= 1){
		int p = 0;
		per(i, n - 1, n - k) y[p++] = i; //此处最好反向，原因未知
		srep(i, 0, n) if (sa[i] >= k) y[p++] = sa[i] - k;
		ms(cnt, 0);
		srep(i, 0, n) cnt[x[y[i]]]++;
		srep(i, 1, m) cnt[i] += cnt[i - 1];
		per(i, n - 1, 0) sa[--cnt[x[y[i]]]] = y[i];
		swap(x, y); p = 0; //交换以后 y 中存储每位的当前排名信息
		srep(i, 0, n) x[sa[i]] = (!i || y[sa[i]] != y[sa[i - 1]] || y[sa[i] + k] != y[sa[i - 1] + k]) ? p++ : p - 1;
		m = p; //更新当前的排名数量
		if (m >= n) break; //其实理论上不会超过 n 
		
	}
	srep(i, 0, n) rank[sa[i]] = i;
	int h = 0;
	srep(i, 0, n){
		if (h) h--;
		if (!rank[i]) continue;
		int j = sa[rank[i] - 1];
		while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
		height[rank[i]] = h;
	} // height 数组基于 sa 数组而非原字符串数组
}
int power(int x, ll y){
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = 1ll * ans * con % M;
		con = 1ll * con * con % M;
		y >>= 1;
	}
	return ans;
}
int n;
int pre[maxn], len[maxn];

int mi[maxn << 2];
int qx, qy, qd;
void init(int l, int r, int o){
	if (l == r) {mi[o] = height[l]; return;}
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	mi[o] = min(mi[o << 1], mi[o << 1 | 1]);
}
int get(int l, int r, int o){
	if (qx <= l && r <= qy) return mi[o];
	int mid = ((r - l) >> 1) + l, ans = n << 1;
	if (qx <= mid) ans = min(ans, get(l, mid, o << 1));
	if (qy > mid) ans = min(ans, get(mid + 1, r, o << 1 | 1));
	return ans;
}

int gethei(int i, int j){
	qx = min(rank[i], rank[j]), qy = max(rank[i], rank[j]);
	qx++;
	if (qx <= qy) return get(1, n - 1, 1);
	cerr << rank[i] << ' ' << rank[j] << endl;
	cerr << qx << ' ' << qy << endl;
	assert(false);
}
bool cmp(const int i, const int j){	
	if (i == j) return 0;
	if (i > j){  
		if (gethei(j + 1, 0) < i - j) return rank[j + 1] > rank[0];
		else {
			if (gethei(0, i - j) < j + 1) return rank[0] > rank[i - j];
			return 0;
		}
	}
	else {
		if (gethei(0, i + 1) < j - i) return rank[0] > rank[i + 1];
		else {
			if (gethei(j - i, 0) < i + 1) return rank[j - i] > rank[0];
			return 0;
		} 
	}
}
int lis[maxn];
int main(){ 
	reads(s);
	n = strlen(s);
	if (n == 1){
		printf("%s", s);
		return 0;
	}
	srep(i, 0, n){
		pre[i] = (!i) ? (s[i] - '0') : ((1ll * pre[i - 1] * 10 + s[i] - '0') % M);
		len[i] = i + 1;
		lis[i] = i;
	}
	build(n, 10);
	init(1, n - 1, 1);
	sort(lis, lis + n, cmp);
	ll sum = 1ll * n * (n + 1) / 2;
	int res = 0;
	srep(i, 0, n){
		sum -= (lis[i] + 1);
		res += 1ll * power(10, sum) * pre[lis[i]] % M, mo(res);
	}
	printf("%d\n", res);
	//注意，示例部分也非常重要，请仔细阅读
	
	/*
		int n;
		reads(s), n = strlen(s);
		build(n, 26); //本处以字符集为 lower-case 为示例
		srep(i, 0, n) printf("%d ", sa[i] + 1); printf("\n"); // 此处遵循 UOJ 要求加 1 输出
		//srep(i, 0, n) printf("%d ", rank[i]); printf("\n");
		srep(i, 1, n) printf("%d ", height[i]); printf("\n");
	*/
	return 0;
}
