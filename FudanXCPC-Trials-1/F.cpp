#include <bits/stdc++.h>
using namespace std;

#define fi first
#define sc second

const int MAXN=5,MAXM=15,MOD=998244353;

struct myArray
{
	int d[5];

	bool operator < (const myArray &b) const
	{
		for (int i=0;i<5;i++)
			if (d[i]!=b.d[i])
				return d[i]<b.d[i];
		return false;
	}

	int & operator [] (int x)
	{
		return d[x];
	}
};

int dwn[MAXN][MAXM],rgt[MAXN][MAXM];
map <myArray,int> dp[MAXN][MAXM];

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int n,m,z;
	scanf("%d%d%d",&n,&m,&z);
	memset(dwn,-1,sizeof(dwn));
	memset(rgt,-1,sizeof(rgt));
	while (z--)
	{
		int r1,c1,r2,c2,w;
		scanf("%d%d%d%d%d",&r1,&c1,&r2,&c2,&w);
		r1--;
		c1--;
		r2--;
		c2--;
		if (r1>r2||c1>c2)
		{
			swap(r1,r2);
			swap(c1,c2);
		}
		if (r1!=r2)
			dwn[r1][c1]=w;
		else
			rgt[r1][c1]=w;
	}
	for (int i=0;i<n;i++)
		rgt[i][m-1]=0;
	myArray init;
	for (int i=0;i<n-1;i++)
		init[i]=100000;
	init[n-1]=0;
	dp[0][m][init]=1;
	for (int i=m-1;i>=0;i--)
	{
		if (rgt[n-1][i]>=0)
			for (const auto &s:dp[0][i+1])
			{
				auto s2=s.fi;
				s2[n-1]+=rgt[n-1][i];
				(dp[n-1][i][s2]+=s.sc)%=MOD;
			}
		else
		{
			for (const auto &s:dp[0][i+1])
				for (int k=0;k<2;k++)
				{
					auto s2=s.fi;
					s2[n-1]+=k;
					(dp[n-1][i][s2]+=s.sc)%=MOD;
				}
		}
		for (int j=n-2;j>=0;j--)
		{
			for (const auto &s:dp[j+1][i])
			{
				for (int k=(dwn[j][i]>=0)?dwn[j][i]:0;k<=((dwn[j][i]>=0)?dwn[j][i]:1);k++)
					for (int l=(rgt[j][i]>=0)?rgt[j][i]:0;l<=((rgt[j][i]>=0)?rgt[j][i]:1);l++)
					{
						auto s2=s.fi;
						s2[j]=min(s2[j+1]+k,s2[j]+l);
						(dp[j][i][s2]+=s.sc)%=MOD;
					}
			}
		}
	}
	int ans=0;
	for (const auto &s:dp[0][0])
	{
		bool flag=true;
		for (int i=1;i<n;i++)
			if (s.fi.d[i]!=s.fi.d[0])
			{
				flag=false;
				break;
			}
		if (flag)
			(ans+=s.sc)%=MOD;
	}
	printf("%d\n",ans);
	return 0;
}
