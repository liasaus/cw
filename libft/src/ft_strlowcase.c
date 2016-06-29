
#include "libft.h"

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
