#include <stdio.h>
#include <ctype.h>

int main()
{
	int i, j;
	char str_src[81], str_dest[81], map[37] = {0};

	scanf("%s%s", str_src, str_dest);

	for(i = j = 0; str_src[i]; ++i) {
		if(str_src[i] != str_dest[j]) {
			if(isupper(str_src[i]) && !map[str_src[i] - 'A']) {
				map[str_src[i] - 'A'] = 1;
				putchar(str_src[i]);
			}

			else if(islower(str_src[i]) && !map[str_src[i] - 'a']) {
				map[str_src[i] - 'a'] = 1;
				putchar(str_src[i] - 'a' + 'A');
			}

			else if(isdigit(str_src[i]) && !map[str_src[i] - '0' + 26]) {
				map[str_src[i] - '0' + 26] = 1;
				putchar(str_src[i]);
			}

			else if(str_src[i] == '_' && !map[36]) {
				map[36] = 1;
				putchar('_');
			}
		}
		else
			++j;
	}

	printf("\n");

	return 0;
}
