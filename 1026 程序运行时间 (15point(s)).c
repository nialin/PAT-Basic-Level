#include <stdio.h>

int main()
{
	int c1, c2, tick, hour, min, sec;

	scanf("%d%d", &c1, &c2);

	tick = c2 - c1;

	sec = tick / 100 % 60 + (tick % 100 >= 50 ? 1 : 0);
	min = tick / 6000 % 60;
	hour = tick / 360000;

	printf("%02d:%02d:%02d", hour, min, sec);

	return 0;
}
