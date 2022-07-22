#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void) 
{
	int ntest, n, len, j, i;
	char r[20];
	scanf("%d", &ntest);

	while (ntest--)
	{
		scanf("%1d ", &n);
		scanf("%s", &r);
		len = strlen(r);
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < n; j++)
			{
				printf("%c", r[i]);
			}
		}
		printf("\n");
	}
}