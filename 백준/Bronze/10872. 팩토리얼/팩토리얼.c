#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int n)
{
	if (n == 0)
		return 1;
	if (n <= 1)
		return n;
	return factorial(n - 1) * n;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", factorial(n));
}