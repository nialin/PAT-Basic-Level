#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);
void fmt_print(long long a, long long b);

int gcd(int a, int b)
{
	return a % b ? gcd(b, a % b) : b;
}

void fmt_print(long long a, long long b)
{
	long long c, k, sign = 1;

	if(0 == a) {
		printf("0");

		return ;
	}

	if(0 == b) {
		printf("Inf");

		return ;
	}

	if(a < 0) {
		sign *= -1;
		a = -a;
	}

	if(b < 0) {
		sign *= -1;
		b = -b;
	}

	k = a / b;
	a -= b * k;
	c = gcd(a, b);

	if(-1 == sign)
		printf("(-");

	if(k)
		printf("%lld", k);

	if(a)
		printf("%s%lld/%lld", k ? " " : "", a / c, b / c);

	if(-1 == sign)
		printf(")");
}

int main()
{
	long long a1, b1, a2, b2;

	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);

	fmt_print(a1, b1);
	printf(" + ");
	fmt_print(a2, b2);
	printf(" = ");
	fmt_print(a1 * b2 + a2 * b1, b1 * b2);
	printf("\n");

	fmt_print(a1, b1);
	printf(" - ");
	fmt_print(a2, b2);
	printf(" = ");
	fmt_print(a1 * b2 - a2 * b1, b1 * b2);
	printf("\n");

	fmt_print(a1, b1);
	printf(" * ");
	fmt_print(a2, b2);
	printf(" = ");
	fmt_print(a1 * a2, b1 * b2);
	printf("\n");

	fmt_print(a1, b1);
	printf(" / ");
	fmt_print(a2, b2);
	printf(" = ");
	fmt_print(a1 * b2 , a2 * b1);
	printf("\n");

	return 0;
}
