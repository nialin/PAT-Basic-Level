#include <stdio.h>

int main()
{
	int i, n, top, stack[3];

	scanf("%d", &n);

	for(top = 0; n; n /= 10)
		stack[top++] = n % 10;

	if(3 == top)
		for(i = 0, --top; i < stack[top]; ++i)
			printf("B");

	if(2 == top)
		for(i = 0, --top; i < stack[top]; ++i)
			printf("S");

	if(1 == top)
		for(i = 0, --top; i < stack[top]; ++i)
			printf("%d", i + 1);

	printf("\n");

	return 0;
}
