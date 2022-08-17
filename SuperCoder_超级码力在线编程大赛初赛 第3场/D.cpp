#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

class Solution {
public:
    /**
     * @param s: string need to be transformed
     * @param k: minimum char can be transformed in one operation
     * @return: minimum times of transforming all char into '1'
     */
    int perfectString(string &s, int k) {
        int n = s.length(), ans = 0;
        srep(i, 0, n) {
            int _i = i; char now = s[i];
            while (i < n && s[i] == now) i++;
            int l = i - _i; i--;
            if (now == '0') ans += (now - 1) / k + 1;
        }
        return ans;
    }
}obj;

int main(){
    string s; int k;
    cin >> s >> k;
    cout << obj.perfectString(s, k);
}
