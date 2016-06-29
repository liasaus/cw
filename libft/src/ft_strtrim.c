
#include "libft.h"

static int				ft_iswhitespace(char c)
{
	return (c == ' ' || c == ',' || c == '\n' || c == '\t') ? 1 : 0;
}

static int				ft_onlywhitesp(char const *s, size_t i)
{
	size_t y;

	y = 0;
	while (s[i])
	{
		if (!ft_iswhitespace(s[i]))
			return (0);
		else
			i++;
	}
	return (1);
}

static t_conteneur4		ft_init(char const *s)
{
	t_conteneur4 c;

	c.i = 0;
	c.d = 0;
	c.s2 = malloc(sizeof(char) * ft_strlen(s));
	return (c);
}

char					*ft_strtrim(char const *s)
{
	t_conteneur4 c;

	if (s == NULL)
		return (NULL);
	c = ft_init(s);
	while (c.i < ft_strlen(s))
	{
		if ((c.i == 0 || ft_onlywhitesp(s, c.i))
				&& ft_iswhitespace(s[c.i]))
		{
			while (ft_iswhitespace(s[c.i]))
			{
				c.i++;
				c.d++;
			}
		}
		else
		{
			c.s2[c.i - c.d] = s[c.i];
			c.i++;
		}
	}
	c.s2[c.i - c.d] = '\0';
	return (c.s2);
}
