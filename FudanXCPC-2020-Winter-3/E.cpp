#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxr 100000
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

int get_num(char* s, int& pos){
	while (!('0' <= s[pos] && s[pos] <= '9')) pos++;
	int x = 0;
	while ('0' <= s[pos] && s[pos] <= '9') x = x * 10 + s[pos] - '0', pos++;
	return x;
}

char s[120];
char s1[] = "All OK";
char s2[] = "1 Point(s) Deducted";
char s3[] = "2 Point(s) Deducted";
char s4[] = "3 Point(s) Deducted";
char s5[] = "Issue Show Cause Letter";

int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("E.in", "r", stdin);
		#endif
	
	int n ;
	while (1){
		scanf("%d", &n);
		if (!n) return 0;
		int good_job = 0;
		rep(i, 1, n){
			scanf("%s", s);
			int type = (s[0] == 'D') ? 0 : 1;
			int pos = 1;
			int h1 = get_num(s, pos);
			int m1 = get_num(s, pos);
			int s1 = get_num(s, pos);
			int h2 = get_num(s, pos);
			int m2 = get_num(s, pos);
			int s2 = get_num(s, pos);
			
			int time1 = h1 * 3600 + m1 * 60 + s1;
			int time2 = h2 * 3600 + m2 * 60 + s2;
			int count_line = 8 * 3600 + 30 * 60 + 0;
			int stay_time = time2 - max(count_line, time1);
			int day_time = 9 * 3600 + 30 * 60 + 0;
			int even_time = 12 * 3600 + 30 * 60 + 0;
			if (type == 0) {
				if (stay_time < 8 * 3600 || time1 > day_time) good_job++;
			}
			else {
				if (stay_time < 9 * 3600 || time1 > even_time) good_job++;
			}
		}
		if (good_job == 0) printf("%s\n", s1);
		else if (good_job == 1) printf("%s\n", s2);
		else if (good_job == 2) printf("%s\n", s3);
		else if (good_job == 3) printf("%s\n", s4);
		else printf("%s\n", s5);
	}
	return 0;
}
