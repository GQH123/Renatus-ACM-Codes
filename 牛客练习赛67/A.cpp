#include <bits/stdc++.h>
#define maxn 200020
#define maxm
#define maxb 
#define maxs
#define M 
#define pii pair<int, int>
#define pdd pair<double, double>
#define uint unsigned int
#define ull unsigned long long int
#define ll long long int 
#define lowbit(x) x & -x
#define fi first
#define se second
#define pb push_back
#define next NEXT
#define hash HASH
#define ls ch[x][0]
#define rs ch[x][1]
#define pi 3.141592653589793
#define ei 2.718281828459045
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next) 
using namespace std;

char s[maxn];

int main(){
    
    
    while (gets(s + 1)){
    	int n = strlen(s + 1); 
        bool first = 1;
        rep(i, 1, n){
            if (!isdigit(s[i])) continue; 
            while (i <= n && s[i] == '0') i++;
            bool f = 1;
            while (i <= n && isdigit(s[i])){
            	if (f){
            		if (!first) printf(" ");
            		else first = 0;
            		f = 0;
            	}
                printf("%c", s[i]);
                i++;
            } 
            if (f) {
            	if (!first) printf(" ");
            	else first = 0;
            	printf("0");
            }
            i--;
        }
        printf("\n"); 
    }
    return 0;
}
