#include <stdio.h>

int main()
{
	int i, nums[10];

	for(i = 0; i < 10; ++i)
		scanf("%d", &nums[i]);

	for(i = 1; i < 10 && !nums[i]; ++i)
		;

	--nums[i];
	printf("%d", i);

	for(i = 0; i < 10; ++i) {
		while(nums[i]) {
			--nums[i];
			printf("%d", i);
		}
	}

	printf("\n");

	return 0;
}
