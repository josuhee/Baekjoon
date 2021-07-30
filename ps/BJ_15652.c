//[백준] 15652 : N과 M (4)

#include <stdio.h>

int n, m;
int arr[10];

void print_num()
{
	for (int i = 0; i < m; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void func(int num, int cnt)
{
	if (cnt == m)
	{
		print_num();
		return;
	}
	for (int i = num; i <= n; i++)
	{
		arr[cnt] = i;
		func(i, cnt + 1);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	func(1, 0);
}