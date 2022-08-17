#include<bits/stdc++.h>
//#include<tr1/unordered_map>
using namespace std;
//using namespace std::tr1;
const double eps=1e-9;
const double pi=acos(-1.);
typedef pair<double,double> PII;
#define rep(i,j,n) for(int i=j;i<=n;i++)
PII f[3];
int T;
double w,h,a,b,c;
void print()
{
    rep(i,0,1)
        printf("%.8lf %.8lf ",f[i].first,f[i].second);
    printf("%.8lf %.8lf\n",f[2].first,f[2].second);
}
bool Get(double w,double h,double a,double b,double c,int x,int y,int z)
{
        f[x]=PII(0,0);
        if(a<=w)
            f[y]=PII(a,0);
        else
            f[y]=PII(w,sqrt(a*a-w*w));
        double d=acos((a*a+b*b-c*c)/2/a/b);
        d+=atan(f[y].second/f[y].first);
        //cout<<d<<endl;
        if(d<-eps) d+=pi;
        if(d>2*pi-eps) d-=2*pi;
        if(d<=pi/2+eps)
        {
            f[z]=PII(b*cos(d),b*sin(d));
            if(f[z].first<=w+eps && f[z].second<=h+eps)
            {
                print();
                return 1;
            }
        }
        return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        cin>>w>>h>>a>>b>>c;
        if(!Get(w,h,a,b,c,0,1,2))
        if(!Get(w,h,a,c,b,1,0,2))
        if(!Get(w,h,b,a,c,0,2,1))
        if(!Get(w,h,b,c,a,2,0,1))
        if(!Get(w,h,c,a,b,1,2,0))
        Get(w,h,c,b,a,2,1,0);
    }
}
