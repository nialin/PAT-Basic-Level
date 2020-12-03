#include <stdio.h>
#include <stdlib.h>

int sort_cmp(const void *a, const void *b);
int binsearch(long long *nums, int cnt, long long n);

int sort_cmp(const void *a, const void *b)
{
	return *(long long *)a - *(long long *)b;
}

int binsearch(long long *nums, int cnt, long long n)
{
	int low = 0, mid, high = cnt - 1;

	while(low <= high) {
		mid = (low + high) / 2;

		if(n >= nums[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}

	return high;
}

int main()
{
	int i, j, n, p, delta;
	long long nums[100000] = {0};

	scanf("%d%d", &n, &p);

	for(i = 0; i < n; ++i)
		scanf("%lld", &nums[i]);

	qsort(nums, n, sizeof(long long), sort_cmp);

	for(i = j = 0, delta = 0; i < n; ++i) {
		j = binsearch(nums, n, nums[i] * p);

		if(delta < j - i)
			delta = j - i;
	}

	printf("%d\n", delta + 1);

	return 0;
}
