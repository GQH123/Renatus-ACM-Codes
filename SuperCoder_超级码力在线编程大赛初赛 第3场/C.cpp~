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

int num[30];
class Solution {
public:
    /**
     * @param s: a string for this game 
     * @return: return whether Alice can win this game
     */
    bool stringGame(string &s) {
        int n = s.length(), mx = 0;
        srep(i, 0, n) if ('a' <= s[i] && s[i] <= 'z') num[s[i] - 'a']++;
        rep(i, 0, 25) mx = max(mx, num[i]);
        if (mx <= 1) {
            int res = 0;
            rep(i, 0, 25) res ^= num[i];
            if (!res) return true;
            else return false;
        }
        else {
            int res = 0;
            rep(i, 0, 25) res ^= num[i];
            if (res) return true;
            else return false;
        } 
    }
}; 
