
#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t i;

	i = 0;
	if (s && f)
	{
		while (i < ft_strlen(s))
		{
			f(&s[i]);
			i++;
		}
	}
}
