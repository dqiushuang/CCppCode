// 2-�Ӽ���.cpp : M��������N��¥
//ȷ������һ�㼦�����ơ�
//dp[m][n] = min(dp[m][n], 1 + max(dp[m - 1][i - 1], dp[m][n - i])) i = 1...n
//���͵�DP����

#include "stdafx.h"
#include <iostream>
using namespace std;

#define N 100
#define M 100

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	int dp[M + 1][N + 1];  //��¼M��������N��¥�Ľ�
	memset(dp, 0, sizeof(dp));
	for(int i = 1;i <= N; ++i)   //1������
		dp[1][i] = i;

	for(int i = 2; i <= M; ++i){
		for(int j = 1; j <= N; ++j) {
			int min = 0x0FFFFFFF;
			for(int k = 1; k <= j; ++k){
				if(min > 1 + max(dp[i - 1][ k - 1], dp[i][ j - k]))
					min = 1 + max(dp[i - 1][ k - 1], dp[i][ j - k]);
			}
			dp[i][j] = min;
		}
	}

	cout <<dp[2][100];
	system("pause");
	return 0;
}

