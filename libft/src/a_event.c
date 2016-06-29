
#include "acurse.h"

int		a_event(void)
{
	char	b[4];
	int		i;
	int		x;
	int		y;

	i = 0;
	a_getscreen(&x, &y);
	while (i < 4)
	{
		b[i] = 0;
		i++;
	}
	read(0, b, 4);
	if (a_storage_data(GETX, 0, 0) != x || a_storage_data(GETY, 0, 0) != y)
		return (E_RESIZE);
	else
		return (*(unsigned int *)b);
}

int		init_term(struct termios *term)
{
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (-1);
	else
		return (0);
}

int		a_init(void)
{
	struct termios	term;
	struct winsize	s;
	char			*term_name;
	int				fd;

	if (((fd = open(ttyname(0), O_WRONLY)) == -1)
			|| ((term_name = getenv("TERM")) == NULL)
			|| (a_stop(INIT) != INIT))
		return (-1);
	get_fd(fd);
	if ((tgetent(NULL, term_name) == -1)
			|| (tcgetattr(0, &term) == -1))
		return (-1);
	init_term(&term);
	ft_putstr_fd(tgetstr("ti", NULL), get_fd(0));
	a_init_clear();
	if (init_term(&term) == -1)
		return (-1);
	siginterrupt(SIGWINCH, 1);
	siginterrupt(SIGTSTP, 1);
	a_handle_signal();
	ioctl(0, TIOCGWINSZ, &s);
	a_storage_data(NEWSCREEN, s.ws_col, s.ws_row);
	a_mv(0, 0);
	return (0);
}
