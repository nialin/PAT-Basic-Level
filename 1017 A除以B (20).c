#include <stdio.h>

int main()
{
	char ca[1001];
	int i, ia[1000], b, q, r, cnt;

	scanf("%s%d", ca, &b);

	for(cnt = 0; ca[cnt]; ++cnt)
		ia[cnt] = ca[cnt] - '0';

	for(i = 0, r = 0; i < cnt; ++i) {
		q = (ia[i] + r * 10) / b;
		r = (ia[i] + r * 10) % b;

		if(0 == i && 0 == q && cnt != 1)
			continue;

		printf("%d", q);
	}

	printf(" %d", r);

	return 0;
}
