#include <bits/stdc++.h>
#include "find.h"
using namespace std;

int solve(int l, int r, int x){
	while (l < r){
		int mid = ((r - l) >> 1) + l;
		if (query(mid) > x) r = mid;
		else l = mid + 1;
	}
	return l;
}

int find_pos(int n, int x){
	int k = solve(1, n + 1, x);
	return k - 1;
} 
