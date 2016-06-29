
#include "libft.h"

long double		ft_power(long double x, long double y)
{
	long double	res;
	int			neg;

	res = x;
	neg = (y < 0) ? 1 : 0;
	if (neg)
		y *= -1;
	if (!y)
		return (1);
	while (--y > 0)
		res *= x;
	if (neg)
		res = 1 / res;
	return (res);
}
