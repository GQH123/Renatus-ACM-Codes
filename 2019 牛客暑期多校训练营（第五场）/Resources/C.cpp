#include<bits/stdc++.h>
//#include<tr1/unordered_map>
using namespace std;
//using namespace std::tr1;
typedef long long ll;
long long n,x,a,b,p,Q,v,T;
typedef pair<int,int> P;
int phi(int n)
{
    int t=1,i;
    for(i=2;i*i<=n;i++)
    if(n%i==0)
    for(n/=i,t*=i-1;n%i==0;n/=i,t*=i);
    if(n>1)t*=n-1;
    return t;
}
int pmod(ll a,int b,int m){ll t=1;for(;b;b>>=1,a=a*a%m)if(b&1)t=t*a%m;return t;}
int g,at;
unordered_map<int,int> u;
inline void bsgspre(int a,int m)
{
    u.clear();
    at=int(2+m/1000);
    int x=1;
    g=m-1,u[x]=0;g=pmod(a,g-at%g,m);
    for(int i=1;i<at;i++)
        u.insert(P(x=ll(x)*a%m,i));
}
inline int bsgs(int a,int r,int m)
{
    if(r>=m)return -1;
 
    //for(i=0,x=1%m;i<50;i++,x=ll(x)*a%m) if(x==r) return i;
    //for(g=x=1;__gcd(int(ll(x)*a%m),m)!=g;c++)g=__gcd(x=ll(x)*a%m,m);
    if(r==0) return -1;
    if(1==r) return 0;
    for(int i=0;i<1000;i++)
    {
        unordered_map<int,int>::iterator t=u.find(r);
        r=ll(r)*g%m;
        if(t!=u.end()) return i*at+t->second;
    }
    return -1;
}
inline int G(int x)
{
    return x<n ? x : -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        cin>>n>>x>>a>>b>>p;
        cin>>Q;
        bsgspre(a,p);
        while(Q--)
        {
            cin>>v;
            //cout<<v<<' '<<x<<endl;
            if(v==x)
            {
                cout<<0<<endl;
                continue;
            }
            if(a==0)
            {
                if(v==b) cout<<1<<endl;else cout<<-1<<endl;
                continue;
            }
            if(a==1)
            {
                if(b==0) cout<<-1<<endl;else cout<<G(((v-x)*pmod(b,p-2,p)%p+p)%p)<<endl;
                continue;
            }
            long long temp=b*pmod(a-1,p-2,p)%p;
            if((x+temp)%p==0){cout<<-1<<endl;continue;}
            v=(v+temp)%p*pmod((x+temp)%p,p-2,p)%p;
            cout<<G(bsgs(a,(v+p)%p,p))<<endl;
        }
 
    }
}
