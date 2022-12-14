#include <bits/stdc++.h>
#define maxr 100000
#define maxn 100005
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ms(a, b) memset(a, b, sizeof(a))
#define uint unsigned int
#define Author Renatus
using namespace std;

/*  
**	这是一个 线性基 (LinearBase) 的模板
**	有关信息维护的标准以 LOJ#113. 最大异或和，LOJ#114. k 大异或和 的题目要求为准
**	在实际使用中，可以对有关部分作出适当改变以适应不同题目要求
**	需要说明的部分已经给出较为详尽的注释
** 	作者：Renatus
*/

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (ch != '-' && !('0' <= ch && ch <= '9')) ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
// 有的时候，数组开小不会产生问题，但是当打开 -O2 优化后则极易产生问题
struct LinearBase{
	uint a[32]; //非常重要！数组一定不要开小
	LinearBase() { ms(a, 0); }
	int get_size(){
		int siz = 0;
		per(i, 31, 0) if (a[i]) siz++;
		return siz;
	}
	bool insert(uint v){
		per(i, 31, 0) {
			if ((v >> i) & 1){
				if (!a[i]) { a[i] = v; return true; }
				else v ^= a[i];
			}
			if (!v) return false;
		}
		//assert(false);
		return true;
	}
	void process(){ //将 01 矩阵化为行简化阶梯型（高斯亚当消元法）	
		per(i, 31, 0) if (a[i]) rep(j, i + 1, 31) a[j] = min(a[j], a[j] ^ a[i]);  
	}
	uint get_kth_min(uint k){ //注意此处的 k 可以为 0 ，即空集（最小的那个）,必须在行简化阶梯型下使用
		uint ans = 0;
		rep(i, 0, 31){
			if (a[i]) {
				if (k & 1) ans ^= a[i];
				k >>= 1;
				if (!k) return ans;
			}
		}
		return (k) ? -1 : ans; 
	} // 注意，此函数只能用于 不同的 异或和中求第 k 小
	bool express(uint v){
		per(i, 31, 0) {
			if ((v >> i) & 1){
				if (!a[i]) return false;
				else v ^= a[i];
			}
			if (!v) return true;
		}
		//assert(false);
		return false;
	}
	void print(){
		per(i, 31, 0){
			uint x = a[i], now = ((uint)1 << 31);
			per(i, 31, 0) printf("%d", (x & now) ? 1 : 0), now >>= 1;
			printf("\n");
		}
	}
	void print(int bit){
		per(i, bit, 0){
			uint x = a[i], now = ((uint)1 << bit);
			per(i, bit, 0) printf("%d", (x & now) ? 1 : 0), now >>= 1;
			printf("\n");
		}
	}
}; //在线性基中，int 一定要谨慎使用

LinearBase merge(LinearBase& A, LinearBase& B){
	LinearBase C;
	per(i, 31, 0) if (A.a[i]) C.insert(A.a[i]);
	per(i, 31, 0) if (B.a[i]) C.insert(B.a[i]);
	return C;
} //注意，合并操作的复杂度为O(log^2)

LinearBase intersect(LinearBase& A, LinearBase& B){
	LinearBase C, D, E;
	per(i, 31, 0) if (A.a[i]) C.insert(A.a[i]), D.a[i] = (uint)1 << i;
	rep(i, 0, 31){
		if (!B.a[i]) continue;
		uint v = 0, x = B.a[i];
		per(i, 31, 0) {
			if ((x >> i) & 1){
				if (C.a[i]) x ^= C.a[i], v ^= D.a[i];
				else { C.a[i] = x, D.a[i] = v; break; }
			}
		}
		if (!x) {
			rep(i, 0, 31){
				if (v & 1) x ^= C.a[i];
				v >>= 1;
			}
			E.insert(x);
		}
	}
	return E;
} //注意，求交操作的复杂度为O(log^2)

LinearBase A[maxn << 1];
int qx, qy;
uint qd;
void pu(int o){
	A[o] = intersect(A[o << 1], A[o << 1 | 1]);
}
void init(int l, int r, int o){
	if (l == r){
		int sz; uint x;
		read(sz); rep(i, 1, sz) read(x), A[o].insert(x);
		return;
	}
	int m = ((r - l) >> 1) + l;
	init(l, m, o << 1), init(m + 1, r, o << 1 | 1);
	pu(o);
}

bool query(int l, int r, int o){
	if (qx <= l && r <= qy) return A[o].express(qd); 
	int m = ((r - l) >> 1) + l;
	if (qx <= m) if (!query(l, m, o << 1)) return false;
	if (qy > m) if (!query(m + 1, r, o << 1 | 1)) return false;
	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
	#endif
	//注意，示例部分也非常重要，请仔细阅读
	
	/*
		//LOJ#113. 最大异或和
		ll x; 
		int n;
		read(n);
		rep(i, 1, n) read(x), A.insert(x);
		A.process(); //要先化为行简化阶梯型
		printf("%lld", A.get_kth_min((1ll << A.get_size()) - 1));
	*/
	
	/*
		//LOJ#114. k 大异或和
		ll x;
		int n, m;
		read(n);
		rep(i, 1, n) read(x), A.insert(x);
		A.process();
		read(m);
		int d = (A.get_size() < n) ? 1 : 0; //重要：修正 0 的非空集表示
		rep(i, 1, m) read(x), printf("%lld\n", A.get_kth_min(x - d));
	*/
	
	int n, m;
	read(n), read(m);
	init(1, n, 1);
	rep(i, 1, m){
		read(qx), read(qy), read(qd);
		printf(query(1, n, 1) ? "YES\n" : "NO\n");
	}
	return 0;
}
