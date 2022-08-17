#include <bits/stdc++.h>
#define LL long long
const int MAXN = 1e6 + 6;
using namespace std;
LL x0, x1, a, b, MOD;
char n[MAXN];
struct Mat {
    LL a[2][2];
    Mat(){}
    Mat Mul(Mat&r) {
        Mat c;
        for(int i = 0; i < 2; ++ i)
            for(int j = 0; j < 2; ++ j)
                c.a[i][j] = 0;
        for(int i = 0; i < 2; ++ i)
            for(int j = 0; j < 2; ++ j)
                for(int k = 0; k < 2; ++ k)
                    c.a[i][k] = (c.a[i][k] + a[i][j] * r.a[j][k] % MOD) % MOD;
        return c;
    }
};
int main() {
    cin >> x0 >> x1 >> a >> b;
    scanf("%s", n + 1); cin >> MOD;
    int L = strlen(n + 1);
    Mat ans, A, B, one;
    for(int i = 0; i < 2; ++ i)
        for(int j = 0; j < 2; ++ j)
            ans.a[i][j] = (i == j);
    for(int i = 0; i < 2; ++ i)
        for(int j = 0; j < 2; ++ j)
            one.a[i][j] = (i == j);
    A.a[0][0] = 0; A.a[0][1] = 1;
    A.a[1][0] = b; A.a[1][1] = a;
    for(int i = L; i > 0; -- i) {
        int digit = n[i] - '0';
        Mat tmp = one;
        for(int j = 1; j <= digit; ++ j)
            tmp = tmp.Mul(A);
        ans = ans.Mul(tmp);
        for(int j = digit + 1; j <= 10; ++ j)
            tmp = tmp.Mul(A);
        A = tmp;
    }
    B.a[0][0] = x0; B.a[0][1] = 0;
    B.a[1][0] = x1; B.a[1][1] = 0;
    B = ans.Mul(B);
    cout << B.a[0][0] << endl;
    return 0;
}
