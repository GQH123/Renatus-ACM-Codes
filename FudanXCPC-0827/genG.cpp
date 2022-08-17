#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
using namespace std;

int main(){
    int T = 20;
    while (T--){
        int n = 1000;
        printf("%d\n", n);
        rep(i, 1, n) {rep(j, 1, n) printf("a"); printf("\n");} 
    } printf("0");
    return 0;
}
