
#include "libft.h"
#include <stdio.h>

static void		ft_inittab(char **tabs, size_t n, size_t length)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		tabs[i] = malloc(sizeof(char*) * (length + 1));
		i++;
	}
	tabs[i] = malloc(sizeof(char *) * 1);
	tabs[i] = 0;
}

static int		ft_analyse(char const *s, char c)
{
	size_t i;
	size_t res;

	res = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c) && i != 0 && s[i + 1] != '\0')
			res++;
		i++;
	}
	return (res);
}

static void		ft_traitement(char **tabs, char const *s, char c)
{
	size_t	i;
	size_t	a;
	size_t	y;

	i = 0;
	a = 0;
	y = 0;
	while (s[i] != '\0')
	{
		y = 0;
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
			{
				tabs[a][y] = s[i];
				y++;
				i++;
			}
			tabs[a][y] = '\0';
			a++;
		}
		else
			i++;
	}
	tabs[a] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tabs;
	size_t	occu;

	occu = 0;
	if (!s)
	{
		tabs = malloc(sizeof(char**));
		tabs[0] = NULL;
		return (tabs);
	}
	occu = ft_analyse(s, c);
	tabs = malloc(sizeof(char**) * (occu + 1));
	ft_inittab(tabs, occu, ft_strlen(s));
	ft_traitement(tabs, s, c);
	return (tabs);
}
