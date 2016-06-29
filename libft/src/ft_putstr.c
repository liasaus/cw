
#include "libft.h"

void	ft_putstr(char const *s)
{
	if (s != NULL)
		write(1, s, ft_strlen(s));
}
