/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:36:29 by otimofie          #+#    #+#             */
/*   Updated: 2019/03/22 16:32:56 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

#ifdef unix
static char term_buffer[2048];
#else
#define term_buffer 0
#endif

void init_terminal_data()
{
	char *termtype = getenv("TERM");

	int success;

	if (termtype == 0)
		ft_printf("Specify a terminal type with `setenv TERM <yourtype>'.\n");

	success = tgetent(term_buffer, termtype);

	if (success < 0)
		ft_printf("Could not access the termcap data base.\n");
	if (success == 0)
		ft_printf("Terminal type `%s' is not defined.\n", termtype);
}

char *tgetstr();

char *cl_string, *cm_string;
int height;
int width;
int auto_wrap;

char PC;  /* For tputs.  */
char *BC; /* For tgoto.  */
char *UP;

void interrogate_terminal(void)
{
#ifdef Unix
	/* Here we assume that an explicit term_buffer
     was provided to tgetent.  */
	char *buffer = (char *)malloc(strlen(term_buffer));
#define BUFFADDR &buffer
#else
#define BUFFADDR 0
#endif

	char *temp;

	/* Extract information we will use.  */
	cl_string = tgetstr("cl", BUFFADDR);
	ft_printf(cl_string);
	cm_string = tgetstr("cm", BUFFADDR);
	ft_printf(cm_string);

	auto_wrap = tgetflag("am");

	height = tgetnum("li");
	ft_printf("height -> %d\n", height);
	width = tgetnum("co");
	ft_printf("width -> %d\n", width);

	/* Extract information that termcap functions use.  */
	temp = tgetstr("pc", BUFFADDR);
	PC = temp ? *temp : 0;
	BC = tgetstr("le", BUFFADDR);
	UP = tgetstr("up", BUFFADDR);
}

int main(void)
{
	init_terminal_data();
	interrogate_terminal();

	return (0);
}
