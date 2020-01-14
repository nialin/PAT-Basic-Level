#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int i, n, tmp, num[101], par[10000], flg = 0;

	memset(par, -1, 10000 * sizeof(int));

	scanf("%d", &n);

	for(i = 0; i < n; ++i) {
		scanf("%d", &num[i]);

		for(tmp = num[i]; tmp != 1; ) {
			if(tmp % 2) {
				par[(tmp * 3 + 1) / 2] = tmp;

				tmp = (tmp * 3 + 1) / 2;
			}
			else {
				par[tmp / 2] = tmp;

				tmp = tmp / 2;
			}
		}
	}

	qsort(num, n, sizeof(int), cmp);

	for(i = n - 1; i >= 0; --i)
		if(-1 == par[num[i]])
			printf("%s%d", flg++ ? " " : "", num[i]);

	printf("\n");

	return 0;
}
