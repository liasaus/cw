
#include "libft.h"

int	ft_str_is_lowercase(char *str)
{
	int i;

	i = 0;
	if (!str[i])
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			i++;
		else
			return (0);
	}
	if (i)
		return (1);
	return (0);
}
