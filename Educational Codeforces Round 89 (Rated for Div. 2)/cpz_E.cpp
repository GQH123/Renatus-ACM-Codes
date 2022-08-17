#include<cstdio>
#include<algorithm>
#define N 200005
#define ll long long
#define mod 998244353
#define inf 1000000000
using namespace std;
int a[N], b[N];
int dp[N];
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
	for(int j=1; j<=m; ++j) scanf("%d", &b[j]);
	int cur=inf;
	for(int i=n, j=m; i>=1; --i){
		cur=min(cur, a[i]);
		while(cur<b[j]) --j;
		if(cur==b[j]) ++dp[j];
		
	}
	
	if(cur!=b[1]) printf("0");
	else{
	    int ans=1;
		for(int j=2;j<=m; ++j) ans=(ll)ans*dp[j]%mod;
		printf("%d", ans);
	}
	return 0;
}
