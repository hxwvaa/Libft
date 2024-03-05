#include <stdio.h>

//NOT CORRECT

char *strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)str[i]);
		i++;
	}
	return (0);
}

int main(void)
{
	printf("%s\n", strchr("hello", 'l'));
}
