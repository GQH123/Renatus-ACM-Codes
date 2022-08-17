#include <bits/stdc++.h>

#define pii pair<int, int>
#define fi first
#define se second
#define maxn 2021
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define srep(i, l, r) for (int i = l; i < r; i++)
 
using namespace std;
 
const int limit = 50;
struct node {
    int v , f , id;
    double c;
    node *next , *rev;
} pool[3200000] , *g[12000] , *from[12000];
int top;
int n;
int b[120000];
int s , t;
double dis[120000];
int f[120000];
int out[120000];
void clear () {
    int i;
    for ( i = 1 ; i <= top ; i++ ) {
        pool[i] = pool[0];
    }
    for ( i = 1 ; i <= 1 + n + n + 1 ; i++ ) {
        g[i] = NULL;
    }
    top = 0;
}
void add ( int u , int v , int f , double c , int id ) {
    node *tmp1 = &pool[++top] , *tmp2=  &pool[++top];
    tmp1 -> v = v; tmp1 -> f = f; tmp1 -> c = c; tmp1 -> id = id; tmp1 -> next = g[u]; g[u] = tmp1; tmp1 -> rev = tmp2;
    tmp2 -> v = u; tmp2 -> f = 0; tmp2 -> c = -c; tmp2 -> id = id; tmp2 -> next = g[v]; g[v] = tmp2; tmp2 -> rev = tmp1;
}
bool spfa () {
    int i , k;
    queue < int > q;
    for ( i = 1 ; i <= t ; i++ ) {
        dis[i] = 9000000;
        f[i] = 0;
    }
    dis[s] = 0; f[s] = 1; q.push ( s );
    while ( q.size () ) {
        k = q.front (); q.pop ();
        f[k] = 0;
        for ( node *j = g[k] ; j ; j = j -> next ) {
            if ( j -> f && dis[j->v] > dis[k] + j -> c + 1e-9 ) {
                dis[j->v] = dis[k] + j -> c;
                from[j->v] = j;
                if ( f[j->v] == 0 ) q.push ( j -> v );
                f[j->v] = 1;
            }
        }
    }
    if ( dis[t] > 9000000 - 5 ) return false;
    return true;
}
void find () {
    int i , f = 9999999;
    for ( i = t ; i != s ; i = from[i] -> rev -> v ) f = min ( f , from[i] -> f );
    for ( i = t ; i != s ; i = from[i] -> rev -> v ) from[i] -> f -= f, from[i] -> rev -> f += f;
}
void dinic () {
    while ( spfa () == true ) find ();
}

pii lis[maxn << 1]; int cs = 0;
pii sta[maxn << 1]; int head = 0;
int res[maxn];
void work () { 
    int i , j;
    //n = 50;
    scanf ( "%d" , &n );
    for ( i = 1 ; i <= n ; i++ ) {
        //b[i] = rand () % n;
        scanf ( "%d" , &b[i] );
    }
    sort ( b + 1 , b + 1 + n );
    if ( n >= limit ) {
    	/*
        for ( i = 1 ; i <= n ; i++ ) {
            printf ( "%d%c" , b[i] , i==n?'\n':' ' );
        }
        return ;
        */
        head = cs = 0;
        rep(i, 1, n) lis[++cs] = pii(i - 1, 1);
        rep(i, 1, n) lis[++cs] = pii(b[i], 0);
        sort(lis + 1, lis + 1 + cs);
        rep(i, 1, cs) lis[i].se ^= 1;
        
        rep(i, 1, cs) {
        	if (!head) {
        		sta[++head] = lis[i];
        	}
        	else {
        		if (sta[head].se == lis[i].se) sta[++head] = lis[i];
        		else {
        			if (!sta[head].se) {
        				res[sta[head].fi] = lis[i].fi;
        			}
        			else {
        				res[lis[i].fi] = sta[head].fi;
        			}
        			head--;
        		}
        	}
        }
        assert(!head);
        
        srep(i, 0, n) printf("%d ", res[i]); printf("\n");
        
        return;
    }
    s = 1; t = 1 + n + n + 1;
    for ( i = 1 ; i <= n ; i++ ) {
        add ( s , 1 + i , 1 , 0 , 0 );
        add ( 1 + n + i , t , 1 , 0 , 0 );
    }
    for ( i = 1 ; i <= n ; i++ ) {
        for ( j = 1 ; j <= n ; j++ ) {
            add ( 1 + i , 1 + n + j , 1 , sqrt(abs(b[i]-(j-1))) , j );
        }
    }
    dinic ();
    //fprintf ( stderr, "##\n" );
    for ( i = 1 ; i <= n ; i++ ) {
        for ( node *l = g[1+i] ; l ; l = l -> next ) {
            if ( l -> id && l -> f == 0 ) {
                out[l->id] = b[i];
            }
        }
    }
    for ( i = 1 ; i <= n ; i++ ) {
        printf ( "%d%c" , out[i] , i==n?'\n':' ' );
    }
}
int main () {
    int t;
    //freopen ( "k.out" , "w" , stdout );
    //t = 400;
    scanf ( "%d" , &t );
    while ( t-- ) {
        work ();
        clear ();
    }
    return 0;
}
