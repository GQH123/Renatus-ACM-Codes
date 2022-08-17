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
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

namespace Fast_Read{
    char buffer[maxr], *p1, *p2;
    template<class T> void read_signed(T& x){
        char ch = gc(); x = 0; bool f = 1;
        while (!isdigit(ch) && ch != '-') ch = gc();
        if (ch == '-') f = 0, ch = gc();
        while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
        x = (f) ? x : -x;
    }
    template<class T, class... Args> void read_signed(T& x, Args&... args){
        read_signed(x), read_signed(args...);
    }
    template<class T> void read_unsigned(T& x){
        char ch = gc(); x = 0;
        while (!isdigit(ch)) ch = gc(); 
        while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = gc(); 
    }
    template<class T, class... Args> void read_unsigned(T& x, Args&... args){
        read_unsigned(x), read_unsigned(args...);
    }
    #define isletter(ch) ('a' <= ch && ch <= 'z')
    int read_string(char* s){
        char ch = gc(); int l = 0;
        while (!isletter(ch)) ch = gc();
        while (isletter(ch)) s[l++] = ch, ch = gc();
        s[l] = '\0'; return l;
    }
}using namespace Fast_Read; 

int _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

#define read read_unsigned
#define reads read_string 
#define writes puts

#define maxn 2000020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

char s[maxn];
int num[26], num2[26][26], num3[26][26][26], num4[26][26][26][26];
int ct, ct2, ct3, ct4;
set<int> ss;
int main(){
	int l; read(l);
	reads(s);
	srep(i, 0, l) {
		if (num[s[i] - 'a'] == 0) {
			if (!ct) ss.insert(1); 
			ct++;
		}
		else if (num[s[i] - 'a'] == 1) {
			ct--;
			if (!ct) ss.erase(1);
		}
		num[s[i] - 'a']++;
		
		if (i) {
			if (num2[s[i - 1] - 'a'][s[i] - 'a'] == 0) {
				if (!ct2) ss.insert(2);
				ct2++;
			}
			else if (num2[s[i - 1] - 'a'][s[i] - 'a'] == 1) {
				ct2--;
				if (!ct2) ss.erase(2);
			}
			num2[s[i - 1] - 'a'][s[i] - 'a']++;
		}
		
		if (i > 1) {
			if (num3[s[i - 2] - 'a'][s[i - 1] - 'a'][s[i] - 'a'] == 0) {
				if (!ct3) ss.insert(3);
				ct3++;
			}
			else if (num3[s[i - 2] - 'a'][s[i - 1] - 'a'][s[i] - 'a'] == 1) {
				ct3--;
				if (!ct3) ss.erase(3);
			}
			num3[s[i - 2] - 'a'][s[i - 1] - 'a'][s[i] - 'a']++;
		}
		
		if (i > 2) {
			if (num4[s[i - 3] - 'a'][s[i - 2] - 'a'][s[i - 1] - 'a'][s[i] - 'a'] == 0) {
				if (!ct4) ss.insert(4);
				ct4++;
			}
			else if (num4[s[i - 3] - 'a'][s[i - 2] - 'a'][s[i - 1] - 'a'][s[i] - 'a']  == 1) {
				ct4--;
				if (!ct4) ss.erase(4);
			}
			num4[s[i - 3] - 'a'][s[i - 2] - 'a'][s[i - 1] - 'a'][s[i] - 'a'] ++;
		}
		
		if (ss.empty()) printf("5\n");
		else printf("%d\n", *ss.begin());
	}
	return 0;
}

