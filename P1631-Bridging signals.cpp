/*longest ordered subsequence*/
#include <iostream>
using namespace std;

int n,p;
int num[40005];
int m[40005];

int main(int argc, _TCHAR* argv[])
{
	cin >>n;
	while(n--)
	{
		int len = 1;
		cin >>p >>num[0];
		m[0] = num[0];

		for(int i = 1; i < p; ++i)
		{
			cin >>num[i];

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
		cout <<len <<endl;
	}
	return 0;
}

