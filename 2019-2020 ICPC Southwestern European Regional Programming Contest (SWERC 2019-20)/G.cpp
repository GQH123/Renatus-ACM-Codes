#include<cstdio>
#include<algorithm>
#include<cstring>
#define S 205
#define N 100005
using namespace std;
int s, l ,n;
char spe[S][25];
bool f[S][S];//friends
int a[N];
int id(char *st){
	for(int i=1;i<=s;++i) if(!strcmp(st, spe[i])) return i;
}
char t1[25], t2[25];
int h[S],pre[S];
int E[N][S];
int in[S];

int main(){
	scanf("%d%d%d", &s, &l, &n);
	for(int i=1;i<=s;++i) scanf("%s", spe[i]);
	for(int i=1;i<=s;++i){
		for(int j=1;j<i;++j){
			if(strcmp(spe[i],spe[j])<0){
				strcpy(t1,spe[i]);
				strcpy(spe[i],spe[j]);
				strcpy(spe[j],t1);
			}
		}
	}
	for(int i=1;i<=l;++i){
		scanf("%s%s", t1, t2);
		int i1=id(t1), i2=id(t2);
		f[i1][i2]=f[i2][i1]= true;
	}
	for(int i=1;i<=n;++i){
		scanf("%s", t1);
		a[i]=id(t1);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=s;++j){
			if(!f[a[i]][j] && pre[j] && !E[pre[j]][a[i]]) E[pre[j]][a[i]]=i, ++in[i];
		}
		if(!pre[a[i]]) h[a[i]]=i;
		pre[a[i]] = i;//previous
	}
	for(int i=1;i<=n;++i){
		int u;
		for(int j=1;j<=s;++j){
			//printf("%d ",h[j]);
			if(h[j] && !in[h[j]]){
				u=h[j];
				h[j]=E[u][j];
				break;
			}
		}
		printf("%s ",spe[a[u]]);
		for(int j=1;j<=s;++j){
			if(E[u][j]){
				--in[E[u][j]];
			} 
		}
	}
	return 0;
} 

