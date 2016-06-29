
#include "asm.h"

int					check_label(char *str)
{
	t_label			*tmp;
	int				i;

	i = -1;
	tmp = *g_labels;
	while (tmp && tmp->next)
		tmp = tmp->next;
	while (tmp)
	{
		if (!ft_strcmp(str, tmp->name))
			i = tmp->address;
		tmp = tmp->prev;
	}
	return (i);
}

char				*find_label(char **line)
{
	char			*start;
	char			*ret;

	(*line)++;
	start = *line;
	while (*start && !ft_isspace(*start) && *start != SEPARATOR_CHAR)
	{
		if (!ft_strchr(LABEL_CHARS, *start))
			put_error("not a LABEL_CHARS");
		start++;
	}
	if (!(ret = ft_strsub(*line, 0, start - *line)))
		put_error(0);
	return (ret);
}

int					check_num(char **line)
{
	char			*start;
	char			*tmp;
	int				ret;

	start = *line;
	while (*start && (ft_isdigit(*start) || start[0] == '-'))
		start++;
	start = ft_strepur(start);
	if (*start && *start != SEPARATOR_CHAR && !ft_isspace(*start))
		put_error("not a valid number");
	if (!(tmp = ft_strsub(*line, 0, start - *line)))
		put_error(0);
	ret = ft_atoi(tmp);
	free(tmp);
	*line = start;
	return (ret);
}

void				verif_label(t_cmnd *cmnd)
{
	int			i;
	t_cmnd		*check;

	check = cmnd;
	while (check)
	{
		check_label_find(check);
		check = check->next;
	}
	while (cmnd)
	{
		i = 0;
		while (i < 3)
		{
			if (cmnd->label_find[i])
				put_error(ft_strjoin(cmnd->label_find[i],
							" is a label that does not exist\n"));
			i++;
		}
		free(cmnd->label_find);
		cmnd = cmnd->next;
	}
}

char				*add_param(int value, int size)
{
	char			*ret;
	char			*tmp;
	union u_param	param;
	int				i;

	i = size - 1;
	param.i = value;
	tmp = param.tab;
	if (!(ret = malloc(sizeof(*ret) * size)))
		put_error(0);
	while (i >= 0)
	{
		ret[i] = *tmp;
		i--;
		tmp++;
	}
	i = 0;
	return (ret);
}
