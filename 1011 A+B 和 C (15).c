#include <stdio.h>

int main()
{
	int i, n;
	long long a, b, c;

	scanf("%d", &n);

	for(i = 1; i <= n; ++i) {
		scanf("%lld%lld%lld", &a, &b, &c);

		printf("Case #%d: %s\n", i, a > c - b ? "true" : "false");
	}

	return 0;
}
