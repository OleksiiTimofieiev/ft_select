#include "ft_select.h"

void	find_routine(t_global *global, char c)
{
	char	read_str[256];
	int key;
	int i = 0x0;

	key = 0;
	ft_memset(read_str, '\0', sizeof(read_str));
	read_str[i++] = c;
	while (i < 256)
	{
		read(INPUT_FD, &key, 8);
		if (!ft_isalpha(key) || key == RETURN)
			break ;
		read_str[i++] = key;
	}
	// ft_putstr_fd(read_str, INPUT_FD);

	t_input *buf = global->head;
	char *buf2;
	while (buf)
	{
		buf2 = ft_strstr(buf->data, read_str);

		if ((buf2))
		{
			t_colors colors;

			init_color_data(&colors);
			colors.data = global->current->data ;
			ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x,
							   global->current->y),
						 INPUT_FD);
			if (global->current->selection == 0)
							  ft_putstr_fd_select(&colors, 0, global);
			else
			{
				colors.color1 = BACK;
				ft_putstr_fd_select(&colors, 0, global);
			}

			global->current = buf;
			colors.data = global->current->data;
			colors.color1 = (global->current->selection) ? BACK : EMPTY_COLOR;
			colors.color2 = UNDERLINED;
			colors.color3 = ITALIC;
			ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x,
			global->current->y), INPUT_FD);

			ft_putstr_fd_select(&colors, INPUT_FD, global);
			break;
		}
		buf = buf->next;
	}
}
