#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i,j,n) for(int i=j;i<=n;i++)
int T;
const ll PP=(1ll<<30)+3;
ll n,c;

ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0) return x=1,y=0,a;
    ll t= exgcd(b,a%b,y,x);
    y-=a/b*x;
    return t;
}

ll pmod(ll x,ll y,ll n)
{
	if(y<0)
		return pmod(x,y+n-1,n);
    ll z=1;
    for(;y;y>>=1){if(y&1)z=z*x%n;x=x*x%n;}
    return z;
}

int main()
{
	//freopen("K.in","r",stdin);
    cin>>T;
    rep(tt,1,T)
    {
        cout<<"Case "<<tt<<": ";
        cin>>n>>c;
        ll p=sqrt(n);
        while(n%p!=0)
            p--;
        ll q=n/p;
        ll c1=c%p;
        ll c2=c%q;
        {
            ll x,y;
            ll k1=PP % (p-1);
            exgcd(p-1,k1,x,y);
            ll x1=c1 ? pmod(c1,(1-x*(p-1))/k1,p) : 0;

            ll k2=PP % (q-1);
            exgcd(q-1,k2,x,y);
            ll x2=c2 ? pmod(c2,(1-x*(q-1))/k2,q) : 0;

            exgcd(p,q,x,y);	
            ll a=(p*((x*x2)%q)+q*((y*x1)%p))%n;
            cout<<(a+n)%n<<endl;
        }
    }
}

