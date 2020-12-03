#include <stdio.h>

int search(int *arr, int n, int i)
{
	int low = 0, high = n - 1, mid;

	while(low <= high) {
		mid = (low + high) / 2;

		if(arr[mid] <= i && arr[mid + 1] > i)
			return mid;

		if(arr[mid] < i)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return -1;
}

int main()
{
	char ch;
	int n, i, j, costs[500] = {1}, pos;

	for(i = 1; i < 500; ++i)
		costs[i] += costs[i - 1] + (i * 2 + 1) * 2;

	scanf("%d %c", &n, &ch);

	pos = search(costs, 500, n);

	for(i = pos; i; --i) {
		for(j = 0; j < pos - i; ++j)
			printf(" ");

		for(j = 0; j < i * 2 + 1; ++j)
			printf("%c", ch);

		printf("\n");
	}

	for(i = 0; i <= pos; ++i) {
		for(j = 0; j < pos - i; ++j)
			printf(" ");

		for(j = 0; j < i * 2 + 1; ++j)
			printf("%c", ch);

		printf("\n");
	}

	printf("%d\n", n - costs[pos]);

	return 0;
}
