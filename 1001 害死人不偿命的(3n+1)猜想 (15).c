#include <stdio.h>

int main()
{
	int n, cnt;

	scanf("%d", &n);

	for(cnt = 0; n != 1; ++cnt) {
		if(n % 2)
			n = 3 * n + 1;
		n /= 2;
	}

	printf("%d\n", cnt);

	return 0;
}
