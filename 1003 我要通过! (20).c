#include <stdio.h>

int is_right()
{
	int a, b, c, i;
	char str[101] = {0};

	scanf("%s", str);

	for(a = 0, i = 0; str[i] != 'P' && str[i]; ++i)
		if('A' == str[i])
			++a;
		else
			return 0;

	if(!str[i])
		return 0;

	for(b = 0, ++i; str[i] != 'T' && str[i]; ++i)
		if('A' == str[i])
			++b;
		else
			return 0;

	if(!str[i])
		return 0;

	for(c = 0, ++i; str[i]; ++i)
		if('A' == str[i])
			++c;
		else
			return 0;

	return b ? c == a * b : 0;
}

int main()
{
	int n, i;

	scanf("%d", &n);

	getchar();

	for(i = 0; i < n; ++i)
		printf("%s\n", is_right() ? "YES" : "NO");

	return 0;
}
