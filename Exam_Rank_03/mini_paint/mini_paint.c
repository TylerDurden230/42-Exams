#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define ERR1 "Error: argument\n"
#define ERR2 "Error: Operation file corrupted\n"

int ft_strlen(const char *str)
{
	int i= 0;
	while(str[i] != 0)
		i++;
	return i;
}

int ft_perror(const char * str)
{
	write(1, str, ft_strlen(str));
	return 1;
}

int check_pos(float x, float y, float cx, float cy, float radius)
{
	float distance = sqrtf(powf(x - cx, 2.) + powf(y - cy, 2.));
	if (distance <= radius)
	{
		if((radius - distance) < 1.00000000)
			return 0;
		return 1;
	}
	return 2;
}

int main(int ac, char**av)
{
	FILE * file;
	char * canvas;
	int pos, read;
	int x, y;

	char bg;
	int bw, bh;

	char id, color;
	float cx, cy, radius;
	if(ac != 2)
		return ft_perror(ERR1);
	if(!(file = fopen(av[1], "r")) || 
		(fscanf(file, "%d %d %c\n", &bw, &bh, &bg) != 3) || 
		(!(bw > 0 && bw <= 300 && bh > 0 && bh <= 300)) || 
		(!(canvas = (char*)malloc(sizeof(char) * (bw * bh)))))
		return (ft_perror(ERR2));
	memset(canvas, bg, bw * bh);
	while((read = fscanf(file, "%c %f %f %f %c\n", &id, &cx, &cy, &radius, &color)) == 5)
	{
		if (!(radius > 0) || !(id == 'C' || id == 'c'))
			break;
		y = -1;
		while (++y < bh)
		{
			x = -1;
			while(++x < bw)
			{
				pos = check_pos((float)x, (float)y, cx, cy, radius);
				if (pos == 0 || (pos == 1 && id == 'C'))
					canvas[y * bw + x] = color;
			}
		}
	}
	if (read != -1)
	{
		free(canvas);
		return ft_perror(ERR2);
	}
	y = -1;
	while (++y < bh)
	{
		write(1, canvas + y * bw, bw);
		write(1, "\n", 1);
	}
	free(canvas);
	fclose(file);
	return 0;
}
