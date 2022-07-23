#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int reverse_num(int num)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		num = num % 10 * 100 + num % 100 / 10 * 10 + num / 100;
	}
	return num;
}

int main()
{
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	if (reverse_num(n1) > reverse_num(n2))
		printf("%d", reverse_num(n1));
	else
		printf("%d", reverse_num(n2));
}