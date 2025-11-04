#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
	int N;
	char str[60];
	int count;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		count = 0;
		scanf("%s", str);
		for (int j = 0; j < strlen(str); j++)
		{
			if (str[j] == '(')
				count++;
			else if(str[j]==')')
				count--;
			if (count < 0)
				break;
		}
		if (count==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}