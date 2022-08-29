#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_prime(int n)
{
	if (n <= 1)
		return 0;

	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return 0;
	}

	return 1;
}

int main(void)
{
	int m, n, min = 0, sum = 0;
	scanf("%d", &m);
	scanf("%d", &n);

	for (int i = m; i <= n; i++)
	{
		if (is_prime(i)) 
		{
			if (min == 0)
				min = i;
			sum += i;
		}		
	}

	if (min == 0)
		printf("-1\n");
	else
		printf("%d\n%d\n", sum, min);
}