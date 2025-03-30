#include <stdio.h>

int find_gcd(int a, int b)
{
	if (a == 0) {
		return b;
	}

	return find_gcd(b % a, a);
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	int gcd = find_gcd(a, b);
	int lcm = a * b / gcd;

	printf("%d\n", gcd);
	printf("%d\n", lcm);
}
