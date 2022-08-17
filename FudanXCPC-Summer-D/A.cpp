#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
struct Point {
    int x, y, id;
} p[505];

int nx[505], ny[505];
int ctr_x[505], ctr_y[505];

struct Edge {
    int v, f, c, nxt;
} e[10004];

bool cmp_x(const Point &L, const Point &R) {
    return L.x < R.x;
}
bool cmp_y(const Point &L, const Point &R) {
    return L.y < R.y;
}

int head[5005], ec = 2;
void ade(int u, int v, int f, int c) {
    //cerr << u << ' ' << v << ' ' << f << ' ' << c << endl;
    e[ec] = (Edge) {v, f, c, head[u]}, head[u] = ec++;
    e[ec] = (Edge) {u, 0, -c, head[v]}, head[v] = ec++;
}

int dist[10004];
int inq[10004];
int fr[10004];
int q[10004];
int hea = 0, tail = 0;
int SPFA() {
	hea = tail = 0;
    for(int i = 1; i <= 3*N+2; i++) dist[i] = -12345678;
    dist[N*3+1] = 0;
    q[++hea] = N * 3 + 1; //q.push(N*3+1);
    while(hea > tail) {
    	int x = q[++tail]; //inq[x] = false;
        //int x = q.front(); q.pop(); inq[x] = false;
        for(int i = head[x]; ~i; i = e[i].nxt) {
            if(!e[i].f) continue;
            int v = e[i].v;
            if(dist[v] < dist[x] + e[i].c) {
                dist[v] = dist[x] + e[i].c;
                fr[v] = i;
                if(!inq[v]) q[++hea] = v, inq[v] = true;//q.push(v), inq[v] = true;
            }
        }
        inq[x] = false;
    }
    return dist[3*N+2];
}

void Aug() {
    int flow = INT_MAX;
    for(int x = 3*N + 2; x != 3*N + 1; x = e[fr[x]^1].v) 
        flow = min(flow, e[fr[x]].f);
    for(int x = 3*N + 2; x != 3*N + 1; x = e[fr[x]^1].v) {
        e[fr[x]].f -= flow;
        e[fr[x]^1].f += flow;
        ans += e[fr[x]].c * flow;
    }
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d%d", &p[i].x, &p[i].y), p[i].id = i;
    for(int i = 1; i <= N; i++)
        nx[i] = p[i].x, ny[i] = p[i].y;
    sort(nx + 1, nx + N + 1);
    sort(ny + 1, ny + N + 1);

    int siz_x = unique(nx + 1, nx + N + 1) - nx - 1;
    int siz_y = unique(ny + 1, ny + N + 1) - ny - 1;

    for(int i = 1; i <= N; i++) {
        p[i].x = lower_bound(nx + 1, nx + siz_x + 1, p[i].x) - nx;
        p[i].y = lower_bound(ny + 1, ny + siz_y + 1, p[i].y) - ny;
    }

    scanf("%d", &M);
    for(int i = 1; i <= N; i++) 
        ctr_x[i] = 505, ctr_y[i] = 505;
    for(int i = 1; i <= M; i++) {
        char str[5]; int t, k;
        scanf("%s", str);
        scanf("%d%d", &t, &k);
        if(str[0] == 'R') {
            t = lower_bound(nx + 1, nx + siz_x + 1, t) - nx;
            ctr_x[t] = min(ctr_x[t], k);
        } else {
            t = lower_bound(ny + 1, ny + siz_y + 1, t) - ny;
            ctr_y[t] = min(ctr_y[t], k);
        }
    }

    sort(p + 1, p + N + 1, cmp_x);
    int ptr = N;
    for(int i = N; i >= 1; i--) {
        while(p[ptr].x == i) ade(N + i, p[ptr].id, 1, p[ptr].id), ptr--;
        if(i > 1) ade(N+i-1, N+i, ctr_x[i], 0);
        else ade(N*3+1, N+1, ctr_x[1], 0);
    }

    sort(p + 1, p + N + 1, cmp_y);
    ptr = N;
    for(int i = N; i >= 1; i--) {
        while(p[ptr].y == i) ade(p[ptr].id, N*2 + i, 1, 0), ptr--;
        if(i > 1) ade(N*2+i, N*2+i-1, ctr_y[i], 0);
        else ade(N*2+1, N*3+2, ctr_y[1], 0);
    }

    while(SPFA()) 
        Aug();

    printf("%d", ans);
}
        
            

