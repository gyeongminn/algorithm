#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void) 
{
	int i, len, find;
	char j, s[100];
	int n[100];
	scanf("%s", &s);
	len = strlen(s);
	for (j = 'a'; j <= 'z'; j++)
	{
		find = 0;
		for (i = 0; i < len; i++)
		{
			if (s[i] == j)
			{
				printf("%d ", i);
				find = 1;
				break;
			}
		}
		if (find == 0)
			printf("-1 ");
	}
}