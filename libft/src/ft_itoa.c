
#include "libft.h"

static t_conteneur	ft_conteneur(int n)
{
	t_conteneur cont;

	cont.i = 0;
	cont.y = 0;
	cont.s = malloc(sizeof(char) * 33);
	cont.r = n;
	return (cont);
}

static t_conteneur	ft_zero(t_conteneur c)
{
	c.s[c.y] = '0';
	c.y++;
	return (c);
}

static t_conteneur	ft_setnegative(t_conteneur c)
{
	c.s[c.y] = '-';
	c.y++;
	c.r *= (-1);
	return (c);
}

char				*ft_itoa(int n)
{
	t_conteneur c;

	c = ft_conteneur(n);
	if (c.r < 0)
		c = ft_setnegative(c);
	c = (c.r == 0) ? ft_zero(c) : c;
	while (c.r > 0)
	{
		c.tabs[c.i] = c.r % 10;
		c.r /= 10;
		c.i++;
	}
	c.i--;
	while (c.i >= 0)
	{
		c.s[c.y] = c.tabs[c.i] + '0';
		c.i--;
		c.y++;
	}
	c.s[c.y] = '\0';
	return (c.s);
}
