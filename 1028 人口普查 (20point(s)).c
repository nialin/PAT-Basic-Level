#include <stdio.h>
#include <string.h>

int main()
{
	int i, n, cnt;
	char name[6], date[11] = {0}, old_date[11] = "2014/09/07", young_date[11] = "1814/09/05", young[6] = {0}, old[6] = {0};

	scanf("%d", &n);

	for(i = 0, cnt = 0; i < n; ++i) {
		scanf("%s %s", name, date);

		if(strcmp(date, "1814/09/06") >= 0 && strcmp(date, "2014/09/06") <= 0) {
			if(strcmp(date, young_date) > 0) {
				strcpy(young, name);
				strcpy(young_date, date);
			}

			if(strcmp(date, old_date) < 0) {
				strcpy(old, name);
				strcpy(old_date, date);
			}

			++cnt;
		}
	}

	printf("%d", cnt);

	if(cnt)
		printf(" %s %s", old, young);

	printf("\n");

	return 0;
}
