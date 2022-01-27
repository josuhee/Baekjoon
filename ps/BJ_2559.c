//[백준] 2559 : 수열

#include <stdio.h>
#define MAX(a,b) a>b?a:b

int num[100001];

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	
	int sum = 0, max;
	for (int i = 0; i < k; i++)
		sum += num[i];
	max = sum;
	for (int i = k; i < n; i++)
	{
		sum -= num[i - k];
		sum += num[i];
		max = MAX(max, sum);
	}
	printf("%d\n", max);
	return (0);
}