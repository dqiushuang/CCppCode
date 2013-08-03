// P3264-Balanced Lineup.cpp : 定义控制台应用程序的入口点。
//This problem is TLE if using cin and cout, but ac while changing to scanf and printf.

#include "stdafx.h"
#include <stdio.h>

#define N 50005
#define Q 200005

int n, q;
int a[N], mini[4 * N], maxi[4 * N];

void init(int node, int l, int r) {
	if(l == r) {
		mini[node] = l;
		maxi[node] = l;
	} else {
		init(2 * node, l, (l + r)/2);
		init(2 * node + 1, (l + r)/2 + 1, r);

		if(a[mini[2 * node]] <= a[mini[2 * node + 1]])
			mini[node] = mini[2 * node];
		else 
			mini[node] = mini[2 * node + 1];

		if(a[maxi[2 * node]] >= a[maxi[2 * node + 1]])
			maxi[node] = maxi[2 * node];
		else 
			maxi[node] = maxi[2 * node + 1];
	}
}

int minquery(int node, int l, int r, int i, int j){
	int p1, p2;
	if(i > r || j < l)
		return -1;

	if(l >= i && r <= j)
		return mini[node];

	p1 = minquery(2 * node, l, (l + r)/2, i, j);
	p2 = minquery(2 *  node + 1, (l + r)/2 + 1, r, i, j);

	if(p1 == -1)
		return p2;
	if(p2 == -1)
		return p1;
	if(a[p1] <= a[p2])
		return p1;
	return p2; 
}

int maxquery(int node, int l, int r, int i, int j){
	int p1, p2;
	if(i > r || j < l)
		return -1;

	if(l >= i && r <= j)
		return maxi[node];

	p1 = maxquery(2 * node, l, (l + r)/2, i, j);
	p2 = maxquery(2 *  node + 1, (l + r)/2 + 1, r, i, j);

	if(p1 == -1)
		return p2;
	if(p2 == -1)
		return  p1;
	if(a[p1] >= a[p2])
		return p1;
	return p2; 
}

int _tmain(int argc, _TCHAR* argv[])
{
	while(scanf("%d%d", &n, &q) != EOF) {
		for(int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		init(1, 1, n);
		for(int i = 0; i < q; ++i) {
			
			int j, k;
			scanf("%d%d", &j, &k);
			printf("%d\n", a[maxquery(1, 1, n, j, k)] - a[minquery(1, 1, n, j, k)]);
		}
	}
	return 0;
}

