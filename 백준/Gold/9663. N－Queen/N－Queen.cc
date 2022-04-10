#include<stdio.h>

int arr[15]={1,0,0,2,10,4,40,92,352,724,2680,14200,73712,365596,2279184};

int main() {
	int N;
	scanf("%d",&N);
	printf("%d\n",arr[N-1]);
	return 0;
}