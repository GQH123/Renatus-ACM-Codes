#include<bits/stdc++.h>
 
using namespace std;
 
#define rep(i,j,n) for(int i=j;i<=n;i++)
int T,n;
int DL[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
struct noob
{
    int y[4];
    int m[2],d[2];
}f[100010];
char s[12];
//unordered_set<int> M[100];
bool M[100],D[100];
int TM[40],TD[40];
int dateid(int y,int m,int d)
{
    if(y<1600) return 0;
    if(d>DL[m]) return 0;
    if(m==2 && d==29)
        if(y%4 || (y%100==0 && y%400)) return 0;
    y+=2800;
    if(m<3) y--,m+=12;
    return y+y/4-y/100+y/400+(153*(m-3)+2)/5+d+1;
}
int main()
{
    //freopen("test.in","r",stdin);
    ios::sync_with_stdio(false);
    cin>>T;
    rep(tt,1,T)
    {
        cin>>n;
        rep(i,0,99) M[i]=D[i]=false;
        rep(i,0,n-1)
        {
            cin>>s;
            rep(j,0,3)
                f[i].y[j]=s[j]-'A';
            rep(j,0,1)
                f[i].m[j]=s[j+5]-'A';
            rep(j,0,1)
                f[i].d[j]=s[j+8]-'A';
            M[f[i].m[0]*10+f[i].m[1]]=true;
            D[f[i].d[0]*10+f[i].d[1]]=true;
        }
        int tm=0,td=0;
        rep(i,0,99)
        {
            if(M[i]) TM[++tm]=i;
            if(D[i]) TD[++td]=i;
            if(tm > 12 || td>31) break;
        }
        if(tm>12 || td>31)
        {
            printf("Case #%d: ",tt);
            puts("Impossible");
            continue;
        }
        int A[10]={0,1,2,3,4,5,6,7,8,9};
        int ttt=0;
        bool p=true;
        do{
            if(ttt>=50000000){p=false;break;}
            //rep(i,0,9) printf("%d",A[i]);
            //puts("");
            p=true;
            //rep(i,0,9) B[A[i]]=i;
            rep(i,1,tm)
            {
                int temp=A[TM[i]%10]+A[TM[i]/10]*10;
                if(temp==0 || temp>=13)
                    {
                        p=false;
                        break;
                    }
            }
            if(!p) continue;
            rep(i,1,td)
            {
                int temp=A[TD[i]%10]+A[TD[i]/10]*10;
                if(temp==0 || temp>=32)
                    {
                        p=false;
                        break;
                    }
            }
            if(!p) continue;
            int Inc=101;
            if(n%Inc==0) Inc=103;
            if(n%Inc==0) Inc=107;
            for(int i=rand()%n,j=0;j<n;j++,i+=Inc)
            {
                if(i>=n) i%=n;
                ttt++;
                int id=dateid(A[f[i].y[0]]*1000+A[f[i].y[1]]*100+A[f[i].y[2]]*10+A[f[i].y[3]],
                              A[f[i].m[0]]*10+A[f[i].m[1]], A[f[i].d[0]]*10+A[f[i].d[1]]);
                if(id%7!=4)
                {
                    p=false;
                    break;
                }
            }
            if(!p) continue;
            printf("Case #%d: ",tt);
            rep(i,0,9) printf("%d",A[i]);
            puts("");
            break;
        }while(next_permutation(A,A+10));
        if(!p){printf("Case #%d: ",tt);
        puts("Impossible");}
    }
}
