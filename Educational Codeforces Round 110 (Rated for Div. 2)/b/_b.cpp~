#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 2100
using namespace std;
int T,n,m;
int a[MAXN];
int cnt[MAXN];
bool vis[MAXN];
int gcd(int x,int y)
{
    return y?gcd(y,x%y):x;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(j!=i && gcd(a[i],2*a[j])>1)
                    cnt[i]++;
        
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int loc=0;
            for(int j=1;j<=n;j++)
            {
                if(!vis[j] && cnt[loc] < cnt[j])
                    loc = j;
            }
            ans+=cnt[loc];
            vis[loc]=1;

            for(int j=1;j<=n;j++)
            {
                if(!vis[j] && j!=loc && gcd(a[j],2*a[loc]) > 1)
                    cnt[j]--;
            }
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
