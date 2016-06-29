
#include "libft.h"

void	ft_putendl(char const *s)
{
	char c;

	c = '\n';
	write(1, s, ft_strlen(s));
	write(1, &c, 1);
}
