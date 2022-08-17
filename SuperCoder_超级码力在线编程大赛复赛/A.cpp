#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std; 

int n, mi[10][10], num[10];

class Solution {
public:
    /**
     * @param s: number string
     * @return: Find the key
     *
     */
    int key(string& s) {
        // write your code here
       	n = s.length();
       	rep(i, 0, 9) rep(j, 0, 9) mi[i][j] = 0;
       	rep(i, 0, 9) num[i] = 0;
       	int ans = 0;
       	srep(i, 0, n) {
       		int x = s[i] - '0';
       		num[x]++;
       		rep(j, 0, 9) {
       			if (j == x || !num[j]) continue;
       			ans = max(ans, num[j] - num[x] - mi[j][x]);
       			mi[j][x] = min(mi[j][x], num[j] - num[x]); 
       		}//(j, x)
       		rep(j, 0, 9) {
       			if (j == x || !num[j]) continue;
       			ans = max(ans, num[x] - num[j] - mi[x][j]);
       			mi[x][j] = min(mi[x][j], num[x] - num[j]);
       		}//(x, j)
       	}
       	return ans;
    }
};

int main(){
	string s;
	while (1) {
		cin >> s;
		cout << Solution().key(s) << endl;
	} 
	return 0;
}

