#include <stdio.h>

void merge_into_primes(int *primes, int *cnt, int n)
{
	int i;

	for(i = 0; i < *cnt && n % primes[i] && primes[i] * primes[i] <= n; ++i)
		;

	if(n % primes[i])
		primes[(*cnt)++] = n;
}

int main()
{
	int i, cnt, primes[10000] = {2}, m, n;

	for(cnt = 1, i = 3; cnt < 10000; i += 2)
		merge_into_primes(primes, &cnt, i);

	scanf("%d%d", &m, &n);

	for(i = m - 1; i < n; ++i) {
		if((i - (m - 1)) % 10)
			printf(" ");

		printf("%d", primes[i]);

		if(9 == (i - (m - 1)) % 10)
			printf("\n");
	}

	return 0;
}
