#include <stdio.h>

int main()
{
	int a, b, d, stack[32], top;

	scanf("%d%d%d",&a, &b, &d);

	if(0 == a + b)
		printf("0");

	for(a += b, top = 0; a; ) {
		stack[top++] = a % d;
		a /= d;
	}

	while(top)
		printf("%d", stack[--top]);

	printf("\n");

	return 0;
}
