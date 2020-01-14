#include <stdio.h>

int main()
{
	long long pa, pb;
	int i, cnt_a, cnt_b;
	char a[11], b[11], da, db;

	scanf("%s %c%s %c", a, &da, b, &db);

	for(cnt_a = 0, i = 0; a[i]; ++i)
		if(a[i] == da)
			++cnt_a;

	for(cnt_b = 0, i = 0; b[i]; ++i)
		if(b[i] == db)
			++cnt_b;

	for(i = 0, pa = 0; i < cnt_a; ++i) {
		pa *= 10;
		pa += da - '0';
	}

	for(i = 0, pb = 0; i < cnt_b; ++i) {
		pb *= 10;
		pb += db - '0';
	}

	printf("%lld\n", pa + pb);

	return 0;
}
