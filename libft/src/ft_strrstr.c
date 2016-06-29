
#include "libft.h"

char	*ft_strrstr(const char *big, const char *little)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	ret = NULL;
	if (!little || *little == '\0')
		return (((char *)big));
	while (big[i] != '\0')
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && big[i + j] != '\0')
			{
				j++;
				if (little[j] == '\0')
					ret = (char *)(&big[i]);
			}
		}
		i++;
	}
	return (ret);
}
