//union search set  --just translate from chinese (bing cha ji)

#include <iostream>
using namespace std;
int ranka[30001];
int father[30001];

void makeset(int n)
{
	for(int i = 0; i < n ; ++i)
	{
		father[i] = i;
		ranka[i] = 1;
	}
}

int find_father(int x)
{
	if(father[x] != x)
		father[x] = find_father(father[x]);

	return father[x];
}

void union_set(int a, int b)
{
	int x = find_father(a);
	int y = find_father(b);
	if(x == y)
		return;

	if(ranka[x] >= ranka[y])
	{
		father[y] = x;
		ranka[x] += ranka[y];
	}
	else
	{
		father[x] = y;
		ranka[y] += ranka[x];
	}
}

int main(int argc, _TCHAR* argv[])
{
	int n,m,k,f;
	while(cin >>n >>m, n != 0)
	{
		makeset(n);

		for(int i = 0; i < m; ++i)
		{
			cin >>k >>f;
			int t;
			for(int j = 1; j < k; ++j)
			{
				cin >>t;
				union_set(f, t);
			}
		}

		cout <<ranka[find_father(0)] <<endl;
	}
	return 0;
}

