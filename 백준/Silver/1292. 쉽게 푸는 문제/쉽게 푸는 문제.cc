#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int a = 1, b = 3, plus = 3;
    int start, end, result = 0;
    scanf("%d %d", &start, &end);

    if (start == 1)
    {
        result = 1;
        start++;
    }

    while (end >= start)
    {
        if (a < start && start <= b)
        {
            result += plus - 1;
            start++;
        }
        else
        {
            a = b;
            b += plus;
            plus++;
        }
    } 

    printf("%d", result);

}