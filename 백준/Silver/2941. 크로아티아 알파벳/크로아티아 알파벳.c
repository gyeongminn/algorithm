#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int sum;
	char arr[100];
	scanf("%s", &arr);
	sum = strlen(arr);
	for (int i = 0; i < strlen(arr); i++)
	{
		if ((arr[i] == 'l' || arr[i] == 'n') && arr[i + 1] == 'j') sum--; 
		if (arr[i] == 'd' && arr[i + 1] == 'z' && arr[i + 2] == '=') sum--; 
		if (arr[i] == '=' || arr[i] == '-') sum--;
	}
	printf("%d", sum);
}