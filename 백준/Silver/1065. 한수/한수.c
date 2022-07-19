#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, j, n, nlist[3], num = 0;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		if (i < 100)
			num++;

		else if (i == 1000)
			break;

		else if (i > 110)
		{
			nlist[0] = i % 1000 / 100;
			nlist[1] = i % 100 / 10;
			nlist[2] = i % 10;
			for (j = 0; j < 5; j++)
			{
				if (nlist[0] + j == nlist[1])
				{
					if (nlist[1] + j == nlist[2]) 
					{
						num++;
						break;
					}
						
				}
				else if (nlist[0] - j == nlist[1])
				{
					if (nlist[1] - j == nlist[2])
					{
						num++;
						break;
					}
				}
			}
		}
	}
	printf("%d\n", num);
}