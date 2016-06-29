
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	if (!(s = malloc(sizeof(char *) * (size))))
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
