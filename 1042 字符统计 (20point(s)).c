#include <stdio.h>
#include <ctype.h>

int main()
{
	char ch, max;
	int map[128] = {0};

	while(scanf("%c", &ch) != EOF && ch != '\n')
		if(isupper(ch))
			++map[ch + 32];
		else
			++map[ch];

	for(ch = max = 'a'; ch <= 'z'; ++ch)
		if(map[ch] > map[max])
			max = ch;

	printf("%c %d\n", max, map[max]);

	return 0;
}
