// P1180-Batch scheduling-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>

#define N 10005
#define INFI  ~0>>2
int t[N], f[N], sumt[N], sumf[N];
int dp[N], q[N];


int _tmain(int argc, _TCHAR* argv[])
{
	int n, s, i;
	int head = 0, tail = 0;
	scanf("%d%d", &n, &s);
	for(i = 1; i <= n; ++i)
		scanf("%d%d", &t[i], &f[i]);

	sumt[n + 1] = 0;
	sumf[n + 1] = 0;
	
	q[0] = n + 1;
	for(i = n; i > 0; --i) {
		sumt[i] = sumt[i + 1] + t[i];
		sumf[i] = sumf[i + 1] + f[i];
		while(tail > head && 
			((dp[q[head + 1]] - dp[q[head]]) < sumf[i] * (sumt[q[head + 1]] - sumt[q[head]]))  )
			head++;
		
		dp[i] =  dp[q[head]] + (sumt[i] - sumt[q[head]] + s) * sumf[i];

		while(tail > head &&
			(dp[q[tail]] - dp[q[tail - 1]]) * (sumt[i] - sumt[q[tail]]) > (sumt[q[tail]] - sumt[q[tail-1]]) * (dp[i] - dp[q[tail]]))
			tail--;

		q[++tail] = i;
	}

	printf("%d", dp[1]);
	return 0;
}

