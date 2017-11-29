#include "unistd.h"
#include <sys/types.h>
#include <sys/uio.h>
#include "stdio.h"
#include <fcntl.h>
#include <stdlib.h>


char	*valid(char *array)
{
	int i;
	int counter_diez;

	i = 0;
	counter_diez = 0;
	while (array[i])
	{
		if (array[i] == '#')
			counter_diez++;
		if (array[i] == '\n' && array[i + 1] == '\n')
		{
			if (counter_diez != 4)
				{
					printf("error\n");
					return (0);
				}
			counter_diez = 0;
		}
		i++;
	}		
	printf("Nistyak, rabotaet\n");
	return (array);
}

char	*valid_figure(char *array)
{
	int i;
	int j;
	int counter_diez;

	i = 0;
	j = 0;
	counter_diez = 0;
	while (array[i])
	{
		if (array[i] == '#')
		{	
			if ((array[i + 1] == '#') && ((j + 1) <= 20))
				counter_diez++;
			if ((array[i - 1] == '#') && ((j - 1) >= 0))
				counter_diez++;
			if ((array[i + 5] == '#') && ((j + 5) <= 20))
				counter_diez++;
			if ((array[i - 5] == '#') && ((j - 5) >= 0))
				counter_diez++;
		}
		if ((array[i] == '\n' && array[i + 1] == '\n') || array[i] == '\0')
		{
			if (counter_diez != 6 && counter_diez != 8)
			{
				printf("i = %i\n", i);

				printf("Not valid tetraminos\n");
				return (0);
			}
			counter_diez = 0;
			j = 0;
		}
		i++;
		j++;
	}
	printf("Valid tetraminos!\n");
	return (array);
}


int main(int argc, char const *argv[])
{
	char buf[1];
	int  i;
	int  fd;
	char *array;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	array = (char *)malloc(sizeof(char) * 2000);
	while ((read(fd, buf, 1)) > 0)
	{
		array[i] = *buf;
		i++;
	}
	if (valid(array) == 0)
		return (0);
	valid_figure(array);
	close(fd);
	return (0);
}