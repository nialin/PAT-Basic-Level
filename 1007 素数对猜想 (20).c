#include <stdio.h>

int is_prime(int n)
{
	int i;

	for(i = 3; i * i <= n; i += 2)
		if(0 == n % i)
			return 0;

	return 1;
}

int main()
{
	int i, n, last, cnt;

	scanf("%d", &n);

	for(i = 3, last = 2, cnt = 0; i <= n; i += 2) {
		if(is_prime(i)) {
			if(2 == i - last)
				++cnt;

			last = i;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
