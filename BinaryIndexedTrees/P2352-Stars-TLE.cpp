// P2325-Stars.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>

#define N 15005
int x[N], y[N];
int res[N];
int n;

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0 ,j = 0, count = 0;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
	}

	//memset(res, 0, sizeof(res));

	res[0] = 1;
	for(i = 1; i < n; ++i) {
		count = 0;
		for(j = 0; j < i; ++j) {
			if(x[j] <= x[i])
				count++;
		}		
		res[count]++;
	}

	for(i = 0; i < n; ++i){
		printf("%d\n", res[i]);
	}
	return 0;
}

