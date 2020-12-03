#include <stdio.h>

int id_check(const char *id);

int id_check(const char *id)
{
	int i, weight, weights[17] = {
		7, 9, 10, 5, 8, 4, 2, 1,
		6, 3, 7, 9, 10, 5, 8, 4, 2 };
	const char map[12] = "10X98765432";

	for(i = 0, weight = 0; i < 17; ++i)
		weight += (id[i] - '0') * weights[i];

	return id[17] == map[weight % 11];
}

int main()
{
	int i, n, flg;
	char id[18] = {0};

	scanf("%d", &n);
	for(i = 0, flg = 1; i < n; ++i) {
		scanf("%s", id);

		if(!id_check(id)) {
			printf("%s\n", id);
			flg = 0;
		}
	}

	if(flg)
		printf("All passed\n");

	return 0;
}
