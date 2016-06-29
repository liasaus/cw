
#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char c;

	c = '\n';
	write(fd, s, ft_strlen(s));
	write(fd, &c, 1);
}
