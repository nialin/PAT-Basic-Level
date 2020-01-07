#include <stdio.h>
#include <string.h>

struct stu {
	int score;
	char name[11], num[11];
};

int main()
{
	int i, n;
	struct stu new, low_stu = {101}, high_stu = {-1};

	scanf("%d", &n);

	for(i = 0; i < n; ++i) {
		scanf("%s%s%d", new.name, new.num, &new.score);

		if(new.score < low_stu.score)
			memcpy(&low_stu, &new, sizeof(struct stu));

		if(new.score > high_stu.score)
			memcpy(&high_stu, &new, sizeof(struct stu));
	}

	printf("%s %s\n", high_stu.name, high_stu.num);
	printf("%s %s\n", low_stu.name, low_stu.num);

	return 0;
}
