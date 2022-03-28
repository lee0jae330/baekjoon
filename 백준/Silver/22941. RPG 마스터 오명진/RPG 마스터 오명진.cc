#include<stdio.h>

int main(void) {
	long long hp1, atk1, hp2, atk2;
	scanf("%lld %lld %lld %lld", &hp1, &atk1, &hp2, &atk2);
	long long P, S;
	scanf("%lld %lld", &P, &S);
	long long knight = hp2 / atk1;
	if (hp2 % atk1)
		knight++;
	long long devil = hp1 / atk2;
	if (hp1 % atk2)
		devil++;
	if (knight > devil)
		printf("gg\n");
	else {
		int ishealed = 0;
		if (hp2 % atk1 == 0) {
			long long n = hp2 / atk1;
			if (n > 1 && P >= atk1)
				ishealed = 1;
		}
		else {
			if (hp2 % atk1 <= P)
				ishealed = 1;
		}
		if (ishealed) {
			long long before = hp2 - P;
			long long num = before / atk1;
			if (before % atk1)
				num++;
			long long after = hp2 - num * atk1 + S;
			long long tmp = after / atk1;
			if (after % atk1)
				tmp++;
			long long result = num + tmp;
			if (result > devil)
				printf("gg\n");
			else
				printf("Victory!\n");
		}
		else
			printf("Victory!\n");
	}
	return 0;
}