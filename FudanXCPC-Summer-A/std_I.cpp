#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#include<ctype.h>
#include<algorithm>
#include<deque>
#include<functional>
#include<iterator>
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<sstream>
#define CPY(A, B) memcpy(A, B, sizeof(A))
typedef long long LL;
typedef unsigned long long uLL;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const LL INFF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;
const double OO = 1e20;
const double PI = acos (-1.0);
int dx[]= {0,1,1,1,0,-1,-1,-1};
int dy[]= {1,1,0,-1,-1,-1,0,1};
int gcd (const LL &a, const LL &b) {return b==0?a:gcd (b,a%b);}
LL LLpow (LL a, LL b) {
    if (b==0) {return 1;}
    LL t=LLpow (a,b/2);
    if (b%2) {return t*t*a;}
    return t*t;
}
using namespace std;
int T,t,n,m;
map<string,string> match[4];
char str[1010],str2[1010],s1[1010],s2[1010];
int type1,type2,Err,Over;
bool Has_Equal() {
    int i,len=strlen (str);
    bool flag=0,flag2=0;
    for (i=0; i<len; i++) {
        if (str[i]==34) {flag2=1;}
        if (str[i]=='=' && flag2==0) {
            flag=true;
            str[i]=' ';
        }
        if (str[i]==9) {str[i]=32;}
    }
    return flag;
}
bool kong() {
    int i,len=strlen (str);
    for (i=0; i<len; i++)
        if (! (str[i]==' ' || str[i]==9) ) {
            return false;
        }
    return true;
}
void solve() {
    int i,len=strlen (str);
    m=0;
    for (i=0; i<len; i++)
        if (str[i]==34) {break;}
    m=i;
    for (i=m; i<len; i++)
        if (! (str[i]==' ' || str[i]==9) ) {str[m++]=str[i];}
    str[m]='\0';
}
int main() {
    string string1,string2;
    scanf ("%d",&T);
    for (t=1; t<=T; t++) {
        if (t!=1) {puts ("");}
        scanf ("%d",&n); getchar();
        for (int i=0; i<=3; i++) {
            match[i].clear();
        }
        Err=1; Over=0;/**Init*/
        while (n--) {
            gets (str);
            solve();
            if (Over==1) {continue;}
            if (kong() ) {continue;}
            if (Has_Equal() ) {
                sscanf (str,"%s %s",s1,s2);
                if (s1[0]=='$') {type1=0;}
                else {type1=1;}
                if (s2[0]!=34) {type2=0;}
                else {type2=1;}
                if (type1==0) {
                    match[0].erase (s1);
                    match[1].erase (s1);
                    match[type2][s1]=s2;
                } else {
                    if (match[2].find (s1) ==match[2].end() && match[3].find (s1) ==match[3].end() ) {
                        match[2+type2][s1]=s2;
                    } else if (Err==1) {
                        printf ("WARNING: Constant %s Already Defined!\n",s1);
                    }
                }
            } else {
                sscanf (str,"%s %s",s1,s2);
                if (s1[0]=='P' && s1[1]=='a') { //Panic
                    printf ("Script was KILLED.\n");
                    Over=1;
                } else if (s1[0]=='E' && s2[1]=='N') { //Errmsg ON
                    Err=1;
                } else if (s1[0]=='E' && s2[1]=='F') { //Errmsg OFF
                    Err=0;
                } else if (s1[0]=='P') { //Print
                    if (s2[0]=='$') {
                        if (match[0].find (s2) !=match[0].end() ) {
                            string1=match[0][s2];
                            cout<<string1<<endl;
                        } else if (match[1].find (s2) !=match[1].end() ) {
                            string1=match[1][s2];
                            string2=string1.substr (1,string1.length()-2);
                            cout<<string2<<endl;
                        } else {
                            printf ("NULL\n");
                            if (Err==1) {
                                printf ("NOTICE: Undefined Variable %s.\n",s2);
                            }
                        }
                    } else {
                        if (match[2].find (s2) !=match[2].end() ) {
                            string1=match[2][s2];
                            cout<<string1<<endl;
                        } else if (match[3].find (s2) !=match[3].end() ) {
                            string1=match[3][s2];
                            string2=string1.substr (1,string1.length()-2);
                            cout<<string2<<endl;
                        } else {
                            printf ("%s\n",s2);
                            if (Err==1) {
                                printf ("NOTICE: Undefined Constant %s.\n",s2);
                            }
                        }
                    }
                } else if (s1[0]=='D') { //Dump
                    if (s2[0]=='$') {
                        if (match[0].find (s2) !=match[0].end() ) {
                            string1=match[0][s2];
                            printf ("integer: ");
                            cout<<string1<<endl;
                        } else if (match[1].find (s2) !=match[1].end() ) {
                            string1=match[1][s2];
                            printf ("string: ");
                            cout<<string1<<endl;
                        } else {
                            printf ("NULL\n");
                            if (Err==1) {
                                printf ("NOTICE: Undefined Variable %s.\n",s2);
                            }
                        }
                    } else {
                        if (match[2].find (s2) !=match[2].end() ) {
                            string1=match[2][s2];
                            printf ("integer: ");
                            cout<<string1<<endl;
                        } else if (match[3].find (s2) !=match[3].end() ) {
                            string1=match[3][s2];
                            printf ("string: ");
                            cout<<string1<<endl;
                        } else {
                            printf ("string: %c%s%c\n",34,s2,34);
                            if (Err==1) {
                                printf ("NOTICE: Undefined Constant %s.\n",s2);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
