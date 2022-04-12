#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char words[20000][51];
int compare(const void* a, const void* b)
{
	int a_len;
	int b_len;
	a_len=strlen((char*) a);
	b_len = strlen((char *)b);
	if (a_len == b_len)
		return strcmp((char *)a, (char*)b);
	else if (a_len > b_len)
		return 1;
	else
		return -1;
}
int main(void)
{
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", words[i]);
		getchar();
	}
	char str[51]="";
	qsort(words, n, sizeof(words[0]), compare);
	for (int i = 0; i < n; i++)
	{
		if (!strcmp(words[i], words[i + 1]))
			continue;
		else
			printf("%s\n", words[i]);
	}
	return 0;
}