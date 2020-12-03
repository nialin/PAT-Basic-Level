#include <stdio.h>

struct money_st {
	int galleon, sickle, knut;
};

int money_to_knut(struct money_st m);
struct money_st knut_to_money(int knut);

int money_to_knut(struct money_st m)
{
	return (m.galleon * 17 + m.sickle) * 29 + m.knut;
}

struct money_st knut_to_money(int knut)
{
	int sign = 1;
	struct money_st rslt;

	if(knut < 0) {
		sign = -1;
		knut = -knut;
	}

	rslt.knut = knut % 29;
	knut /= 29;

	rslt.sickle = knut % 17;
	knut /= 17;

	rslt.galleon = knut * sign;

	return rslt;
}

int main()
{
	struct money_st p, a, delta;

	scanf("%d.%d.%d", &p.galleon, &p.sickle, &p.knut);
	scanf("%d.%d.%d", &a.galleon, &a.sickle, &a.knut);

	delta = knut_to_money(money_to_knut(a) - money_to_knut(p));

	printf("%d.%d.%d\n", delta.galleon, delta.sickle, delta.knut);

	return 0;
}
