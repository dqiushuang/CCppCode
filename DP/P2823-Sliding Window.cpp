// P2823-Sliding Window.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>

#define N 1000005

int a[N], qmin[N], qmax[N];
int minv[N], maxv[N];

int _tmain(int argc, _TCHAR* argv[])
{
	int n, k;
	int i;
	int headqmin = 0, tailqmin = 0;
	int headqmax = 0, tailqmax = 0;
	scanf("%d%d", &n, &k);
	for(i = 0;i < n; ++i) {
		scanf("%d", &a[i]);
	}
	
	qmin[0] = 0, qmax[0] = 0;
	minv[0] = a[0], maxv[0] = a[0];

	for(i = 1; i < n; ++i) {
		while(headqmin <= tailqmin && a[qmin[tailqmin]] > a[i])
			tailqmin--;
		qmin[++tailqmin] = i;

		while(headqmin <= tailqmin && qmin[tailqmin] - qmin[headqmin] >= k)
			headqmin++;
		
		minv[i] = a[qmin[headqmin]];
		
		while(headqmax <= tailqmax && a[qmax[tailqmax]] < a[i])
			tailqmax--;

		qmax[++tailqmax] = i;

		while(headqmax <= tailqmax && qmax[tailqmax] - qmax[headqmax] >= k)
			headqmax++;
		
		maxv[i] = a[qmax[headqmax]];
	}

	for(i = k - 1; i < n; ++i) {
		printf("%d", minv[i]);
		if(i < n -1)
			printf(" ");
	}
	printf("\n");
	for( i = k - 1; i < n; ++i) {
		printf("%d", maxv[i]);
		if(i < n - 1)
			printf(" ");
	}	

	getchar();
	getchar();
	return 0;
}

