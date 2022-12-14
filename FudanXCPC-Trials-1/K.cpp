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
} A[MX], B[MX], p[MX * MX], p2[MX * MX];

int lc;
struct Line {
    Vect p, v; DB a;
    bool operator < (const Line &rhs) const { 
        if(fabs(this -> a - rhs.a) < eps) return fabs((p-rhs.p) * rhs.v) < eps ? p.x < rhs.p.x : (p-rhs.p) * rhs.v < 0;
        return a < rhs.a;
    }
} line[MX * MX], q[MX * MX], q2[MX * MX];

bool para(const Line a, const Line b){
	return fabs(a.a - b.a) < eps;
}
Vect inc(const Line &a, const Line &b) { return b.p + b.v * ((b.p - a.p) * a.v / (a.v * b.v)); }
bool is_left(const Vect &a, const Line &l) { return (a-l.p) * l.v < eps; }

namespace I{
	bool half_plane() {
		sort(line + 1, line + lc + 1);
		int h = 0, t = 0; q[t++] = line[1];
		int h2 = 0, t2 = 0; q2[t2++] = line[1];
		if (1){
					cout << t << ' ' << h << ' ' << t2 << ' ' << h2 << endl;
					srep(j, 0, t) cout << q[j].p.x << ' ' << q[j].p.y << ' ' << q[j].v.x << ' ' << q[j].v.y << ' ' << endl;
					srep(j, 0, t2) cout << q2[j].p.x << ' ' << q2[j].p.y << ' ' << q2[j].v.x << ' ' << q2[j].v.y << ' ' << endl; 
					cout << endl;
					if (t != t2 || h != h2) assert(false);
				}
		for(int i = 2; i <= lc; i++) {
		        while(t-h >= 2 && !is_left(p[t-1], line[i])) t--;
		        while(t-h >= 2 && !is_left(p[h+1], line[i])) h++;
		        if(para(q[t-1], line[i])) q[t-1] = is_left(line[i].p, q[t-1]) ? line[i] : q[t-1];
		        else q[t++] = line[i];
		        if(t-h >= 2) p[t-1] = inc(q[t-2], q[t-1]);
		        
		        if(!para(line[i], line[i-1])) {
					while(t2-h2 >= 2 && !is_left(p2[t2-1], line[i])) t2--;
					while(t2-h2 >= 2 && !is_left(p2[h2+1], line[i])) h2++;
					q2[t2++] = line[i];
					if(t2-h2 >= 2) p2[t2-1] = inc(q2[t2-2], q2[t2-1]);
				}
				
				if (1){
					cout << t << ' ' << h << ' ' << t2 << ' ' << h2 << endl;
					srep(j, 0, t) cout << q[j].p.x << ' ' << q[j].p.y << ' ' << q[j].v.x << ' ' << q[j].v.y << ' ' << endl, cout << p[j].x << ' ' << p[j].y << endl;
					srep(j, 0, t2) cout << q2[j].p.x << ' ' << q2[j].p.y << ' ' << q2[j].v.x << ' ' << q2[j].v.y << ' ' << endl, cout << p2[j].x << ' ' << p2[j].y << endl;
            		cout << line[i].p.x << ' ' << line[i].p.y << ' ' << line[i].v.x << ' ' << line[i].v.y << ' ' << endl << endl;
					if (t != t2 || h != h2) assert(false);
				}
		}
		while(t-h>=3 && !is_left(p[t-1], q[h])) t--;
		while(t2-h2>=3 && !is_left(p2[t2-1], q2[h2])) t2--;
		return t2-h2 >= 3;
	}
}

/*
namespace II{
	bool half_plane() {
		sort(line + 1, line + lc + 1);
		int h = 0, t = 0; q[t++] = line[1];
		for(int i = 2; i <= lc; i++) if(!(line[i] == line[i-1])) {
		    while(t-h >= 2 && !is_left(p[t-1], line[i])) t--;
		    while(t-h >= 2 && !is_left(p[h+1], line[i])) h++;
		    q[t++] = line[i];
		    if(t-h >= 2) p[t-1] = inc(q[t-2], q[t-1]);
		}
		while(t-h>=3 && !is_left(p[t-1], q[h])) t--;
		return t-h >= 3;
	}
} 
*/

bool judge(DB d) {
    lc = 0;
    for(int i = 1; i <= n; i++) {
        Vect s = A[i], v = A[i+1] - A[i];
        Vect vt = (Vect) {-v.y, v.x};
        s = s + vt * (d / sqrt(vt ^ vt));
        for(int i = 1; i <= m; i++) line[++lc] = (Line) {s - B[i], v, atan2(v.y, v.x)};
    }
    return I :: half_plane();
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
	  	  				 			      	 			  			
