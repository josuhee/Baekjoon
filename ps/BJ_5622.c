//[백준] 5622 : 다이얼

#include <stdio.h>

int main()
{
	char str[20];
	int sum = 0;

	scanf("%s", str);
	for (int i =0; str[i];i++)
	{
		if (str[i] == 'Z')
			sum += 10;
		else if (str[i] == 'S')
			sum += 8;
		else if (str[i] >= 'T')
			sum += (str[i] - 'A' - 1) / 3 + 3;
		else
			sum +=(str[i] - 'A') / 3 + 3;
	}
	printf("%d\n", sum);
	return (0);
}