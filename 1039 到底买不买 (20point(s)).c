#include <stdio.h>

int main()
{
	char str[100001];
	int i, remain, lack, src[128] = {0}, dest[128] = {0};

	for(i = 0, scanf("%s", str); str[i]; ++i)
		++src[str[i]];

	for(i = 0, scanf("%s", str); str[i]; ++i)
		++dest[str[i]];

	for(i = 0, remain = lack = 0; i < 128; ++i) {
		if(dest[i] <= src[i])
			remain += src[i] - dest[i];
		else
			lack += dest[i] - src[i];
	}

	if(lack > 0)
		printf("No %d\n", lack);
	else
		printf("Yes %d\n", remain);

	return 0;
}
