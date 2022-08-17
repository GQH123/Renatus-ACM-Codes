#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
//#define fl cout.flush()
#define maxn 2048
#define ll long long int 
using namespace std;

int n, k;
bool vis[maxn]; 

int main(){
	
		//freopen("div2F.in", "r", stdin);
		
	ios :: sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	int s = n / k; char ch;
	rep(j, 1, s){
		if (j != 1) cout << "R" << endl, cout.flush();
		rep(i, (j - 1) * k + 1, j * k){
			cout << "? " << i << endl, cout.flush();
			cin >> ch;
			if (ch == 'Y') vis[i] = 1;
		}
		int fi = (j - 1) * k + 1;
		rep(i, j * k + 1, n){
			cout << "? " << i << endl, cout.flush();
			cin >> ch;
			if (ch == 'Y') vis[i] = 1;
			cout << "? " << fi << endl, cout.flush();
			cin >> ch;
		}
	}
	int ans = 0;
	rep(i, 1, n) if (!vis[i]) ans++;
	cout << "! " << ans << endl, cout.flush();
	return 0;
}
