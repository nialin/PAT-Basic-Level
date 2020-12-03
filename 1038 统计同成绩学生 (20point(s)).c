#include <stdio.h>

int main()
{
	int i, n, k, score, map[101] = {0};

	for(i = 0, scanf("%d", &n); i < n; ++i) {
		scanf("%d", &score);
		++map[score];
	}

	for(i = 0, scanf("%d", & k); i < k; ++i) {
		scanf("%d", &score);
		printf("%s%d", i ? " " : "", map[score]);
	}

	printf("\n");

	return 0;
}
