#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;
const int MAXN = 1e6 + 5;
const int DIFF = 1e8 + 5;
int n, m, cnt;
int pos[MAXN], ord, bk[MAXN];
unordered_map<string, int> mp;
set<PII> st;
inline void GET(int &n) {
    char c; bool f = 0; n = 0;
    do { c = getchar(); if(c == '-') f = 1; } while('0' > c || c > '9');
    while('0' <= c && c <= '9') { n = n * 10 + c - '0'; c = getchar(); }
    if(f) n = -n;
}
char str[MAXN][20];
int main() {
    //freopen("input", "r", stdin);
    //freopen("output2", "w", stdout);
    int T; GET(T);
    while(T --) {
        GET(n); GET(m);
 
        mp.clear();
        st.clear();
        cnt = 0;
        ord = 0;
 
        int v, p, num = 0, op;
        for(int i = 1; i <= n; ++ i) {
            GET(op);
            scanf("%s", str[i]);
            GET(v);
            if(op == 0) {
                if(!mp[str[i]]) {
                    mp[str[i]] = ++ cnt;
                    p = cnt;
                } else
                    p = mp[str[i]];
                if(pos[p]) {
                    auto it = st.lower_bound(PII(pos[p], -100));
                    v = it -> second;
                    if(it != st.end() || it -> first == pos[p])
                        st.erase(it);
                    bk[pos[p]] = 0;
                    pos[p] = ++ ord;
                    bk[ord] = p;
                    st.insert(PII(pos[p], v));
                } else {
                    pos[p] = ++ ord;
                    bk[ord] = p;
                    st.insert(PII(pos[p], v));
                    ++ num;
                    if(num > m) {
                        auto it = st.begin();
                        pos[bk[it -> first]] = 0;
                        bk[it -> first] = 0;
                        st.erase(it);
                    }
                }
                printf("%d\n", v);
            } else {
                p = mp[str[i]];
                if(!p) {
                    puts("Invalid");
                    continue;
                }
                auto it = st.lower_bound(PII(pos[p], -100));
                if(it == st.end() || it -> first != pos[p]) {
                    puts("Invalid");
                    continue;
                }
                if(v == 0) {
                    printf("%d\n", it -> second);
                } else if(v == 1) {
                    ++ it;
                    if(it == st.end()) {
                        puts("Invalid");
                        continue;
                    } else
                        printf("%d\n", it -> second);
                } else {
                    if(it == st.begin()) {
                        puts("Invalid");
                        continue;
                    } else {
                        -- it;
                        printf("%d\n", it -> second);
                    }
                }
            }
        }
 
        for(int i = 1; i <= cnt; ++ i) {
            bk[pos[i]] = 0;
            pos[i] = 0;
        }
    }
    return 0;
}
