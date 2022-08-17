#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 20020
#define maxnode (maxn << 2)
#define maxcs (maxnode << 2)
//#define DEBUG
using namespace std;  

namespace S1{ 
	int nodet = 0, numt = 0, nxtt = 0;
	int root;
	int nxt[maxnode], ptr[maxnode];
	int ch[maxnode][2], v[maxnode]; 
	void init(){
		root = ++nxtt;
		ptr[nxtt] = ++nodet;
		v[nodet] = ++numt;
	}
	void add_nxt(int x){
		nxt[x] = ++nxtt;
		ptr[nxtt] = ++nodet;
		v[nodet] = ++numt;
	}
	bool mod(char chr){
		if (chr == 'C'){
			int x = root;
			root = ++nxtt;
			ptr[root] = ptr[x];
			nxt[root] = x;
		}// +1
		else if (chr == 'D'){ 
			if (!nxt[root]) add_nxt(root);
			root = nxt[root];
		}// +1
		else if (chr == 'L'){ 
			int pr = ptr[root];
			if (!ch[pr][0]) return false;
			ptr[root] = ch[pr][0];
		}// +0
		else if (chr == 'P'){	
			if (!nxt[root]) add_nxt(root);
			if (!nxt[nxt[root]]) add_nxt(nxt[root]);
			int pl = ptr[root], pr = ptr[nxt[root]];
			root = nxt[root];
			ptr[root] = ++nodet;
			ch[nodet][0] = pl;
			ch[nodet][1] = pr; 
		}// +3
		else if (chr == 'R'){
			int pr = ptr[root];
			if (!ch[pr][1]) return false;
			ptr[root] = ch[pr][1];
		}// +0
		else if (chr == 'S'){
			if (!nxt[root]) add_nxt(root);
			swap(ptr[root], ptr[nxt[root]]);
		}// +2
		else if (chr == 'U'){
			int x = root, pr = ptr[root];
			if (!ch[pr][0] || !ch[pr][1]) return false;
			int l = ch[pr][0], r = ch[pr][1]; 
			root = ++nxtt;
			nxt[root] = x;
			ptr[root] = l;
			ptr[x] = r; 
		}// +0
		return true;
	}
	int lis[maxcs], cs = 0; //maxcs = 3 * maxnode
	bool vis[maxnode]; //maxnode = 3 * maxn
	void get_ett(int x){
		lis[++cs] = v[x];
		if (vis[x]) return;
		vis[x] = 1;
		if (ch[x][0]) get_ett(ch[x][0]), lis[++cs] = v[x];
		if (ch[x][1]) get_ett(ch[x][1]), lis[++cs] = v[x];
	}
	void get_lis(int num){
		int x = root;
		while (numt <= num){
			get_ett(ptr[x]);
			if (!nxt[x]) add_nxt(x);
			x = nxt[x];
		}
	}
	char s[maxn];
	bool work(){
		init();
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		rep(i, 1, n) {
			if (!mod(s[i])) return false;
		}
		return true;
	} 
}

namespace S2{ 
	int nodet = 0, numt = 0, nxtt = 0;
	int root;
	int nxt[maxnode], ptr[maxnode];
	int ch[maxnode][2], v[maxnode]; 
	void init(){
		root = ++nxtt;
		ptr[nxtt] = ++nodet;
		v[nodet] = ++numt;
	}
	void add_nxt(int x){
		nxt[x] = ++nxtt;
		ptr[nxtt] = ++nodet;
		v[nodet] = ++numt;
	}
	bool mod(char chr){
		if (chr == 'C'){
			int x = root;
			root = ++nxtt;
			ptr[root] = ptr[x];
			nxt[root] = x;
		}// +1
		else if (chr == 'D'){ 
			if (!nxt[root]) add_nxt(root);
			root = nxt[root];
		}// +1
		else if (chr == 'L'){ 
			int pr = ptr[root];
			if (!ch[pr][0]) return false;
			ptr[root] = ch[pr][0];
		}// +0
		else if (chr == 'P'){	
			if (!nxt[root]) add_nxt(root);
			if (!nxt[nxt[root]]) add_nxt(nxt[root]);
			int pl = ptr[root], pr = ptr[nxt[root]];
			root = nxt[root];
			ptr[root] = ++nodet;
			ch[nodet][0] = pl;
			ch[nodet][1] = pr; 
		}// +3
		else if (chr == 'R'){
			int pr = ptr[root];
			if (!ch[pr][1]) return false;
			ptr[root] = ch[pr][1];
		}// +0
		else if (chr == 'S'){
			if (!nxt[root]) add_nxt(root);
			swap(ptr[root], ptr[nxt[root]]);
		}// +2
		else if (chr == 'U'){
			int x = root, pr = ptr[root];
			if (!ch[pr][0] || !ch[pr][1]) return false;
			int l = ch[pr][0], r = ch[pr][1]; 
			root = ++nxtt;
			nxt[root] = x;
			ptr[root] = l;
			ptr[x] = r; 
		}// +0
		return true;
	}
	int lis[maxcs], cs = 0; //maxcs = 3 * maxnode
	bool vis[maxnode]; //maxnode = 3 * maxn
	void get_ett(int x){
		lis[++cs] = v[x];
		if (vis[x]) return;
		vis[x] = 1;
		if (ch[x][0]) get_ett(ch[x][0]), lis[++cs] = v[x];
		if (ch[x][1]) get_ett(ch[x][1]), lis[++cs] = v[x];
	}
	void get_lis(int num){
		int x = root;
		while (numt <= num){
			get_ett(ptr[x]);
			if (!nxt[x]) add_nxt(x);
			x = nxt[x];
		}
	}
	char s[maxn];
	bool work(){
		init();
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		rep(i, 1, n) {
			if (!mod(s[i])) return false;
		}
		return true;
	} 
}

int main(){
	bool f1 = S1 :: work();
	bool f2 = S2 :: work();
	if (f1 ^ f2) {printf("False"); return 0;} 
	else if (!f1) {printf("True"); return 0;}
	else {
		int mxnum = max(S1 :: numt, S2 :: numt);
		S1 :: get_lis(mxnum);
		S2 :: get_lis(mxnum);
		
		#ifdef DEBUG 
			cerr << endl;
		
			cerr << S1 :: cs << ':';
			rep(i, 1, S1 :: cs) cerr << S1 :: lis[i] << ' ';
			cerr << endl;
			
			cerr << S2 :: cs << ':';
			rep(i, 1, S2 :: cs) cerr << S2 :: lis[i] << ' ';
			cerr << endl;
			
			cerr << endl; 
		#endif 
		
		int cs1 = S1 :: cs, cs2 = S2 :: cs;
		if (cs1 != cs2) {printf("False"); return 0;}
		
		rep(i, 1, cs1) if (S1 :: lis[i] != S2 :: lis[i]) {printf("False"); return 0;} 
		printf("True");
		return 0;
	}
	return 0;
}
