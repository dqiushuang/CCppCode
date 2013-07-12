// 1-循环左移.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int N;   //the length of array

void rotateleft(int *a, int n, int left) {
	int i, j, k, change;

	if(left >= n)
		left = left % n;
	if(left == 0)
		return ;

	for(i = 0; i + left < n; i += change) {
		if(i + 2 * left < n)
			change = left;
		else
			change = n -i - left;

		for(j = i; j < i + change; ++j) {
			a[j] = a[j] ^ a[j + left];
			a[j + left] = a[j] ^ a[j + left];
			a[j] = a[j] ^ a[j + left];
		}

		if(n - i == left + change) {
			k = (left - change) % left;
			if(k == 0)
				return ;
			left = k;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int left;  //rotate left 
	int a[] = {1, 2, 3, 4, 5, 6, 7};

	cin >>left;
		
	N = sizeof(a)/sizeof(int);

	rotateleft(a, N, left);

	for(int i = 0; i < N; ++i)
		cout <<a[i] <<"   ";
	cout <<endl;

	system("pause");
	return 0;
}

