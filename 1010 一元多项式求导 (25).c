#include <stdio.h>

int main()
{
	int coef, exp, high_exp;

	scanf("%d%d", &coef, &high_exp);

	if(high_exp)
		printf("%d %d", coef * (high_exp), high_exp - 1);
	else
		printf("0 0");

	while(scanf("%d%d", &coef, &exp) != EOF)
		if(exp)
			printf(" %d %d", coef * exp, exp - 1);

	printf("\n");

	return 0;
}
