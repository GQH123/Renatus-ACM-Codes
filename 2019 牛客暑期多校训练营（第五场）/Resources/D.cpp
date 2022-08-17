#pragma GCC optimize(3)
#include<bits/stdc++.h>
 
using namespace std;
#define rep(i,j,n) for(int i=j;i<=n;i++)
typedef pair<int,int> PII;
const int N=400005;
int x[N+5],y[N+5];
int temp[N+5],mx[61][N+5],mi[61][N+5],nt[61][N+5],fx[N+5],fy[N+5];
int MX[N+5],MI[N+5];
int ax,ay,bx,by,px,py;
long long n;
 
inline void Get(int x,int n,int *MX,int *MI)
{
    int temp=60;
    int ans=-1;
    while(n)
    {
        while(1LL<<temp > n) temp--;
        n-=1LL<<temp;
        *MX=max(*MX,mx[x][temp]);
        *MI=min(*MI,mi[x][temp]);
        x=nt[x][temp];
    }
}
 
long long X(PII a,PII b,PII c)
{
    return 1ll*(b.second-a.second)*(c.first-a.first) - 1ll*(b.first-a.first)*(c.second-a.second);
}
 
void Solve()
{
    static PII Up[200005],Dn[200005];
    int Upl=0, Dnl=0;
    rep(i,0,px-1)
    {
        if(MX[i]<MI[i]) continue;
        //cout<<i<<' '<<MX[i]<<' '<<MI[i]<<endl;
        Up[++Upl]=PII(i,MX[i]);
        while(Upl>=3 && X(Up[Upl-2],Up[Upl-1],Up[Upl])<=0)
            Up[Upl-1]=Up[Upl],Upl--;
        Dn[++Dnl]=PII(i,MI[i]);
        while(Dnl>=3 && X(Dn[Dnl-2],Dn[Dnl-1],Dn[Dnl])>=0)
            Dn[Dnl-1]=Dn[Dnl],Dnl--;
    }
    long long ans=X(Dn[1],Up[Upl],Dn[Dnl]);
    rep(i,1,Upl - 1)
        ans+=X(Dn[1],Up[i],Up[i+1]);
    rep(i,1,Dnl - 1)
        ans-=X(Dn[1],Dn[i],Dn[i+1]);
    cout<<ans<<endl;
    return;
}
int main()
{
    cin>>x[0]>>y[0]>>ax>>ay>>bx>>by>>px>>py>>n;
    n--;
 
    rep(i,1,N)
        x[i]=(1ll*ax*x[i-1]+bx)%px;
    rep(i,1,N)
        y[i]=(1ll*ay*y[i-1]+by)%py;
 
    memset(MX,0x80,sizeof(MX));
    memset(MI,0x7f,sizeof(MI));
    if(n<=N)
    {
        rep(i,0,n)
        {
            MX[x[i]]=max(MX[x[i]],y[i]);
            MI[x[i]]=min(MI[x[i]],y[i]);
        }
        Solve();
        return 0;
    }
 
    int clx,stx,cly,sty;
    memset(temp,0,sizeof(temp));
    rep(i,0,N)
    {
        if(!temp[x[i]]) temp[x[i]]=i;
        fx[i]=temp[x[i]];
        if(fx[i]<i)
        {
            clx=i-fx[i];
            stx=fx[i];
            break;
        }
    }
    memset(temp,0,sizeof(temp));
    rep(i,0,N)
    {
        if(!temp[y[i]]) temp[y[i]]=i;
        fy[i]=temp[y[i]];
        if(fy[i]<i)
        {
            cly=i-fy[i];
            sty=fy[i];
            break;
        }
    }
 
    rep(i,0,cly-1)
    {
        mx[0][i]=y[i+sty];
        mi[0][i]=y[i+sty];
        nt[0][i]=(i+clx)%cly;
    }
    rep(k,1,60)
    {
        rep(i,0,cly-1)
        {
            mx[k][i]=max(mx[k-1][i],mx[k-1][nt[k-1][i]]);
            mi[k][i]=min(mi[k-1][i],mi[k-1][nt[k-1][i]]);
            nt[k][i]=nt[k-1][nt[k-1][i]];
        }
    }
 
    rep(i,0,max(stx,sty)-1)
    {
        MX[x[i]]=max(MX[x[i]],y[i]);
        MI[x[i]]=min(MI[x[i]],y[i]);
    }
    rep(i,max(stx,sty),max(stx,sty)+clx-1)
    {
        long long temp=(n-i)/clx+1;
        int k=63-__builtin_clzll(temp);
        MX[x[i]]=max(MX[x[i]],mx[k][(i-sty)%cly]);
        MX[x[i]]=max(MX[x[i]],mx[k][(i-sty+(temp-(1LL<<k))%cly*clx)%cly]);
        MI[x[i]]=min(MI[x[i]],mi[k][(i-sty)%cly]);
        MI[x[i]]=min(MI[x[i]],mi[k][(i-sty+(temp-(1LL<<k))%cly*clx)%cly]);
    }
    Solve();
    return 0;
}
