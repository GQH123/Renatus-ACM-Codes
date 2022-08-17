#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 300020 
#define ll long long int 
using namespace std;

struct vec{
	ll x, y;
	vec(ll x, ll y) : x(x), y(y){}
	vec(){}
}p[maxn], pre[maxn];
vec operator + (vec a, vec b){
	return vec(a.x + b.x, a.y + b.y);
}
vec operator - (vec a, vec b){
	return vec(a.x - b.x, a.y - b.y);
}
ll cross(vec a, vec b){
	return a.x * b.y - a.y * b.x;
}

int que[maxn];
int good[maxn];
int head = 0, tail = 0;
int n;
int ans[maxn], cs = 0;

int main(){
	while (scanf("%d", &n) == 1 && n){
		cs = 0;
		rep(i, 1, n) scanf("%lld%lld", &p[i].y, &p[i].x); 
		ll nowx = 0, nowy = 0;
		per(i, n, 1){
			nowx += p[i].x, nowy += p[i].y;
			pre[i - 1] = vec(nowx, nowy);
		}
		head = tail = 0;
		srep(i, 1, n){
			while (head && (p[que[head]].x >= p[i].x || p[que[head]].y >= p[i].y)) head--;
			while (head > 1 && (cross(p[que[head]] - p[que[head - 1]], p[i] - p[que[head]]) >= 0)) head--;
			que[++head] = i;
			while (head > 1 && (cross(p[que[head]] - p[que[head - 1]], pre[i]) > 0)) head--;
			good[i + 1] = que[head];
		}
		head = tail = 0;
		sper(i, n, 1){	
			while (head > tail && (p[que[head]].x <= p[i].x || p[que[head]].y <= p[i].y)) head--;
			while (head > tail + 1 && (cross(p[que[head]] - p[que[head - 1]], p[i] - p[que[head]]) >= 0)) head--;
			que[++head] = i;
			while (head > tail + 1 && (cross(p[que[tail + 2]] - p[que[tail + 1]], pre[i - 1]) > 0)) tail++;
			if (cross(pre[i - 1], p[good[i]] - p[que[tail + 1]]) > 0) ans[++cs] = i - 1;
		} 
		printf("%d\n", cs);
		per(i, cs, 1) printf("%d\n", ans[i]);
	} 
	return 0;
}
