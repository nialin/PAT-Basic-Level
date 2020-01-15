#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int i, arr[4], num, num_1, num_2;

	scanf("%d", &num);

	do {
		for(i = 0; i < 4; ++i, num /= 10)
			arr[i] = num % 10;

		qsort(arr, 4, sizeof(int), cmp);

		num_1 = (((arr[0] * 10 + arr[1]) * 10) + arr[2]) * 10 + arr[3];
		num_2 = (((arr[3] * 10 + arr[2]) * 10) + arr[1]) * 10 + arr[0];
		printf("%04d - %04d = %04d\n", num_1, num_2, num = num_1 -num_2);
	} while(num != 6174 && num);

	return 0;
}
