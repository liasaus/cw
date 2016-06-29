
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s1end;

	i = 0;
	while (dst[i] && i < size)
		i++;
	s1end = i;
	while (src[i - s1end] && i < size - 1)
	{
		dst[i] = src[i - s1end];
		i++;
	}
	if (s1end < size)
		dst[i] = '\0';
	return (s1end + ft_strlen(src));
}
