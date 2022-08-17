#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=1000005;

int a[MAXN],maxbit,mx_pre[20][MAXN],mx_suf[20][MAXN],ans[MAXN];

int main()
{
#ifdef KeyID
	freopen("read.txt","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	while ((1<<maxbit)<=n) maxbit++;
	maxbit--;
	for (int i=1;i<=n;i++)
		mx_pre[0][i]=mx_suf[0][i]=a[i];
	for (int j=1;j<=maxbit;j++)
	{
		for (int i=1;i+(1<<j)-1<=n;i++)
			mx_suf[j][i]=max(mx_suf[j-1][i],mx_suf[j-1][i+(1<<j-1)]);
		for (int i=1<<j;i<=n;i++)
			mx_pre[j][i]=max(mx_pre[j-1][i-(1<<j-1)],mx_pre[j-1][i]);
	}
	int p=0;
	for (int i=1;i<=n;i++)
	{
		int now=a[i],l=i-1,r=i+1;
		for (;;)
		{
			int t=now;
			for (int j=31-__builtin_clz(l);j>=0;j--){
				cerr << j << ' ' << l << endl;
				if (l>=(1<<j)&&mx_pre[j][l]<=now)
				{
					now+=(1<<j);
					l-=(1<<j);
				}
				}
			for (int j=31-__builtin_clz(n-r+1);j>=0;j--)
				if (n-r+1>=(1<<j)&&mx_suf[j][r]<=now)
				{
					now+=(1<<j);
					r+=(1<<j);
				}
			if (t==now)
				break;
		}
		if (l<1&&r>n)
			ans[p++]=i;
	}
	printf("%d\n",p);
	for (int i=0;i<p;i++)
		printf("%d ",ans[i]);
	return 0;
}
