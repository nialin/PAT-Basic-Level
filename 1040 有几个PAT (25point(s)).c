#include <stdio.h>

int main()
{
	char ch;
	long long p_cnt, pa_cnt, pat_cnt;

	for(p_cnt = pa_cnt = pat_cnt = 0; scanf("%c", &ch) != EOF; ) {
		switch(ch) {
			case 'P':
				++p_cnt;
				break;

			case 'A':
				pa_cnt += p_cnt;
				break;

			case 'T':
				pat_cnt += pa_cnt;
				break;
		}
	}

	printf("%lld\n", pat_cnt % 1000000007);

	return 0;
}
