#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void) 
{
	int len, i, max, temp, same, max_c = 0;
	char arr[1000000];
	int alpha[26] = { 0 };
	scanf("%s", &arr);
	len = strlen(arr);
	for (i = 0; i < len; i++)
	{
		temp = toupper(arr[i]) - 'A';
		alpha[temp]++;
	}
	max = 0;
	for (i = 0; i < 26; i++)
	{
		
		if (alpha[i] > max)
		{
			max = alpha[i];
			max_c = i;
			same = 0;
		}
		else if (alpha[i] == max)
			same = 1;
	}
	if (same == 1)
		printf("?\n");
	else
		printf("%c\n", max_c + 'A');
}
