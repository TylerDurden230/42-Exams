#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h> // to use memset

#define ERR1 "Error: argument\n"
#define ERR2 "Error: Operation file corrupted\n"

int ft_strlen(const char* s)
{
	int i = 0;
	while (s[i] != 0)
		i++;
	return i;
}

int ft_perror(const char *s)
{
	write(1, s, ft_strlen(s));
	return 1;
}

int check_pos(float x, float y, float topx, float topy, float width, float height)
{
	if (x < topx || x > topx + width || y < topy || y > topy + height) // out of the rectangle
		return 0;
	else if (x - topx < 1.00000000 || (topx + width) - x < 1.00000000 || y - topy < 1.00000000 || (topy + height) - y < 1.00000000) // on the border
		return 1;
	return 2; // in the rectangle
}

int main(int ac, char** av)
{
	FILE * file;
	int pos, read;
	int x, y; // iterators
	char * canvas;

	char bg; 	//	bg_char
	int bw, bh; //	bg_width & bg_height

	char id, color;						//	id action R or r, char to color the rectangle
	float topx, topy, width, height;	//	top-left rectangle coordinates x y, rectangle width and height 

	if (ac != 2) // without argument
		return (ft_perror(ERR1)); // Error 1 output, function termination
	if (!(file = fopen(av[1], "r")) || // The file of the first argument cannot be opened, or
		(fscanf(file, "%d %d %c\n", &bw, &bh, &bg) != 3) || // The first line of the file does not match the condition or
		(!(bw > 0 && bw <= 300 && bh > 0 && bh <= 300)) || // Or the bg is not within the specified range
		(!(canvas = (char *)malloc(sizeof(char) * (bw * bh))))) // If you cannot allocate as much memory as the bg
		return (ft_perror(ERR2)); // Error 2 output, function termination
	memset(canvas, bg, bw * bh); // bg drawing
	while ((read = fscanf(file, "%c %f %f %f %f %c\n", &id, &topx, &topy, &width, &height, &color)) == 6) // Repeat if the condition (format, number) is met from the second line of the file
	{
		if (!(width > 0 && height > 0) || !(id == 'R' || id == 'r')) // If the size to be drawn is negative or the id is not'R' or'r'
				break ; // Loop escape
		y = -1;
		while (++y < bh) // Repeat until the bg height
		{
			x = -1;
			while (++x < bw) // Repeat until bg width
			{
				pos = check_pos((float)x, (float)y, topx, topy, width, height); // Boundary check
				if (pos == 1 || (pos == 2 && id == 'R'))
					canvas[y * bw + x] = color; // drawing
			}
		}
	}
	if (read != -1) // What if I escaped the loop and the reason was not that the reading failed Because it doesn’t meet the conditions
	{
		free(canvas); // Release bg memory
		return (ft_perror(ERR2)); // Error 2 output, function termination
	}
	y = -1;
	while (++y < bh) // Repeat to bg height
	{
		write(1, canvas + y * bw, bw); // Painting
		write(1, "\n", 1); // Newline
	}
	free(canvas); // Release bg memory
	fclose(file); // Close file
	return (0); // Function termination
}