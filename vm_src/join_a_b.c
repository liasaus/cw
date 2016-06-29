
#include "header.h"

unsigned char	*join_a_b(unsigned char *s, int a, int b)
{
	unsigned char	*new_s;
	int				len;
	int				i;

	len = b - a;
	if ((new_s = malloc(sizeof(unsigned char *) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i + a < b)
	{
		new_s[i] = s[i + a];
		i++;
	}
	return (new_s);
}

void			cpy_a_b(void *new_s, unsigned char *src, int a, int b)
{
	int				len;
	unsigned char	*ptr;
	int				i;

	ptr = (unsigned char *)new_s;
	len = b - a;
	i = 0;
	while (i + a < b)
	{
		ptr[i] = src[i + a];
		i++;
	}
}
