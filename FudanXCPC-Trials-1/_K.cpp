#include <bits/stdc++.h>
#define srep(i, l, r) for (register int i = l; i < r; i++)
using namespace std;
typedef double DB;
 
const DB eps = 1e-13;
const int MX = 105;
 
int n, m;
struct Vect { 
    DB x, y; 
    Vect operator * (DB a) const { return (Vect) {x*a, y*a}; }
    Vect operator + (const Vect &rhs) const { return (Vect){x + rhs.x, y + rhs.y}; }
    Vect operator - (const Vect &rhs) const { return (Vect){x - rhs.x, y - rhs.y}; }
    DB operator * (const Vect &rhs) const { return x * rhs.y - y * rhs.x; }
    DB operator ^ (const Vect &rhs) const { return x * rhs.x + y * rhs.y; }
} A[MX], B[MX], p[MX * MX];
 
int lc;
struct Line {
    Vect p, v; DB a;
    bool operator == (const Line &rhs) const { return fabs(a - rhs.a) < eps; }
    bool operator < (const Line &rhs) const { 
        if((*this) == rhs) return (p-rhs.p) * rhs.v < 0;
        return a < rhs.a;
    }
} line[MX * MX], q[MX * MX];
 
Vect inc(const Line &a, const Line &b) { return b.p + b.v * ((b.p - a.p) * a.v / (a.v * b.v)); }
bool is_left(const Vect &a, const Line &l) { return (a-l.p) * l.v < 0; }
/*
bool half_plane() {
    sort(line + 1, line + lc + 1);
    int h = 0, t = 0; q[t++] = line[1];
    for(int i = 2; i <= lc; i++) {
            while(t-h >= 2 && !is_left(p[t-1], line[i])) t--;
            while(t-h >= 2 && !is_left(p[h+1], line[i])) h++;
            if(q[t-1] == line[i]) { assert(!is_left(line[i].p, q[t-1])); q[t-1] = is_left(line[i].p, q[t-1]) ? line[i] : q[t-1]; }
            else q[t++] = line[i];
            if(t-h >= 2) p[t-1] = inc(q[t-2], q[t-1]);
    }
    while(t-h>=3 && !is_left(p[t-1], q[h])) t--;
    return t-h >= 3;
}
*/
 
bool half_plane() {
    sort(line + 1, line + lc + 1);
    int h = 0, t = 0; q[t++] = line[1];
    cout << t << ' ' << h << endl;
	srep(j, 0, t) cout << q[j].p.x << ' ' << q[j].p.y << ' ' << q[j].v.x << ' ' << q[j].v.y << ' ' << endl; 
	srep(j, 0, t) cout << q[j].p.x << ' ' << q[j].p.y << ' ' << q[j].v.x << ' ' << q[j].v.y << ' ' << endl;
	cout << endl;
    for(int i = 2; i <= lc; i++) {if(!(line[i] == q[t-1])) {
        while(t-h >= 2 && !is_left(p[t-1], line[i])) t--;
        while(t-h >= 2 && !is_left(p[h+1], line[i])) h++;
        q[t++] = line[i];
        if(t-h >= 2) p[t-1] = inc(q[t-2], q[t-1]);
        }
        if (1){
			cout << t << ' ' << h << ' ' << t << ' ' << h << endl;
			srep(j, 0, t) cout << q[j].p.x << ' ' << q[j].p.y << ' ' << q[j].v.x << ' ' << q[j].v.y << ' ' << endl, cout << p[j].x << ' ' << p[j].y << endl;
			srep(j, 0, t) cout << q[j].p.x << ' ' << q[j].p.y << ' ' << q[j].v.x << ' ' << q[j].v.y << ' ' << endl, cout << p[j].x << ' ' << p[j].y << endl;
			cout << line[i].p.x << ' ' << line[i].p.y << ' ' << line[i].v.x << ' ' << line[i].v.y << ' ' << endl << endl; 
		}
    }
    while(t-h>=3 && !is_left(p[t-1], q[h])) t--;
    return t-h >= 3;
}
 
bool judge(DB d) {
    lc = 0;
    for(int i = 1; i <= n; i++) {
        Vect s = A[i], v = A[i+1] - A[i];
        Vect vt = (Vect) {-v.y, v.x};
        s = s + vt * (d / sqrt(vt ^ vt));
        for(int i = 1; i <= m; i++) line[++lc] = (Line) {s - B[i], v, atan2(v.y, v.x)};
    }
    return half_plane();
}
 
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> A[i].x >> A[i].y;
    A[n+1] = A[1];
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> B[i].x >> B[i].y;
    B[m+1] = B[1];
 
    DB lt = 0, rt = 1e4;
    for(int cas = 1; cas <= 100; cas++) {
        DB mid = (lt + rt) / 2;
        if(judge(mid)) lt = mid;
        else rt = mid;
    }
 
    cout << fixed << setprecision(10) << lt / 2 << endl;
}
