
#include "acurse.h"

int		a_store_old_term(int ret)
{
	static struct termios	term;

	if (ret == INIT)
	{
		if (tcgetattr(0, &term) == -1)
			return (-1);
		if (tcsetattr(0, 0, &term) == -1)
			return (-1);
		return (INIT);
	}
	a_cursor_on();
	a_mode_off();
	a_clear();
	ft_putstr_fd(tgetstr("te", NULL), get_fd(0));
	close(get_fd(0));
	get_fd(1);
	return (tcsetattr(0, TCSANOW, &term));
}

void	a_exit(int ret)
{
	a_store_old_term(ret);
	exit(ret);
}

int		a_stop(int ret)
{
	return (a_store_old_term(ret));
}
