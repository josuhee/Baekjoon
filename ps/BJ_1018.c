//[백준] 1018 : 체스판 다시 칠하기

#include <stdio.h>
#define MIN(a, b) a<b?a:b

int main()
{
	int n, m, result;
	char map[51][51];

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);

	int black, white;
	result = 50;
	for (int i = 0; i < n - 7; i++)
	{
		for (int j = 0; j < m - 7; j++)
		{
			black = white = 0;
			// search
			for (int k = i; k < i + 8; k++)
			{
				for (int l = j; l < j + 8; l++)
				{
					if ((k + l) % 2)
					{
						if (map[k][l] == 'B')
							black++;
						if (map[k][l] == 'W')
							white++;
					}
					else
					{
						if (map[k][l] == 'B')
							white++;
						if (map[k][l] == 'W')
							black++;
					}
				}
			}
			// update
			result = MIN(result, black);
			result = MIN(result, white);
		}
	}
	printf("%d\n", result);
	return 0;
}