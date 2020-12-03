#include <stdio.h>

int main()
{
	int i, n, schools[100001] = {0}, sid, score, max_id;

	scanf("%d", &n);

	for(i = 0, max_id = 0; i < n; ++i) {
		scanf("%d%d", &sid, &score);

		schools[sid] += score;

		if(schools[sid] > schools[max_id])
			max_id = sid;
	}

	printf("%d %d\n", max_id, schools[max_id]);

	return 0;
}
