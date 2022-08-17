#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int num[64];
int cn = 0;
bool judge(ll x){
	cn = 0;
	while (x){
		num[++cn] = x % 10;
		x /= 10;
	}
	int year = num[cn] * 1000 + num[cn - 1] * 100 + num[cn - 2] * 10 + num[cn - 3];
	int month = num[cn - 4] * 10 + num[cn - 5];
	int dday = num[cn - 6] * 10 + num[cn - 7];
	int h = num[cn - 8] * 10 + num[cn - 9];
	int m = num[cn - 10] * 10 + num[cn - 11];
	int s = num[cn - 12] * 10 + num[cn - 13];
	if (!(0 <= s && s <= 59)) return false;
	if (!(0 <= m && m <= 59)) return false;
	if (!(0 <= h && h <= 23)) return false;
	if (!(1 <= month && month <= 12)) return false;
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) day[2] = 29;
	else day[2] = 28;
	if (!(1 <= dday && dday <= day[month])) return false;
	return true;
}

int main(){

		freopen("A.in", "r", stdin);
	
	int k;
	scanf("%d", &k);
	if (!k) {printf("20200122100202"); return 0;}
	rep(i, 2020013, 9999999){
		ll x = (ll)i * 10000000;
		int _i = i, _x = 0;
		while (_i){
			_x = _x * 10 + _i % 10;
			_i /= 10;
		}
		x += _x;
		if (judge(x)) k--;
		if (!k) {printf("%lld", x); return 0;}
	}
	return 0;
}
