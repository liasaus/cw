
#include "acurse.h"

void	a_mode_video_inverted(void)
{
	a_tputs("mr");
}

void	a_mode_surlight(void)
{
	a_tputs("us");
}

void	a_mode_off(void)
{
	a_tputs("me");
}

void	a_cursor_off(void)
{
	a_tputs("vi");
}

void	a_cursor_on(void)
{
	a_tputs("ve");
}
