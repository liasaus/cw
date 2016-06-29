
#include "asm.h"

void	check_reg(char **line, t_cmnd *new, int nb_param)
{
	char	*start;
	char	*tmp;
	int		reg_value;

	(*line)++;
	start = *line;
	while (*start && ft_isdigit(*start))
		start++;
	tmp = ft_strsub(*line, 0, start - *line);
	reg_value = ft_atoi(tmp);
	free(tmp);
	start = ft_strepur(start);
	if (reg_value <= 0 || reg_value > 16
			|| (*start && *start != SEPARATOR_CHAR && !ft_isspace(*start)))
		put_error("not a valid register");
	new->params[nb_param] = add_param(reg_value, 1);
	new->codage += REG_CODE << (6 - 2 * nb_param);
	*line = start;
	new->size++;
}

void	check_dir(char **line, t_cmnd *new, int nb_param, t_instruction select)
{
	char	*label;
	int		dir_value;

	if (**line == LABEL_CHAR)
	{
		*line += (ft_strlen(label = find_label(line)));
		*line = ft_strepur(*line);
		if (**line && **line != SEPARATOR_CHAR && !ft_isspace(**line))
			put_error("not a valid label");
		if ((dir_value = check_label(label)) >= 0)
		{
			new->params[nb_param] = add_param(dir_value - g_address,
					select.dir_size);
			free(label);
		}
		else
			new->label_find[nb_param] = label;
	}
	else
	{
		dir_value = check_num(line);
		new->params[nb_param] = add_param(dir_value, select.dir_size);
	}
	new->codage += DIR_CODE << (6 - 2 * nb_param);
	new->size += select.dir_size;
}

void	check_ind(char **line, t_cmnd *new, int nb_param, t_instruction select)
{
	char	*label;
	int		ind_value;

	if (**line == LABEL_CHAR)
	{
		*line += ft_strlen(label = find_label(line));
		*line = ft_strepur(*line);
		if (**line && **line != SEPARATOR_CHAR && !ft_isspace(**line))
			put_error("not a valid label");
		if ((ind_value = check_label(label)) >= 0)
		{
			new->params[nb_param] = add_param(ind_value - g_address,
					select.dir_size);
			free(label);
		}
		else
			new->label_find[nb_param] = label;
	}
	else
	{
		ind_value = check_num(line);
		new->params[nb_param] = add_param(ind_value, 2);
	}
	new->codage += IND_CODE << (6 - 2 * nb_param);
	new->size += 2;
}

int		check_param(char **line, t_cmnd *new, int nb_param, t_instruction selec)
{
	if (!**line)
		return (0);
	if (**line == 'r')
	{
		if (!(selec.param_type[nb_param] & T_REG))
			put_error("Invalid parameter type register for instruction\n");
		check_reg(line, new, nb_param);
	}
	else if (**line == DIRECT_CHAR)
	{
		if (!(selec.param_type[nb_param] & T_DIR))
			put_error("Invalid parameter type direct for instruction\n");
		(*line)++;
		check_dir(line, new, nb_param, selec);
	}
	else
	{
		if (!(selec.param_type[nb_param] & T_IND))
			put_error("Invalid parameter type indirect for instruction\n");
		check_ind(line, new, nb_param, selec);
	}
	return (1);
}

t_cmnd	*find_params(char **line, t_instruction select)
{
	int		nb_param;
	t_cmnd	*new;

	nb_param = 0;
	new = cmnd_new(select.nb_param, *line);
	new->address = g_address;
	while (**line)
	{
		*line = ft_strepur(*line);
		nb_param += check_param(line, new, nb_param, select);
		*line = ft_strepur(*line);
		if (nb_param > select.nb_param)
			put_error("too many parameters");
		if (**line == SEPARATOR_CHAR)
			(*line)++;
	}
	if (nb_param < select.nb_param)
		put_error("too few parameters");
	new->op_code = select.opcode;
	new->size += (select.codage) ? 2 : 1;
	g_address += new->size;
	return (new);
}
