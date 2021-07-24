#include "get_next_line.h"

int ft_strlen(char *str)
{
	int count = 0;
	while(*str++)
		count++;
	return count;
}

char *ft_strdup(char *str)
{
	int i = 0;
	char *rslt = malloc(ft_strlen(str) + 1);
	
	while (*str)
		rslt[i++] = *str++;
	rslt[i] = 0;
	return (rslt);
}

char *ft_strjoin(char *str1, char *str2)
{
	char *rslt = malloc(ft_strlen(str1) + ft_strlen(str2) +1);
	int i = 0;

	while (*str1)
		rslt[i++] = *str1++;
	while (*str2)
		rslt[i++] = *str2++;
	rslt[i] = 0;
	return (rslt);
}

int ft_strchr(char c, char *str)
{
	int ret = 0;
	while (str[ret])
	{
		if (str[ret] == c)
			return (ret);
		ret++;
	}
	return (-1);
}

int get_next_line(char **line)
{
	char tmp[2];
	char *total_read;
	char *safe;

	total_read = 0;
	while ((read(0, tmp, 1)) > 0)
	{
		tmp[1] = 0;
		if (!total_read)
			total_read = ft_strdup(tmp);
		else
		{
			safe = total_read;
			total_read = ft_strjoin(total_read, tmp);
			free(safe);
		}
		if (ft_strchr('\n', total_read) >= 0)
		{
			total_read[ft_strchr('\n', total_read)] = 0;
			*line = total_read;
			return 1;
		}	
	}
	if (total_read)
		*line = total_read;
	else
		*line = ft_strdup("");
	return 0;
}
