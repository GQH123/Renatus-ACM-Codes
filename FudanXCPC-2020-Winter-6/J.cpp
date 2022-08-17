#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 400020
using namespace std;

int n, q, root;
int a[maxn];
set<int> pre, suf;
set<int> :: iterator it, it2;
void debug(){
	printf("%d\n", root);
	for (it = pre.begin(); it != pre.end(); it++){
		printf("%d ", *it);
	}
	printf("\n");
	for (it = suf.begin(); it != suf.end(); it++){
		printf("%d ", *it);
	}
	printf("\n");
}
int main(){
		
		freopen("J.in", "r", stdin);
		
	scanf("%d%d", &n, &q);
	rep(i, 1, n) scanf("%d", a + i);
	int mx = -1;
	rep(i, 1, n) if (a[i] > mx) pre.insert(i), mx = a[i]; 
	mx = -1;
	per(i, n, 1) if (a[i] > mx) suf.insert(i), mx = a[i]; 
	root = *suf.begin();
	char ch; int x, y;
	
	//debug();
	rep(i, 1, q){
		char ch; int x;
		scanf("%c", &ch);
		while (ch != 'U' && ch != 'L' && ch != 'R') scanf("%c", &ch);
		scanf("%d", &x);
		if (ch == 'U'){
			scanf("%d", &y);
			a[x] = y;
			
			pre.insert(x);
			it2 = it = pre.lower_bound(x);
			if (it != pre.begin() && a[*(--it)] > a[x]) pre.erase(x);
			else {
				it = it2; it++;
				while (it != pre.end() && a[*it] < a[x]) {
					int op = *it;
					it++;
					pre.erase(op);
				}
			}
			
			suf.insert(x);
			it2 = it = suf.lower_bound(x);
			it++;
			if (it != suf.end() && a[*it] > a[x]) suf.erase(x);
			else if (it2 != suf.begin()) {
				it = it2; it--;
				while (it != suf.begin() && a[*it] < a[x]) {
					int op = *it;
					it--;
					suf.erase(op);
				}
				int op = *suf.begin();
				if (a[op] < a[x]) suf.erase(op);
			}
			
			root = *suf.begin();
		}
		else if (ch == 'L'){
			if (x == root) printf("%d\n", root);
			else if (x < root) printf("%d\n", *pre.lower_bound(x));
			else printf("%d\n", *(--suf.lower_bound(x)));
		}
		else {
			if (x == root) printf("%d\n", root);
			else if (x < root) printf("%d\n", *pre.upper_bound(x));
			else printf("%d\n", *(--suf.upper_bound(x)));
		}
		//debug();
	}
	return 0;
}
