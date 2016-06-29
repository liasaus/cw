
#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	unsigned int i;
	unsigned int length;

	i = 0;
	length = ft_strlen(dest);
	while (src[i] != '\0' && i < n)
	{
		dest[length + i] = src[i];
		i++;
	}
	dest[length + i] = '\0';
	return (dest);
}
