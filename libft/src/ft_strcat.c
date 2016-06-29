
#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	unsigned int i;
	unsigned int length;

	i = 0;
	length = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[length + i] = src[i];
		i++;
	}
	dest[length + i] = '\0';
	return (dest);
}
