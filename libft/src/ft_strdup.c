
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*newstr;
	int		i;

	if (s == NULL)
		return (ft_strdup("(null)"));
	newstr = (char *)malloc(ft_strlen(s) * sizeof(char *) + 1);
	i = 0;
	while (s[i])
	{
		newstr[i] = s[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
