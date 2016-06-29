
#include "libft.h"

long			ft_latoi(const char *s)
{
	int			signe;
	long int	res;

	signe = 1;
	res = 0;
	if (*s == '-')
	{
		signe = -1;
		s++;
	}
	while (*s)
	{
		res += *s - '0';
		s++;
		(*s) ? res *= 10 : 0;
	}
	return (res * signe);
}
