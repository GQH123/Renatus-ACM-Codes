#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 300
#define pb push_back
using namespace std;

int sg[maxn][maxn];
vector<int> s;

int main(){
	int T;
	cin >> T;
	
	sg[0][0] = 0;
	srep(i, 1, maxn) sg[i][0] = sg[0][i] = i; 
	
	srep(i, 1, maxn) {
		srep(j, 1, maxn) { 	
			s.clear();
			srep(k, 0, i) s.pb(sg[k][j]); 
			srep(k, 0, j) s.pb(sg[i][k]);
			rep(k1, 0, i) rep(k2, 0, j) if (k1 + k2 > 0 && abs(k1 - k2) <= T) s.pb(sg[i - k1][j - k2]); 
			sort(s.begin(), s.end());
			unique(s.begin(), s.end());
			int si = s.size(), ptr = 0;
			rep(k, 0, si) {
				if (k == si) {
					sg[i][j] = ptr;
					break;
				}
				if (s[k] != ptr) {
					sg[i][j] = ptr;
					break;
				}
				ptr++;
			}
		}
	}
	//srep(i, 0, maxn) {srep(j, 0, maxn) cout << sg[i][j] << ' '; cout << endl;} cout << endl;
	int ct = 0;
	srep(i, 0, maxn) srep(j, i, maxn) if (!sg[i][j]) cout << ct << ' ' << i << ' ' << j << endl, ct++;
	
	//cout << endl << sg[2][4] << endl;
	return 0;
}

/*
0 0
1 2
3 5
4 7
6 10
8 13
9 15
11 18
12 20
14 23
16 26
17 28
19 31
21 34
22 36
24 39
25 41
27 44
29 47
30 49
32 52
33 54
35 57
37 60
38 62
40 65
42 68
43 70
45 73
46 75
48 78
50 81
51 83
53 86
55 89
56 91
58 94
59 96
61 99
*/

/*
0 0
1 3
2 6
4 10
5 13
7 17
8 20
9 23
11 27
12 30
14 34
15 37
16 40
18 44
19 47
21 51
22 54
24 58
25 61
26 64
28 68
29 71
31 75
32 78
33 81
35 85
36 88
38 92
39 95
41 99
*/
