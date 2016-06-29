
#include "libft.h"

static int	ft_isblank(int c)
{
	if (c == '\v' || c == '\f' || c == '\r' || c == '\033')
		return (1);
	else
		return (0);
}

char		*ft_strtrim2(char const *s)
{
	int		i;
	int		j;
	char	*strim;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (ft_isblank(s[i]) && s[i] != '\0')
		i++;
	while (j > -1 && ft_isblank(s[j]))
		j--;
	if (j < 0)
		return (ft_strdup(""));
	strim = ft_strsub(s, i, (j + 1 - i));
	return (strim);
}
