
#include "asm.h"

t_cmnd		*cmnd_new(int size_param, char *line)
{
	t_cmnd	*new;
	int		i;

	i = 0;
	if (!(new = malloc(sizeof(*new))))
		put_error(0);
	new->op_code = 0;
	new->codage = 0;
	new->line = ft_strdup(line);
	if (!(new->params = malloc(sizeof(*new->params) * size_param)))
		put_error(0);
	while (i < size_param)
		new->params[i++] = NULL;
	new->size = 0;
	new->address = 0;
	if (!(new->label_find = malloc(sizeof(*(new->label_find)) * 3)))
		put_error(0);
	i = 0;
	while (i < 3)
		new->label_find[i++] = NULL;
	new->next = NULL;
	return (new);
}

t_label		*new_label(char *name)
{
	t_label	*new;

	if (!(new = malloc(sizeof(*new))))
		put_error(0);
	new->next = NULL;
	if (name)
		new->name = name;
	new->address = g_address;
	new->prev = NULL;
	return (new);
}

void		add_cmnd_to_end(t_cmnd **list_start, t_cmnd *new)
{
	t_cmnd	*ptr;

	ptr = *list_start;
	if (ptr)
	{
		while (ptr && ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	else
		*list_start = new;
}

void		add_label_start(t_label **list, t_label *elem)
{
	t_label		*tmp;

	tmp = *list;
	while (tmp)
		tmp = tmp->next;
	elem->next = *list;
	if (*list)
		(*list)->prev = elem;
	*list = elem;
}

char		*fill_label(char *line)
{
	char	*start;
	long	len;

	start = line;
	while (*line != '\0' && !ft_isspace(*line))
	{
		if (*line == LABEL_CHAR)
			break ;
		else if (!(ft_strchr(LABEL_CHARS, *line)))
			put_error("invalid char in label");
		line++;
	}
	if (*line == LABEL_CHAR)
	{
		len = ((line - start == 0) ? ft_strlen(start) : line - start);
		add_label_start(g_labels, new_label(ft_strsub(start, 0, len)));
		line++;
	}
	else
		line = start;
	return (line);
}
