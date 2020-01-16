#include <stdio.h>

int main()
{
	int i, cnts[10] = {0};
	char num[1001];

	scanf("%s", num);

	for(i = 0; num[i]; ++i)
		++cnts[num[i] - '0'];

	for(i = 0; i < 10; ++i)
		if(cnts[i])
			printf("%d:%d\n", i, cnts[i]);

	return 0;
}
