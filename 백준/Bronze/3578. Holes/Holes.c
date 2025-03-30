#include <stdio.h>

void solve(int n)
{
	if (n <= 1) {
		printf("%d", !n);
		return;
	}

	if (n & 1) {
		printf("4");
		n--;
	}

	for (int i = 0; i < n / 2; i++) {
		printf("8");
	}
} 

int main()
{
	int n;
	scanf("%d", &n);
	solve(n);
}
