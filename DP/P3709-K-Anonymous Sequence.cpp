// POJ 3709-K-Anonymous Sequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define N 500005

__int64 a[N], q[N];
__int64 sum[N], dp[N];
int t, n, k;

__int64 gr(int i) {
	return dp[i] - sum[i] + a[i + 1] * i;
}

bool comp(int j, int k, int i) {
	return gr(j) - gr(k) >= i * (a[j + 1] - a[k + 1]);
}

int _tmain(int argc, _TCHAR* argv[])
{
	cin >>t;
	while(t--) {
		cin >>n >>k;
		a[0] = 0;
		sum[0] = 0;
		for(int i = 1; i <= n; ++i){
			cin >>a[i];
			sum[i] = sum[i - 1] + a[i];
			dp[i] = ~0>>2;
		}

		q[0] = 0, dp[0] = 0;
		int head = 0, tail = 0;
		for(int i = 1; i <= n; ++i) {
			while(tail > head && comp(q[head], q[head + 1], i))
				head++;

			dp[i] = dp[q[head]] + sum[i] - sum[q[head]] - a[q[head] + 1] * (i - q[head]);

			int p = i - k + 1;
			if(p >= k) {
				while(head < tail && 
					(gr(q[tail - 1]) - gr(q[tail])) * (a[q[tail] + 1] - a[p + 1]) >= (gr(q[tail]) - gr(p)) * (a[q[tail - 1] + 1] - a[q[tail] + 1]))
					tail--;
				
				q[++tail] = p;
			}
		}
		cout <<dp[n];
		if(t != 0)
			cout <<endl;
	}
	system("pause");
 	return 0;
}

