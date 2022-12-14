#include <bits/stdc++.h>
#define maxr 100000
#define maxn 300005
#define ll long long int 
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n;
int prufer[maxn];
bool last[maxn];
set<int> s;
int maxv;
void build(){
	printf("1\n");
	printf("%d\n", n);
	per(i, n - 2, 1) if (!s.count(prufer[i])) last[i] = 1, s.insert(prufer[i]);
	s.clear();
	rep(i, 1, n) s.insert(i);
	rep(i, 1, n - 2) if (s.count(prufer[i])) s.erase(prufer[i]);
	rep(i, 1, n - 2){
		printf("%d %d %d\n", prufer[i], *s.begin(), rand() % maxv + 1);
		s.erase(s.begin());
		if (last[i]) s.insert(prufer[i]);
	}
	printf("%d %d %d\n", *(++s.begin()), *s.begin(), rand() % maxv + 1);
}

int main(){
	srand(time(NULL));
	freopen("K.in", "w", stdout);
	scanf("%d %d", &n, &maxv);
	rep(i, 1, n - 2) prufer[i] = rand() % n + 1;
	build();
	return 0;
}
