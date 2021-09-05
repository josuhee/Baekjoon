//[백준] 1929 : 소수 구하기

#include <stdio.h>

int ft_is_prime(int nb)
{
	long long i;

	i = 5;
	if (nb <= 1)
		return (0);
	if (nb <= 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i++;
	}
	return (1);
}

int main()
{
	int N, M;

	scanf("%d %d", &M, &N);

	for (int i = M; i <= N; i++)
	{
		if (ft_is_prime(i))
			printf("%d\n", i);
	}

	return (0);
}