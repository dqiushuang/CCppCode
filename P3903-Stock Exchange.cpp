// longest orderest subsequence

#include <stdio.h>

int n;
long num[100005];
long m[100005];

int main(int argc, _TCHAR* argv[])
{
	while(scanf("%d",&n) != EOF)
	{
		scanf("%ld", &num[0]);
		int len = 0;
		m[0] = num[0];
		for(int i = 1; i < n; ++i)
		{
			scanf("%ld", &num[i]);

			int low = 0;
			int high = len;
			while(low < high)
			{
				int mid = (low + high)/2;
				if(m[mid] < num[i])
					low = mid + 1;
				else
					high = mid;
			}
			m[low] = num[i];
			if(low == len)
				len++;
		}
		if(n == 1)
			len = 1;
		printf("%d\n",len);
	}

	return 0;
}

