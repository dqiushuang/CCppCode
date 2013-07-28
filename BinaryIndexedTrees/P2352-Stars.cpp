// P2352-Stars.cpp : 定义控制台应用程序的入口点。
//As Stars are listed in ascending order of Y coordinate. Stars with equal Y coordinates are listed in ascending order of X coordinate. 
//So, the stars those contribute to the star(x, y) are scanfed before (x, y). Using x coordinate is OK.  
#include "stdafx.h"
#include <stdio.h>

#define N 15005
#define MAXVAL 32005
int tree[MAXVAL];
int res[N];
int n;

void update(int x, int val) {
	while(x <= MAXVAL) {
		tree[x] += val;
		x += (x & -x);
	}
}

int read(int x) {
	int sum = 0;
	while(x > 0) {
		sum += tree[x];
		x -= (x & -x);
	}
	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0 ,j = 0, count = 0;
	int x, y;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d%d", &x, &y);
		res[read(++x)]++;
		update(x, 1);
	}

	for(i = 0; i < n; ++i){
		printf("%d\n", res[i]);
	}
	getchar();getchar();
	return 0;
}

