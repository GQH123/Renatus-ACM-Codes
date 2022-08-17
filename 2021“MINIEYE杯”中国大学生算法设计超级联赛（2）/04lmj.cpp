#pragma GCC optimize(3)

#include <stdio.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>

using namespace __gnu_pbds;
using namespace std;

struct so {
    int l , a , b , i;
} tmp;
struct node {
    int lev;
    tree < int , null_type , less<int> , rb_tree_tag , tree_order_statistics_node_update> s;
    node *ch[2];
} pool[1700000] , *t;
int top;
int n , q;
int a[120000];
int last[120000];
vector < so > v[120000];
int ans[120000];
void insert ( node *id , int x , int i , int ls ) {
    id -> s.insert ( i );
    if ( ls != 0 ) id -> s.erase ( ls );
    if ( id -> lev == -1 ) return ;
    int s = ( (x&(1<< id->lev))!=0 ? 1 : 0 );
    if ( !id -> ch[s] ) {
        id -> ch[s] = &pool[++top];
        id -> ch[s] -> lev = id -> lev - 1;
    }
    insert ( id -> ch[s] , x , i , ls );
}
void query ( node *id , int i , int l , int a , int b ) {
    if ( !id ) return ;
    //printf ( "## %d lev%d l%d %d %d ans%d\n" , i , id -> lev , l , a ,b ,ans[i] );
    if ( id -> lev == -1 ) {
        ans[i] += id -> s.size () - id -> s.order_of_key ( l );
        return;
    }
    if ( (a&(1<< id->lev)) == 0 && (b&(1<< id->lev)) == 0 ) {
        query ( id -> ch[0] , i , l , a , b );
    }
    if ( (a&(1<< id->lev)) != 0 && (b&(1<< id->lev)) == 0 ) {
        query ( id -> ch[1] , i , l , a , b );
    }
    if ( (a&(1<< id->lev)) == 0 && (b&(1<< id->lev)) != 0 ) {
        query ( id -> ch[1] , i , l , a , b );
        if ( id -> ch[0] ) ans[i] += id -> ch[0] -> s.size () - id -> ch[0] -> s.order_of_key ( l );
    }
    if ( (a&(1<< id->lev)) != 0 && (b&(1<< id->lev)) != 0 ) {
        query ( id -> ch[0] , i , l , a , b );
        if ( id -> ch[1] ) ans[i] += id -> ch[1] -> s.size () - id -> ch[1] -> s.order_of_key ( l );
    }
}
void work () {
    int i , r;
    scanf ( "%d" , &n );
    for ( i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] );
    }
    scanf ( "%d" , &q );
    for ( i = 1 ; i <= q ; i++ ){
        scanf ( "%d%d%d%d" , &tmp.l , &r , &tmp.a , &tmp.b );
        tmp.i = i;
        v[r].push_back ( tmp );
    }
    t = &pool[++top];
    t -> lev = 16;
    for ( i = 1 ; i <= n ; i++ ) {
        insert ( t , a[i] , i , last[a[i]] );
        last[a[i]] = i;
        for ( auto j : v[i] ) {
            query ( t , j.i , j.l , j.a , j.b );
        }
    }
    for ( i = 1 ; i <= q ; i++ ) {
        printf ( "%d\n" , ans[i] );
    }
}
int main () {
    work ();
    return 0;
}
