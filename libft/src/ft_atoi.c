
#include "libft.h"

static t_conteneur3	ft_setnegative(const char *s, t_conteneur3 c)
{
	if (s[c.i] == '-')
	{
		c.coef = -1;
		c.i++;
	}
	return (c);
}

static t_conteneur3	ft_initc(void)
{
	t_conteneur3 c;

	c.coef = 1;
	c.i = 0;
	c.res = 0;
	return (c);
}

int					ft_atoi(const char *nptr)
{
	t_conteneur3 c;

	c = ft_initc();
	if (nptr == 0 || (nptr[0] == '+' && (nptr[1] == '-' || nptr[1] == '+'))
			|| !ft_isascii(nptr[0]))
		return (0);
	while (!ft_isdigit(nptr[c.i]) && nptr[c.i] != '-')
	{
		if (ft_isprint(nptr[c.i])
				&& (!ft_isspace(nptr[c.i])) && nptr[c.i] != '+')
			return (0);
		c.i++;
	}
	c = ft_setnegative(nptr, c);
	while (nptr[c.i] != '\0' && ft_isdigit(nptr[c.i]))
	{
		c.res += nptr[c.i] - '0';
		c.res *= 10;
		c.i++;
	}
	c.res /= 10;
	return (c.res * c.coef);
}
