#include <stdio.h>

int main()
{
	int i, cnt = 0, map[6] = {0};
	char ch, *str = "PATest";

	while(scanf("%c", &ch) != EOF && ch != '\n') {
		for(i = 0; str[i] && ch != str[i]; ++i)
			;

		if(str[i]) {
			++map[i];
			++cnt;
		}
	}

	while(cnt)
		for(i = 0; i < 6; ++i)
			if(map[i]) {
				printf("%c", str[i]);
				--map[i];
				--cnt;
			}

	printf("\n");

	return 0;
}
