
#include "header.h"

char	**explode(char *tofind, char *s)
{
	int		i;
	int		cut;
	int		len;
	int		a;
	char	**tab;

	if ((tab = malloc(sizeof(char **) * ft_strlen(s))) == NULL)
		return (NULL);
	a = 0;
	cut = 0;
	len = ft_strlen(tofind);
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_strncmp(s + i, tofind, len) == 0)
		{
			(cut != i) ? tab[a++] = join_a_b(s, cut, i) : 0;
			i += len - 1;
			cut = i + 1;
		}
		i++;
	}
	(cut != i) ? tab[a++] = join_a_b(s, cut, i) : 0;
	tab[a] = NULL;
	return (tab);
}
