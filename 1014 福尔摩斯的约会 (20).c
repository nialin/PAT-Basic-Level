#include <stdio.h>
#include <ctype.h>

int main()
{
	int i;
	char strs[4][61];
	const char *days[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

	scanf("%s%s%s%s", strs[0], strs[1], strs[2], strs[3]);

	for(i = 0; strs[0][i] && strs[1][i]; ++i) {
		if(strs[0][i] == strs[1][i] && strs[0][i] >= 'A' && strs[0][i] <= 'G') {
			printf("%s ", days[strs[0][i] - 'A']);

			break;
		}
	}

	for(++i; strs[0][i]; ++i) {
		if(strs[0][i] == strs[1][i] && ((strs[0][i] >= 'A' && strs[0][i] <= 'N') || isdigit(strs[0][i]))) {
			if(isdigit(strs[0][i]))
				printf("0%c:", strs[0][i]);
			else
				printf("%d:", strs[0][i] - 'A' + 10);

			break;
		}
	}

	for(i = 0; strs[2][i] != strs[3][i] || !isalpha(strs[2][i]); ++i)
		;

	printf("%02d\n", i);

	return 0;
}
