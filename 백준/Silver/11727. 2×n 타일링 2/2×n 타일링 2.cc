#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[1001];

int main(void)
{
    arr[0]=1;
    arr[1]=3;
    for(int i=2;i<1001;i++)
    {
        arr[i]=(arr[i-1]+arr[i-2]+arr[i-2])%10007;
    }
    int n;
    scanf("%d",&n);
    printf("%d\n",arr[n-1]%10007);
    return 0;
}