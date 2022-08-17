#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 1005;
char a[maxn][maxn];
int dp[maxn][maxn];

int main()
{
    int n,ans;
    while(scanf("%d",&n)!=EOF && n)
    {
        ans = 1;
        for(int i=0;i<n;i++)
            scanf("%s",a[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>=0;j--)
            {
                dp[i][j] = 1;
                if(i == 0 || j == n-1) continue;
                int k = dp[i-1][j+1];
                for(int s=1;s<=k;s++)
                {
                    if(a[i-s][j] == a[i][j+s]) dp[i][j]++;
                    else break;
                }
                ans = max(ans,dp[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
