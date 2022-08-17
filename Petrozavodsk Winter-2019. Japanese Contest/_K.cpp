#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

const int X = 10000;

int f(vector<int>& A, vector<int>& B) {
    int a = 0, win = 0;
    rep(x, X) {
        int k = min(B[x], a);
        a -= k;
        win += k;
        a += A[x];
    }
    return win;
}

int g(vector<int>& A, vector<int>& B, int x) {
    B[x]--;
    int ans = f(A, B);
    B[x]++;
    return ans;
}

int main() {
    int N; cin >> N;
    vector<int> a(N);
    rep(i, N) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> b(N);
    rep(i, N) {
        cin >> b[i];
        b[i]--;
    }
    sort(all(b));
    vector<int> A(X);
    rep(i, N) A[a[i]]++;
    vector<int> v(N);
    rep(i, N) {
        int M = b.size();
        vector<int> B(X);
        rep(j, M) B[b[j]]++;
        int x0 = a[i];
        A[x0]--;
        int m = upper_bound(all(b), x0) - b.begin();
        i_i ans = i_i{-1, -1};
        if (m > 0) {
            int win = g(A, B, b[0]);
            int lb = 0, ub = m;
            while (ub - lb > 1) {
                int j = (lb + ub) / 2;
                if (g(A, B, b[j]) == win) lb = j;
                else ub = j;
            }
            ans = max(ans, i_i{win, lb});
        }
        if (m < M) {
            int win = g(A, B, b[m]);
            int lb = m, ub = M;
            while (ub - lb > 1) {
                int j = (lb + ub) / 2;
                if (g(A, B, b[j]) == win) lb = j;
                else ub = j;
            }
            ans = max(ans, i_i{win + 1, lb});
        }
        int j = get<1>(ans);
        v[i] = b[j];
        b.erase(b.begin() + j);
    }
    rep(i, N) cout << v[i] + 1 << (i + 1 < N ? ' ' : '\n');
}
