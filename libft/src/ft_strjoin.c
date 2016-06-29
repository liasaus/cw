
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		iparam;
	char	*str;

	i = 0;
	iparam = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[iparam])
	{
		str[i++] = s1[iparam];
		iparam++;
	}
	iparam = 0;
	while (s2[iparam])
	{
		str[i] = s2[iparam];
		i++;
		iparam++;
	}
	str[i] = '\0';
	return (str);
}
