#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	size_t len;
	int i, j, n, num;
	char *earth[] = {
		"tret", "jan", "feb", "mar", "apr", "may", "jun",
		"jly", "aug", "sep", "oct", "nov", "dec"
	}, *mars[] = {
		"", "tam", "hel", "maa", "huh", "tou", "kes",
		"hei", "elo", "syy", "lok", "mer", "jou"
	}, *line = NULL, term1[4] = {0}, term2[4] = {0};

	for(i = 0, scanf("%d\n", &n); i < n; ++i) {
		getline(&line, &len, stdin);

		if(isdigit(line[0])) {
			num = atoi(line);

			if(0 == num) {
				printf("tret\n");

				continue;
			}

			if(num / 13)
				printf("%s", mars[num / 13]);

			if(num % 13)
				printf("%s%s", num / 13 ? " " : "", earth[num % 13]);
		}
		else {
			if(strlen(line) > 5) {
				sscanf(line, "%s %s", term1, term2);

				for(j = 0; j < 13 && strcmp(term1, mars[j]); ++j)
					;

				num = j * 13;

				for(j = 0; j < 13 && strcmp(term2, earth[j]); ++j)
					;

				num += j;
			}
			else {
				sscanf(line, "%s", term1);

				for(j = 0; j < 13 && strcmp(term1, mars[j]); ++j)
					;

				if(j < 13)
					num = j * 13;
				else {
					for(j = 0; j < 13 && strcmp(term1, earth[j]); ++j)
						;

					num = j;
				}
			}

			printf("%d", num);
		}

		printf("\n");
	}

	return 0;
}
