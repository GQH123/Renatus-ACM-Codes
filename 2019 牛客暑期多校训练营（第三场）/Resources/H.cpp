#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
const int DIFF = 1e8 + 5;
int n;
struct Pt {
    int x, y;
    void scan() {
        scanf("%d%d", &x, &y);
    }
    inline bool operator < (const Pt& r) const {
        return (y == r.y) ? (x < r.x) : y < r.y;
    }
} p[MAXN];
int main() {
    int T; cin >> T;
    while(T --) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i)
            p[i].scan();
        sort(p + 1, p + n + 1);
        int mid = n / 2;
        int x1 = p[mid].x - DIFF, y1 = p[mid].y + 1;
        int x2 = p[mid].x + DIFF + 1, y2 = p[mid].y - 1;
        printf("%d %d %d %d\n", x1, y1, x2, y2);
    }
    return 0;
}
