#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char arr[25][25];
int visit[25][25] = { 0 };
int x, y;
int step=0;
int R[4] = { -1,0,1,0 };
int L[4] = { 0,1,0,-1 };

int Judge(int x1, int y1)
{
	return x1 < x && y1 < y && x1 >= 0 && y1 >= 0;
}
void dfs(int x1,int y1)
{
	step++;
	visit[x1][y1] = 1;

	for (int i = 0; i < 4; i++) 
	{
		int m = x1 + R[i];
		int n = y1 + L[i];
		if (visit[m][n] == 0 && arr[m][n] == '.' && Judge(m , n))
		{
			dfs(m, n);
		}
	}
	
}

int main()
{
	int i1=0, j1=0;

	scanf("%d%d", &y, &x);

	for (int i = 0; i < x; i++)
	{
		scanf("%s", arr[i]);
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (arr[i][j] == '@')
			{
				i1 = i;
				j1 = j;
			}
		}
	}

	dfs(i1,j1);
	
	printf("%d", step);

	return 0;
}
