
#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;
	unsigned char	x;

	i = 0;
	if (!src)
		return (NULL);
	p1 = (unsigned char *)dest;
	p2 = (unsigned char *)src;
	x = (unsigned long)c;
	while (i < n)
	{
		if ((*p1++ = *p2++) == x)
			return (p1);
		i++;
	}
	return (NULL);
}
