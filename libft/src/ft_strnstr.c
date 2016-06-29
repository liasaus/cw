
#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	unsigned int i;
	unsigned int y;

	i = 0;
	if (!s2 || s2[0] == '\0')
		return (char *)(&s1[0]);
	while (s1[i] != '\0' && i < len)
	{
		y = 0;
		if (s1[i + y] == s2[y] && (i + ft_strlen(s2) <= len))
		{
			while ((s1[i + y] == s2[y]) && s2 && i + y < len)
			{
				y++;
				if (y == ft_strlen(s2))
					return (char*)(&s1[i]);
			}
		}
		i++;
	}
	return (NULL);
}
