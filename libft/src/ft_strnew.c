
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(*str) * size + 1);
	if (str)
	{
		while (i < size)
		{
			str[i] = '\0';
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
