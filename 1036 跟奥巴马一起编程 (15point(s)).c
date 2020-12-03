#include <stdio.h>

int main()
{
	int i, n, row_cnt;
	char ch, tmp_1[21] = {0}, tmp_2[21] = {0};

	scanf("%d %c", &n, &ch);

	for(i = 0; i < n; ++i) {
		tmp_1[i] = ch;
		tmp_2[i] = ' ';
	}

	tmp_2[0] = tmp_2[n - 1] = ch;

	printf("%s\n", tmp_1);

	for(i = 1, row_cnt = (n + 1) / 2; i < row_cnt - 1; ++i)
		printf("%s\n", tmp_2);

	printf("%s\n", tmp_1);

	return 0;
}
