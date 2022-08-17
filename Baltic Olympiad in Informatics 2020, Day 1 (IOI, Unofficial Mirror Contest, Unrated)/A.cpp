#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 
#define ll long long int 
using namespace std;

ll n;
set<ll> hav;
ll solve(ll l, ll r){
	ll lptr = n / 4, rptr = -1;
	int op = 0, res = -1;
	while (l != r){	
		ll mid = ((r - l) >> 1) + l;
		if (!op) {
			rptr = lptr + mid;
			cout << "? " << rptr << endl;
			cin >> res;
			if (res) r = mid;
			else l = mid + 1;
		}
		else {
			lptr = rptr - mid;
			cout << "? " << lptr << endl;
			cin >> res;
			if (res) r = mid;
			else l = mid + 1;
		} 
		op ^= 1;
	}
	return l;
}

ll solve2(ll l, ll r){
	ll lptr = n / 4, rptr = -1;
	int op = 0, res = -1;
	while (l != r){	
		ll mid = ((r - l) >> 1) + l;
		if (!op) {
			rptr = lptr + mid; 
			if (rptr > n) rptr = n;
			while (hav.count(rptr)) rptr--;
			mid = rptr - lptr; 
			cout << "? " << rptr << endl, hav.insert(rptr);                     
			cin >> res;
			if (res) r = mid;
			else l = mid + 1; 
		}
		else {
			lptr = rptr - mid;
			if (lptr < 1) lptr = 1;
			while (hav.count(lptr)) lptr++;
			mid = rptr - lptr; 
			cout << "? " << lptr << endl, hav.insert(lptr);
			cin >> res;
			if (res) r = mid;
			else l = mid + 1;
		} 
		op ^= 1;
	}
	return l;
}

int BF(){
	int ptr = 1, res = -1;
	cout << "? " << ptr << endl;
	cin >> res;
	int nowC = n;
	rep(i, 2, n){
		if (i & 1) {
			ptr = ((i + 1) >> 1);
			cout << "? " << ptr << endl;
			cin >> res;
			if (!res) return nowC;
		}
		else {
			ptr = (n + 1) - (i >> 1);
			cout << "? " << ptr << endl;
			cin >> res;
			if (!res) return nowC;
		}
		nowC--;
	}
	return nowC;
}

int main(){
	int T;
	cin >> T;
	while (T--){ 
		cin >> n;
		if (n <= 64) {
			int ans = BF();
			cout << "= " << ans << endl;
			continue; 
		} 
		hav.clear();
		ll mid = ((n - 1) >> 1) + 1;
		cout << "? " << n / 4 << endl, hav.insert(n / 4);
		int res = -1;
		cin >> res;
		ll ans = solve2(1, n);
		cout << "= " << ans << endl;
	}
	return 0;
}
