
#include "libft.h"

int		ft_strisspace(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isspace(str[i])))
			return (0);
		i++;
	}
	return (1);
}
