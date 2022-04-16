#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

char str[31][22];

int arr[31];

int main(void)
{
	int T,N;
	int index;
	char tmp[22],name[22];
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		for (int x = 0; x < 32; x++)
			arr[x] = 1;
		index = 0;
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			int aa = 1;
			scanf("%s %s", tmp,name);
			if (j == 0)
			{
				strcpy(str[index], name);
				index++;
			}
			else
			{
				for (int k = 0; k < index; k++)
				{
					if (!strcmp(str[k], name))
					{
						arr[k]++;
						aa = 0;
						break;
					}
				}
				if (aa == 1)
				{
					strcpy(str[index], name);
					index++;
				}
			}
		}
		int sum = 1;
		for (int j = 0; j < index; j++)
		{
			sum *= (arr[j] + 1);
		}
		sum--;
		printf("%d\n", sum);
	}
	return 0;
}