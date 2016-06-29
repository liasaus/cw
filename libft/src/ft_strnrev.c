
#include "libft.h"

char	*ft_strnrev(char *c, const int len)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = len - 1;
	while (i < (len / 2))
	{
		tmp = c[i];
		c[i++] = c[j];
		c[j--] = tmp;
	}
	return (c);
}
