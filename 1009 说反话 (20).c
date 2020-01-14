#include <stdio.h>

int main()
{
	int top;
	char stack[40][41] = {{0}};

	for(top = 0; scanf("%s", stack[top]) != EOF; ++top)
		;

	while(top) {
		printf("%s", stack[--top]);
		printf("%s", top ? " " : "");
	}

	printf("\n");

	return 0;
}
