#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long LL;

const int MAXN=1000005;

struct operation
{
	int ty,l,r,d,id;
};

int n,m,a[MAXN],tm_node[MAXN],yl,yr;
LL V,sumv[MAXN*4],addv[MAXN*4],ans[MAXN];
vector <operation> qu[MAXN];
vector <int> G[MAXN];

void build(int o,int l,int r)
{
	addv[o]=0;
	if (l<r)
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		build(lc,l,m);
		build(rc,m+1,r);
		sumv[o]=sumv[lc]+sumv[rc];
	}
	else
		sumv[o]=a[l];
}

void update(int o,int l,int r)
{
	if (yl<=l&&yr>=r)
	{
		addv[o]+=V;
		sumv[o]+=V*(r-l+1);
	}
	else
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		if (yl<=m)
			update(lc,l,m);
		if (yr>m)
			update(rc,m+1,r);
		sumv[o]=sumv[lc]+sumv[rc];
	}
}

void query(int o,int l,int r,LL add)
{
	if (yl<=l&&yr>=r)
		V+=sumv[o]+add*(r-l+1);
	else
	{
		int m=l+r>>1;
		add+=addv[o];
		if (yl<=m)
			query(o<<1,l,m,add);
		if (yr>m)
			query(o<<1|1,m+1,r,add);
	}
}

void dfs(int u)
{
	for (const auto &q:qu[u])
		if (q.ty==0)
		{
			yl=q.l;
			yr=q.r;
			V=q.d;
			update(1,1,n);
		}
	for (const auto &q:qu[u])
		if (q.ty==1)
		{
			yl=q.l;
			yr=q.r;
			V=0;
			query(1,1,n,0);
			ans[q.id]=V;
		}
	for (int v:G[u])
		dfs(v);
	for (const auto &q:qu[u])
		if (q.ty==0)
		{
			yl=q.l;
			yr=q.r;
			V=-q.d;
			update(1,1,n);
		}
}

void solve()
{
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=0;i<=m;i++)
	{
		G[i].clear();
		qu[i].clear();
	}
	tm_node[0]=0;
	int node=0,qc=0;
	for (int i=0,now=0;i<m;i++)
	{
		char op[5];
		scanf("%s",op);
		operation t;
		if (op[0]=='C')
		{
			t.ty=0;
			scanf("%d%d%d",&t.l,&t.r,&t.d);
			G[tm_node[now]].pb(++node);
			tm_node[++now]=node;
			qu[node].pb(t);
		}
		else if (op[0]=='Q')
		{
			t.ty=1;
			scanf("%d%d",&t.l,&t.r);
			t.id=qc++;
			qu[tm_node[now]].pb(t);
		}
		else if (op[0]=='H')
		{
			t.ty=1;
			int tt;
			scanf("%d%d%d",&t.l,&t.r,&tt);
			t.id=qc++;
			qu[tm_node[tt]].pb(t);
		}
		else
		{
			int tt;
			scanf("%d",&tt);
			now=tt;
		}
	}
	build(1,1,n);
	dfs(0);
	for (int i=0;i<qc;i++)
		printf("%lld\n",ans[i]);
}

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	while (scanf("%d%d",&n,&m)!=EOF) solve();
	return 0;
}
