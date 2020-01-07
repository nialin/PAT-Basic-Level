#include <stdio.h>

int main()
{
	int i, sum, stack[4];
	char str[101] = {0};
	const char *map[] = {
		"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
	};

	scanf("%s", str);

	for(i = 0, sum = 0; str[i] != '\0'; ++i)
		sum += str[i] - '0';

	for(i = 0; sum; sum /= 10)
		stack[i++] = sum % 10;

	if(0 == i)
		printf("%s", map[0]);

	for( ; i; ) {
		printf("%s", map[stack[--i]]);
		printf("%s", i ? " " : "");
	}

	printf("\n");

	return 0;
}
