#include <stdio.h>
#include <string.h>

struct stu_st {
	char exam_num[17];
	int seat_num;
};

int main()
{
	char exam_num[17];
	int i, n, test_num, seat_num;
	struct stu_st stus[1001];

	for(i = 0, scanf("%d", &n); i < n; ++i) {
		scanf("%s%d%d", exam_num, &test_num, &seat_num);

		strcpy(stus[test_num].exam_num, exam_num);
		stus[test_num].seat_num = seat_num;
	}

	for(i = 0, scanf("%d", &n); i < n; ++i) {
		scanf("%d", &test_num);
		printf("%s %d\n", stus[test_num].exam_num, stus[test_num].seat_num);
	}

	return 0;
}
