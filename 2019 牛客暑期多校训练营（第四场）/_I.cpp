#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4e5+5;
const int MAX=2e5+5;
const int ALP=26;
int ran[maxn],tem[maxn],sa[maxn],lcp[maxn];
ll n,k,x;
 
struct Palindromic_Tree {
    int son[MAX][ALP]; //转移边
    int fail[MAX]; //fail 指针
    int cnt[MAX]; //当前节点表示的回文串在原串中出现了多少次
    int num[MAX]; //当前节点 fail 可以向前跳多少次
    int len[MAX]; //当前节点表示的回文串的长度
    int S[MAX]; //插入的字符串
    int last; //最后一次访问到的节点，类似 SAM
    int n; //插入的字符串长度
    int p; //自动机的总状态数
 
    int newnode(int l) {
        memset(son[p], 0, sizeof(son[p]));
        cnt[p] = 0;
        num[p] = 0;
        len[p] = l;
        return p++;
    }
 
    void init() {
        p = 0;
        newnode(0);
        newnode(-1);
        last = 0;
        n = 0;
        S[n] = -1;
        fail[0] = 1;
    }
 
    int get_fail(int x) {
        while (S[n - len[x] - 1] != S[n]) x = fail[x];
        return x;
    }
 
    void add(int c) {
        c -= 'a';
        S[++n] = c;
        int cur = get_fail(last); //通过上一次访问的位置去扩展
        if (!son[cur][c]) { //如果没有对应的节点添加一个新节点
            int now = newnode(len[cur] + 2);
            fail[now] = son[get_fail(fail[cur])][c]; //通过当前节点的 fail 去扩展出新的 fail
            son[cur][c] = now;
            num[now] = num[fail[now]] + 1; //记录 fail 跳多少次
        }
        last = son[cur][c];
        cnt[last]++; //表示当前节点访问了一次
    }
    void count() {
        //如果某个节点出现一次，那么他的 fail 也一定会出现一次，并且在插入的时候没有计数
        for (int i = p - 1; i >= 0; i--) cnt[fail[i]] += cnt[i];
    }
} AUT;
bool compare_sa(int i,int j){
    if(ran[i]!=ran[j]) return ran[i]<ran[j];
    else{
        int x=i+k<=n?ran[i+k]:-1;
        int y=j+k<=n?ran[j+k]:-1;
        return x<y;
    }
}
void calc_sa(string s,int *sa){
    for(int i=0;i<=n;i++){
        sa[i]=i;
        ran[i]=i<n?s[i]:-1;
    }
    for(k=1;k<=n;k*=2){
        sort(sa,sa+n+1,compare_sa);
        tem[sa[0]]=0;
        for(int i=1;i<=n;i++){
            tem[sa[i]]=tem[sa[i-1]]+(compare_sa(sa[i-1],sa[i])?1:0);
        }
        for(int i=0;i<=n;i++){
            ran[i]=tem[i];
        }
    }
}
void calc_lcp(string s,int *sa,int *lcp){
    for(int i=0;i<=n;i++) ran[sa[i]]=i;
    int h=0;
    lcp[0]=0;
    for(int i=0;i<n;i++){
        int j=sa[ran[i]-1];
        if(h>0) h--;
        for(;j+h<n&&i+h<n;h++){
            if(s[j+h]!=s[i+h]) break;
        }
        lcp[ran[i]-1]=h;
    }
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("I.in", "r", stdin);
	#endif
    string s;
    cin>>s;
    x=n=s.length();
    AUT.init();
    for(int i=0;i<s.length();i++) AUT.add(s[i]);
    ll q=AUT.p-2;
    string ss=s;
    reverse(s.begin(),s.end());
    s=ss+'@'+s;
    n=2*n+1;
    calc_sa(s,sa);
    calc_lcp(s,sa,lcp);
    ll cnt=0;
    for(int i=1;i<n;i++){
        cnt+=lcp[i];
    }
    ll p=n*(n+1)/2-cnt-(x+1)*(x+1);
    cout << p << ' ' << q << endl;
    cout<<(p+q)/2<<endl;
    return 0;
}
