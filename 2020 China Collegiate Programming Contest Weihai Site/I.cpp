#pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <bits/extc++.h>
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
#define maxb
//#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;
using namespace __gnu_pbds;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x, char sep = '\n'){    
    if (!x) {putchar('0'), putchar(sep); return;}
    if (x < 0) putchar('-'), x = -x;
    int c = 0;
    while (x) _num[++c] = x % 10, x /= 10;
    while (c) putchar('0' + _num[c--]); 
    putchar(sep);
}


/*

      |---------|
      |   0     |
      | 1 2 3 4 |
      |   5     |
      |---------|
      
          |-----|
          |00 01|
          |02 03|
    |-----|-----|-----|-----|
    |04 05|08 09|12 13|16 17|
    |06 07|10 11|14 15|18 19|
    |-----|-----|-----|-----|
          |20 21|
          |22 23|
          |-----|
*/
  
/*

  BOY = 00, 01, 02
  BRY = 03, 04, 05
  BOW = 06, 07, 08
  BRW = 09, 10, 11
  GOY = 12, 13, 14
  GRY = 15, 16, 17
  GOW = 18, 19, 20
  GRW = 21, 22, 23
  
          |-----|
          |17 16|
          |19 18|
          |-----|
          
     
     4--------5
    /|       /|
   / |      / |
  0--+-----1  |
  |  6-----+--7
  | /      | /      
  |/       |/  
  2--------3
  
  BOY = 00, 01, 02
  BRY = 03, 04, 05
  BOW = 06, 07, 08
  BRW = 09, 10, 11
  GOY = 12, 13, 14
  GRY = 15, 16, 17
  GOW = 18, 19, 20
  GRW = 21, 22, 23
  
*/

const int cor[][3] = {{2, 5, 8}, 
                     {3, 9, 12}, 
                     {7, 10, 20},
                     {11, 14, 21}, 
                     {0, 4, 17},
                     {1, 13, 16},
                     {6, 19, 22},
                     {15, 18, 23}
                    };
const char color[] = "BGORWY";  
const char cor_c[][4] = {"BOY", "BRY", "BOW", "BRW", "GOY", "GRY", "GOW", "GRW"};
const int  cor_id[][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 10, 11}, {12, 13, 14}, {15, 16, 17}, {18, 19, 20}, {21, 22, 23}};
const int read_pos[] = {0, 1, 2, 3, 4, 5, 8, 9, 12, 13, 16, 17, 6, 7, 10, 11, 14, 15, 18, 19, 20, 21, 22, 23};
const int solved[] = {14, 17, 2, 5, 
                      13, 1, 19, 7, 
                      0, 3, 6, 9, 
                      4, 16, 10, 22,
                      15, 12, 21, 18,
                      8, 11, 20, 23};
 
const int  r_le[] =   {2, 0, 3, 1, 
                       8, 9, 10, 11, 
                       12, 13, 14, 15,
                       16, 17, 18, 19,
                       4, 5, 6, 7,
                       21, 23, 20, 22
                      };  
const int  r_up[] =   {8, 9, 10, 11, 
                       5, 7, 4, 6, 
                       20, 21, 22, 23, 
                       14, 12, 15, 13, 
                       3, 2, 1, 0, 
                       19, 18, 17, 16
                      };
const int  r_cl[] =   {6, 4, 7, 5,
                       22, 20, 23, 21,
                       10, 8, 11, 9,
                       2, 0, 3, 1,
                       17, 19, 16, 18,
                       14, 12, 15, 13
                      };
/*
const int  r_cl[] =   {6, 4, 7, 5,
                       22, 20, 23, 21,
                       10, 8, 11, 9,
                       2, 0, 3, 1,
                       17, 19, 16, 18,
                       14, 12, 13, 15
                      };
*/ 
const int  tr_fr[] =  {0, 18, 2, 16,
                       4, 5, 6, 7,
                       8, 1, 10, 3,
                       13, 15, 12, 14,
                       23, 17, 21, 19,
                       20, 9, 22, 11
                      };
const int  tl_le[] =  {0, 1, 2, 3,
                       4, 5, 10, 11,
                       8, 9, 14, 15,
                       12, 13, 18, 19,
                       16, 17, 6, 7,
                       21, 23, 20, 22
                      };
const int  tb_cl[] =  {6, 4, 2, 3,
                       22, 5, 23, 7,
                       8, 9, 10, 11,
                       12, 0, 14, 1,
                       17, 19, 16, 18, 
                       20, 21, 15, 13
                      }; 
const int M[] = {1000000007, 19260817};
struct cube{
    #define pci pair<char, int>
    int num[24];
    cube(){ memset(num, 0, sizeof(num)); }
    cube(int* per){ rep(i, 0, 23) num[i] = per[i]; }
    cube(const int* per){ rep(i, 0, 23) num[i] = per[i]; }
    void operator = (const cube b) {
    	rep(i, 0, 23) num[i] = b.num[i];
    }
    bool operator == (const cube b) const{
    	rep(i, 0, 23) if (num[i] != b.num[i]) return false;
    	return true;
    }
    bool operator < (const cube b) const {
    	rep(i, 0, 23) if (num[i] != b.num[i]) return num[i] < b.num[i];
    	return false;
    }
    void bingo(){ rep(i, 0, 23) num[i] = solved[i]; }
    void init(char* pat){ 
    	memset(num, 0, sizeof(num));
        pci sta[3];
        rep(i, 0, 7) {
            rep(j, 0, 2) sta[j] = pci(pat[cor[i][j]], cor[i][j]);
            sort(sta, sta + 3); 
            rep(j, 0, 7) {
                bool f = 1;
                rep(k, 0, 2) if (sta[k].fi != cor_c[j][k]) {f = 0; break;}
                if (f) {
                    rep(k, 0, 2) num[sta[k].se] = cor_id[j][k];
                    break;
                }
            }
        }
    }
    void apply_per(const int* per){
        int _num[24];
        rep(i, 0, 23) _num[i] = num[per[i]];
        rep(i, 0, 23) num[i] = _num[i];
    }
    void apply_revper(const int* per){
        int _per[24];
        rep(i, 0, 23) _per[per[i]] = i;
        apply_per(_per);
    }
    void rotate_up()    { apply_per(r_up); }
    void rotate_left()  { apply_per(r_le); } 
    void rotate_clock() { apply_per(r_cl); }
    void rotate_init(){
        int id = -1; rep(i, 0, 23) if (!num[i]) {id = i; break;} 
        while (!(1 <= (id >> 2) && (id >> 2) <= 4)) {
            rotate_up();
            id = -1; rep(i, 0, 23) if (!num[i]) {id = i; break;} 
        }
        while ((id >> 2) != 2) {
            rotate_left();
            id = -1; rep(i, 0, 23) if (!num[i]) {id = i; break;} 
        }
        while (id != 8) {
            rotate_clock();
            id = -1; rep(i, 0, 23) if (!num[i]) {id = i; break;} 
        }
    }
    void twist_r_fr() { apply_per(tr_fr); 	 }
    void twist_r_bk() { apply_revper(tr_fr); }
    void twist_l_le() { apply_per(tl_le); 	 }
    void twist_l_ri() { apply_revper(tl_le); } 
    void twist_b_cl() { apply_per(tb_cl); 	 }
    void twist_b_rc() { apply_revper(tb_cl); } 
    void debug(){ 
    	rep(i, 0, 23) cout << num[i] << ' '; cout << endl << endl; 
    	rep(x, 0, 23) {
    		int i = read_pos[x];
    		if (i == 0 || i == 2 || i == 20 || i == 22) rep(k, 0, 1) cout << ' ';
    		cout << cor_c[num[i] / 3][num[i] % 3];
    		if (i == 1 || i == 3 || i == 17 || i == 19 || i == 21 || i == 23) cout << endl;
    	}
    } 
    #define type ll
    type hash(){ 
    	type res;
    	int has = 0; rep(i, 0, 23) has = (1ll * has * 2333 + num[i]) % M[0]; res = has;
    	has = 0; rep(i, 0, 23) has = (1ll * has * 2333 + num[i]) % M[1]; res = res * M[1] + has;
    	return res; 
    }
};

#define maxs 4000020

#define Hash
#ifdef Hash
cube bfs[maxs]; int head = 0, tail = 0;
cc_hash_table<type, int> d;
void BFS(){
	head = tail = 0;
	cube S, x, _x; S.bingo();
	bfs[++head] = S; //S.debug();
	
	d[S.hash()] = 1;
	while (head != tail){
		x = bfs[++tail]; _x = x; type has = x.hash(); int dd = d[has];
		//x.debug(); cout << dd << endl << endl;
		x.twist_r_fr(); has = x.hash(); if (!d[has]) d[has] = dd + 1, bfs[++head] = x; x = _x; 
		x.twist_r_bk(); has = x.hash(); if (!d[has]) d[has] = dd + 1, bfs[++head] = x; x = _x; 
		x.twist_l_le(); has = x.hash(); if (!d[has]) d[has] = dd + 1, bfs[++head] = x; x = _x;
		x.twist_l_ri(); has = x.hash(); if (!d[has]) d[has] = dd + 1, bfs[++head] = x; x = _x; 
		x.twist_b_cl(); has = x.hash(); if (!d[has]) d[has] = dd + 1, bfs[++head] = x; x = _x; 
		x.twist_b_rc(); has = x.hash(); if (!d[has]) d[has] = dd + 1, bfs[++head] = x; x = _x;
	} 
	//cerr << head << ' ' << tail << endl;
}
#endif

#ifdef Cube
cube bfs[maxs]; int head = 0, tail = 0;
cc_hash_table<cube, int> d;
void BFS(){
	head = tail = 0;
	cube S, x, _x; S.bingo();
	bfs[++head] = S; //S.debug(); 
	d[S] = 1;
	while (head != tail){
		x = bfs[++tail]; _x = x; int has = x.hash(), dd = d[has];
		assert(dd);
		//x.debug(); cout << dd << endl << endl;
		x.twist_r_fr(); if (!d[x]) d[x] = dd + 1, bfs[++head] = x; x = _x; 
		x.twist_r_bk(); if (!d[x]) d[x] = dd + 1, bfs[++head] = x; x = _x; 
		x.twist_l_le(); if (!d[x]) d[x] = dd + 1, bfs[++head] = x; x = _x;
		x.twist_l_ri(); if (!d[x]) d[x] = dd + 1, bfs[++head] = x; x = _x; 
		x.twist_b_cl(); if (!d[x]) d[x] = dd + 1, bfs[++head] = x; x = _x; 
		x.twist_b_rc(); if (!d[x]) d[x] = dd + 1, bfs[++head] = x; x = _x;
	} 
	//cerr << head << ' ' << tail << endl;
}
#endif

void test(cube x){
	cube _x = x;
	x.rotate_up(); x.debug(); x = _x; 
	x.rotate_left(); x.debug(); x = _x; 
	x.rotate_clock(); x.debug(); x = _x; 
	x.twist_r_fr(); x.debug(); x = _x; 
	x.twist_r_bk(); x.debug(); x = _x; 
	x.twist_l_le(); x.debug(); x = _x;  
	x.twist_l_ri(); x.debug(); x = _x; 
	x.twist_b_cl(); x.debug(); x = _x; 
	x.twist_b_rc(); x.debug(); x = _x;
}
void getper(int* a, int* b, int* per){ // get per for apply(per, a) = b
	int _a[24];
	rep(i, 0, 23) _a[a[i]] = i;
	rep(i, 0, 23) per[i] = _a[b[i]];
}
void getper(int* a, const int* b, int* per){ // get per for apply(per, a) = b
	int _a[24];
	rep(i, 0, 23) _a[a[i]] = i;
	rep(i, 0, 23) per[i] = _a[b[i]];
}
void appper(int* a, int* per){
	int _a[24];
	rep(i, 0, 23) _a[i] = a[per[i]];
	rep(i, 0, 23) a[i] = _a[i];
} 
void revper(int* per, int* _per){
	rep(i, 0, 23) _per[per[i]] = i;
}

char s[24], t[24];
cube a, b;
int pa[24], pb[24], _pa[24], _pb[24], now[24];
int main(){
	int T; scanf("%d", &T);
	BFS();
	while (T--){
		int cntt = 0, cnts = 0, line = 6;
		char ch; scanf("%c", &ch);
		while (line--){
			while (!isupper(ch)) scanf("%c", &ch);
			while (isupper(ch)) s[read_pos[cnts++]] = ch, scanf("%c", &ch); 
			while (!isupper(ch)) scanf("%c", &ch); 
			while (isupper(ch)) t[read_pos[cntt++]] = ch, scanf("%c", &ch); 
		}
		a.init(s), b.init(t); 
		a.rotate_init(), b.rotate_init();
		/*
		a.debug(), b.debug();
		printf("%d\n", d[a.hash()] - 1);
		printf("%d\n", d[b.hash()] - 1);
		return 0;
		*/
		//a.debug(), b.debug();
		//test(b);
		/*
		appper(a.num, pa);
		rep(i, 0, 23) assert(a.num[i] == solved[i]); 
		return 0;
		*/
		/*
		cube x = a, y = a;
		x.twist_l_le(), x.twist_r_fr(), x.debug();
		y.twist_r_fr(), y.twist_l_le(); y.debug();
		return 0;
		*/
		getper(a.num, solved, pa); 
		getper(b.num, solved, pb);
		revper(pb, _pb);
		rep(i, 0, 23) now[i] = solved[i];
		appper(now, pa), appper(now, _pb);
		
		
		cube op = cube(now); op.rotate_init(); //op.debug();
		//op = cube(solved), op.debug();
		printf("%d\n", d[op.hash()] - 1);
	}
    return 0;
}

