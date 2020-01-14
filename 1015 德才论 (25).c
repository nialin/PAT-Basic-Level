#include <stdio.h>
#include <stdlib.h>

struct score{
	int num, de, cai, type;
};

int cmp(const void *a, const void *b) {
	if(((struct score *)a)->type == ((struct score *)b)->type) {
		if((((struct score *)a)->de + ((struct score *)a)->cai) == (((struct score *)b)->de + ((struct score *)b)->cai)) {
			if(((struct score *)a)->de == ((struct score *)b)->de)
				return ((struct score *)a)->num - ((struct score *)b)->num;
			else
				return ((struct score *)b)->de - ((struct score *)a)->de;
		}
		else
			return (((struct score *)b)->de + ((struct score *)b)->cai) - (((struct score *)a)->de + ((struct score *)a)->cai);
	}

	return ((struct score *)a)->type - ((struct score *)b)->type;
}

int main()
{
	int i, n, l, h, cnt;
	struct score stus[100000] = {{0}};

	scanf("%d%d%d", &n, &l, &h);

	for(i = 0, cnt = 0; i < n; ++i) {
		scanf("%d%d%d", &stus[cnt].num, &stus[cnt].de, &stus[cnt].cai);

		if(stus[cnt].de >= h && stus[cnt].cai >= h)
			stus[cnt].type = 1;
		else if(stus[cnt].de >= h)
			stus[cnt].type = 2;
		else if(stus[cnt].de >= stus[cnt].cai)
			stus[cnt].type = 3;
		else
			stus[cnt].type = 4;

		if(stus[cnt].de >= l && stus[cnt].cai >= l)
			++cnt;
	}

	qsort(stus, cnt, sizeof(struct score), cmp);

	printf("%d\n", cnt);

	for(i = 0; i < cnt; ++i)
		printf("%d %d %d\n", stus[i].num, stus[i].de, stus[i].cai);

	return 0;
}