#include <unistd.h>

short is_in_string(char c, char *str)
{
	while(*str)
	{
		if (*str++ == c)
			return 1;
	}
	return 0;
}

int ft_strlen(char *str)
{
	int count = 0;

	while (*str++)
		count++;
	return count;
}

int main(int argc, char *argv[])
{
	if (argc != 3)
		return -1;
	char *str1 = argv[1];
	char *str2 = argv[2];
	char rslt[ft_strlen(str1) + 1];
	int i = 0;

	rslt[0] = 0;
	while (*str1)
	{
		if (is_in_string(*str1, str2) && !is_in_string(*str1, rslt))
		{
			rslt[i++] = *str1;
			rslt[i] = 0;
		}
		str1++;
	}
	write(1, rslt, i);
	return 0;
}
