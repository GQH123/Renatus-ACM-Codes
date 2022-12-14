#include <bits/stdc++.h>
#define maxr 100000
#define maxn 500000 //参数可调
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ms(a, b) memset(a, b, sizeof(a))
#define rank RANK //适应编译器要求
#define ll long long int 
#define Author Renatus
using namespace std;


char buffer[maxr], *p1, *p2;
void reads(char* s){ //本处以字符集为 lower-case 为示例
	char ch = gc();
	while ('a' <= ch && ch <= 'z') *(s++) = ch, ch = gc();
}

char s[maxn], t[maxn];
int t1[maxn], t2[maxn], cnt[maxn], rank[maxn], sa[maxn], height[maxn];
//t1, t2, cnt为基数排序辅助数组，其余为后缀数组算法标准包含数组，注意 height 数组有意义下标从 1 开始
void build(int n, int m){ //串长为 n, 字符集大小为 m， 字符串下标从 0 开始
	int *x = t1, *y = t2;
	srep(i, 0, n) cnt[x[i] = s[i]]++; //本处以字符集为 lower-case 为示例
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

struct Palindrome_Tree{
	int last, tot, go[maxn][26], fail[maxn], len[maxn];
	void init(){fail[0] = fail[1] = 1, len[tot = 1] = -1;}
	void build(char* s){
		int n = strlen(s + 1), now;
		rep(i, 1, n) {
			now = last;
			while (s[i] != s[i - 1 - len[now]]) now = fail[now];
			if (!go[now][s[i] - 'a']){
				int _now = fail[now];
				while (s[i] != s[i - 1 - len[_now]]) _now = fail[_now];
				fail[++tot] = go[_now][s[i] - 'a'], len[tot] = len[now] + 2, go[now][s[i] - 'a'] = tot;
			}
			last = go[now][s[i] - 'a'];
		}
	}//字符串下标从 1 开始
}pt;
int main(){
	#ifndef ONLINE_JUDGE
		freopen("I.in", "r", stdin);
	#endif
	int n;
	reads(s);
	n = strlen(s);
	srep(i, 0, n) t[i + 1] = s[i], s[i] -= 'a';
	s[n] = 26;
	rep(i, n + 1, 2 * n) s[i] = s[(n << 1) - i];
	ll ans = -(ll)(n + 1) * (n + 1);
	n = (n << 1 | 1);
	build(n, 27);
	ans += n - sa[0];
	srep(i, 1, n) ans += n - sa[i], ans -= height[i];
	pt.init();
	pt.build(t);
	ans += pt.tot - 1;
	//printf("%d %lld %lld", pt.tot - 1, ans, ans >> 1);
	printf("%lld", ans >> 1);
	return 0;
}
