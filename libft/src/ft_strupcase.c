
#include "libft.h"

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
