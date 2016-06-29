
#include "libft.h"

int		ft_str_is_numeric(char *str)
{
	int i;

	i = 0;
	if (!str[i])
		return (1);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	if (i)
		return (1);
	return (0);
}
