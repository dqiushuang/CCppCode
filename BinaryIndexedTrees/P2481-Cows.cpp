// P2481-Cows.cpp : 定义控制台应用程序的入口点。
//this problem is similar to p2352. in p2352, the secquence is order by y asc, x asc.
//so, here we order the secquence by e desc, s asc.
//submitted in c++
#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

#define N 100005

int n, tree[N], res[N];

struct cow{
	int s;
	int e;
	int idx;
}cows[N];

bool comp(cow a, cow b) {
	if(a.e == b.e)
		return a.s < b.s;
	return a.e > b.e ;
}

int read(int x) {
	int sum = 0;
	while(x > 0) {
		sum += tree[x];
		x -= (x & -x);
	}
	return sum;
}

void update(int x) {
	while(x <= n) {
		tree[x]++;
		x += (x & -x);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i, j;
	while(scanf("%d", &n), n != 0) {
		memset(cows, 0, sizeof(cows));
		memset(tree, 0, sizeof(tree));
		memset(res, 0, sizeof(res));

		for(i = 0; i < n; ++i) {
			scanf("%d%d", &cows[i].s, &cows[i].e);
			cows[i].s++;
			cows[i].idx = i;
		}
		sort(cows, cows + n, comp);  //the idea is the same as P2352
		struct cow pre = {-1, -1};
		int minus = 0;
		for(i = 0; i < n; ++i) {
			if(pre.e == cows[i].e && pre.s == cows[i].s)
				minus++;
			else {
				minus = 0;
				pre.e = cows[i].e;
				pre.s = cows[i].s;
			}
			res[cows[i].idx] = read(cows[i].s)  - minus;
			update(cows[i].s);
		}
		for(i = 0; i < n; i++)
			printf("%d ", res[i]);
		printf("\n");
	}
	getchar(); getchar();
	return 0;
}

