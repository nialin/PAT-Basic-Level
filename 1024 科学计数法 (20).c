#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char num[10000];
	int i, exp, exp_flg = 1;

	scanf("%s", num);

	for(i = 0; num[i] != 'E'; ++i)
		;

	num[i] = 0;

	if('-' == num[++i])
		exp_flg = -1;

	exp = atoi(&num[++i]) * exp_flg;

	if('-' == num[0])
		printf("-");

	if(0 == exp)
		printf("%s", &num[1]);
	else if(exp > 0) {
		for(i = 1; num[i] && i <= exp + 2; ++i)
			if(isdigit(num[i]))
				printf("%c", num[i]);

		if(0 == num[i])
			for( ; i <= exp + 2; ++i)
				printf("0");
		else
			printf(".%s", &num[i]);
	}
	else {
		printf("0.");

		for(i = 0; i < -exp - 1; ++i)
			printf("0");

		for(i = 1; num[i]; ++i)
			if(isdigit(num[i]))
				printf("%c", num[i]);
	}

	return 0;
}
