
#include "header.h"

int			count(char **t)
{
	int i;

	i = 0;
	while (t[i] != NULL)
		i++;
	return (i);
}
