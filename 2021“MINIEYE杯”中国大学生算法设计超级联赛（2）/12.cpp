#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define ll long long int 
#define maxn 200020
using namespace std;

char s[maxn];
int main(){
    int T; cin >> T;
    while (T--){
        string s;
        cin >> s;
        //printf("%d\n", s.find("114514"));
        if (s.find("114514") != -1) {
            puts("AAAAAA");
        }
        else puts("Abuchulaile");
    }
    return 0;
}
