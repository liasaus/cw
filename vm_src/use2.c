
#include "header.h"

int				reg_correct(int reg_number)
{
	if (reg_number > 0 && reg_number <= REG_NUMBER)
		return (1);
	else
		return (0);
}

char			*binary_cat(char *dest, int len_dest, char *src, int len_src)
{
	int i;

	i = 0;
	while (i < len_src)
	{
		dest[i + len_dest] = src[i];
		i++;
	}
	return (dest);
}

char			*binary_cpy(char *src, char *dest, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		src[i] = dest[i];
		i++;
	}
	return (src);
}
