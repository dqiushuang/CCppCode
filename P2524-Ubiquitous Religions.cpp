//union search set  --just translate from chinese (bing cha ji)

#include <stdio.h>
int n,m,k;
int f[50005],ran[50005];

void makeset(int n)
{
	for(int i = 1; i <= n; ++i)
	{
		f[i] = i;
		ran[i] = 1;
	}
}


int findF(int x)
{
	if(f[x] != x)
		f[x] = findF(f[x]);

	return f[x];
}

void unionSet(int x, int y)
{
	x = findF(x);
	y = findF(y);
	if(x == y)
		return;

	f[y] = x;
	--n;
}

int main(int argc, _TCHAR* argv[])
{
	int k = 1;
	while(scanf("%d %d",&n,&m)!=EOF, n != 0)
	{
		makeset(n);
		for(int i = 0; i < m; ++i)
		{
			int x,y;
			scanf("%d %d", &x, &y);
			unionSet(x, y);
		}
		printf("Case %d: %d\n", k++, n);
	}
	return 0;
}

