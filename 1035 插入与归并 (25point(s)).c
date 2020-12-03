#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *is_insertion_sort(const int *nums, int n, const int *dest);

int cmp(const void *a, const void *b);
int *is_merge_sort(const int *nums, int n, const int *dest);

void list_show(const int *nums, int n);

int *is_insertion_sort(const int *nums, int n, const int *dest)
{
	int i, j, tmp, *buffer, flg = 0;

	if(!(buffer = malloc(n * sizeof(int))))
		exit(1);

	memcpy(buffer, nums, n * sizeof(int));

	for(i = 1; i < n; ++i) {
		for(j = i - 1, tmp = buffer[i]; j >= 0 && tmp < buffer[j]; --j)
			buffer[j + 1] = buffer[j];

		buffer[j + 1] = tmp;

		if(flg)
			return buffer;

		if(0 == memcmp(dest, buffer, n * sizeof(int)))
			flg = 1;
	}

	free(buffer);

	return NULL;
}

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int *is_merge_sort(const int *nums, int n, const int *dest)
{
	int i, j, *buffer, flg = 0;

	if(!(buffer = malloc(n * sizeof(int))))
		exit(1);

	memcpy(buffer, nums, n * sizeof(int));

	for(i = 2; i <= n; i *= 2) {
		for(j = 0; j < n; j += i)
			qsort((void *)&buffer[j], i < n - j ? i : n - j, sizeof(int), cmp);

		if(flg)
			return buffer;

		if(0 == memcmp(dest, buffer, n * sizeof(int)))
			flg = 1;
	}

	free(buffer);

	return NULL;
}

void list_show(const int *nums, int n)
{
	int i;

	for(i = 0; i < n; ++i)
		printf("%s%d", i ? " " : "", nums[i]);

	printf("\n");
}

int main()
{
	int i, n, nums[100], tar[100], *next;

	scanf("%d", &n);

	for(i = 0; i < n; ++i)
		scanf("%d", &nums[i]);

	for(i = 0; i < n; ++i)
		scanf("%d", &tar[i]);

	if(!(next = is_insertion_sort(nums, n, tar))){
		next = is_merge_sort(nums, n, tar);

		printf("Merge Sort\n");
	}
	else
		printf("Insertion Sort\n");

	list_show(next, n);

	free(next);

	return 0;
}
