// 5-LIS.cpp : 定义控制台应用程序的入口点。
//use the state change function: dp[i] = max(dp[i], dp[j] + 1). a[j] < a[i] && j < i

#include <iostream>
using namespace std;

int a[1005];
int dp[1005];

int main()
{
	int n;
	cin >>n;
	for(int i = 0; i < n; ++i) {
		cin >>a[i];
		dp[i] = 1;
	}
	int len = 1;
	for(int i = 0; i < n; ++i) {
		int max = 0;
		for(int j = 0;j < i; ++j) {
			if(a[j] < a[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
		if(len < dp[i])
			len = dp[i];
	}
	
	cout <<len;
	
	return 0;
}

