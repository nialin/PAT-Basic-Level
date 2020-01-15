#include <stdio.h>

struct gesture {
	int c, j, b;
};

void update_gesture(struct gesture *tar, char gest)
{
	if('C' == gest)
		++tar->c;

	if('J' == gest)
		++tar->j;

	if('B' == gest)
		++tar->b;
}

void print_most_gesture(struct gesture *a)
{
	if(a->b >= a->c && a->b >= a->j)
		printf("B");
	else if(a->c >= a->j && a->c > a->b)
		printf("C");
	else
		printf("J");
}

int main()
{
	char gest_jia, gest_yi;
	int i, n, win = 0, draw = 0, lose = 0;
	struct gesture jia = {0}, yi = {0};

	scanf("%d", &n);
	getchar();

	for(i = 0; i < n; ++i) {
		scanf("%c %c", &gest_jia, &gest_yi);
		getchar();

		switch(gest_jia) {
			case 'C' :
				if('C' == gest_yi)
					++draw;
				else if('J' == gest_yi) {
					update_gesture(&jia, 'C');
					++win;
				}
				else {
					update_gesture(&yi, 'B');
					++lose;
				}

				break;

			case 'J':
				if('C' == gest_yi) {
					update_gesture(&yi, 'C');
					++lose;
				}
				else if('J' == gest_yi)
					++draw;
				else {
					update_gesture(&jia, 'J');
					++win;
				}

				break;

			case 'B':
				if('C' == gest_yi) {
					update_gesture(&jia, 'B');
					++win;
				}
				else if('J' == gest_yi) {
					update_gesture(&yi, 'J');
					++lose;
				}
				else
					++draw;

				break;
		}
	}

	printf("%d %d %d\n", win, draw, lose);
	printf("%d %d %d\n", lose, draw, win);

	print_most_gesture(&jia);
	printf(" ");

	print_most_gesture(&yi);
	printf("\n");

	return 0;
}
