#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int clr;
	char key_map[128], mask, ch;

	memset(key_map, 1, 128);

	while((mask = getchar()) != '\n') {
		if(isupper(mask))
			key_map[mask + 32] = 0;

		if(islower(mask))
			key_map[mask - 32] = 0;

		if('+' == mask)
			for(clr = 'A'; clr <= 'Z'; ++clr)
				key_map[clr] = 0;
		else
			key_map[mask] = 0;
	}

	while((ch = getchar()) != '\n')
		if(key_map[ch])
			printf("%c", ch);

	printf("\n");

	return 0;
}
