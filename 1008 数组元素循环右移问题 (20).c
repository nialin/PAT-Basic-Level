#include <stdio.h>

void arr_reverse(int *a, int n)
{
	int i, tmp;

	for(i = 0; i < n / 2; ++i) {
		tmp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = tmp;
	}
}

int main()
{
	int i, m, n, a[100] = {0};

	scanf("%d%d", &n, &m);

	for(i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	m %= n;

	arr_reverse(a, n - m);
	arr_reverse(a + n - m, m);
	arr_reverse(a, n);

	for(i = 0; i < n; ++i)
		printf("%s%d", i ? " " : "", a[i]);

	printf("\n");

	return 0;
}
