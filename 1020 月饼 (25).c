#include <stdio.h>
#include <stdlib.h>

struct mooncake {
	float unit, stock, total_price;
};

int cmp(const void *a, const void *b)
{
	if(*(float *)b > *(float *)a)
		return 1;

	return -1;
}

int main()
{
	float max = 0.0;
	int i, n, need;
	struct mooncake cakes[1000];

	scanf("%d%d", &n, &need);

	for(i = 0; i < n; ++i)
		scanf("%f", &cakes[i].stock);

	for(i = 0; i < n; ++i) {
		scanf("%f", &cakes[i].total_price);

		cakes[i].unit = cakes[i].total_price / cakes[i].stock;
	}

	qsort(cakes, n, sizeof(struct mooncake), cmp);

	for(i = 0; i < n; ++i) {
		if(need >= cakes[i].stock) {
			max += cakes[i].total_price;
			need -= (int)cakes[i].stock;
		}
		else {
			max += cakes[i].unit * need;
			break;
		}
	}

	printf("%.2f\n", max);

	return 0;
}
