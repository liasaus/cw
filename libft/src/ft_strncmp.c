
#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] && s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
