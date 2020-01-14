#include <stdio.h>

int main()
{
	int i, n, num, sum_0 = 0, sum_1 = 0, sign_1 = 1, sum_3 = 0, max_4 = 0, cnts[5] = {0};

	scanf("%d", &n);

	for(i = 0; i < n; ++i){
		scanf("%d", &num);

		switch(num % 5) {
			case 0 :
				if(0 == num % 2) {
					sum_0 += num;
					++cnts[0];
				}

				break;

			case 1:
				sum_1 += sign_1 * num;
				sign_1 *= -1;

				++cnts[1];

				break;

			case 2:
				++cnts[2];

				break;

			case 3:
				sum_3 += num;

				++cnts[3];

				break;

			case 4:
				if(max_4 < num)
					max_4 = num;

				++cnts[4];

				break;
		}
	}

	if(cnts[0])
		printf("%d ", sum_0);
	else
		printf("N ");

	if(cnts[1])
		printf("%d ", sum_1);
	else
		printf("N ");

	if(cnts[2])
		printf("%d ", cnts[2]);
	else
		printf("N ");

	if(cnts[3])
		printf("%.1f ", (float)sum_3 / cnts[3]);
	else
		printf("N ");

	if(cnts[4])
		printf("%d\n", max_4);
	else
		printf("N\n");

	return 0;
}
