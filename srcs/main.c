/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:36:29 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/09 20:13:01 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

#include <stdio.h>

struct s_termcap_cmd
{
	char *cl;
	char *cm;
	char *vi;
	char *ve;
	char *ab;
	char *reset;

	char *ku;
	char *kd;
	char *kl;
	char *kr;
};

struct s_termcap_cmd tc_cmd;

void init_termcap(struct s_termcap_cmd *tc_cmd)
{
// #ifdef USE_TERMCAP
	int ret;
	char *term_name = getenv("TERM");

	if (term_name == NULL)
	{
		fprintf(stderr, "Specify a terminal type with 'TERM=<type>'.\n");
		return ;
	}

	ret = tgetent(NULL, term_name);

	if (ret == -1)
	{
		fprintf(stderr, "Could not access the termcap data base.\n");
		return;
	}
	else if (ret == 0)
	{
		fprintf(stderr, "Terminal type '%s' is not defined in termcap database (or too little information).\n", term_name);
		return ;
	}

	tc_cmd->cl = tgetstr("cl", NULL);
	tc_cmd->cm = tgetstr("cm", NULL);
	tc_cmd->vi = tgetstr("vi", NULL);
	tc_cmd->ve = tgetstr("ve", NULL);
	tc_cmd->ab = tgetstr("AB", NULL);
	tc_cmd->reset = tgetstr("me", NULL);

	tc_cmd->ku = tgetstr("ku", NULL);
	tc_cmd->kd = tgetstr("kd", NULL);
	tc_cmd->kl = tgetstr("kl", NULL);
	tc_cmd->kr = tgetstr("kr", NULL);
// #else

// 	if (setupterm(NULL, STDOUT_FILENO, NULL) != 0)
// 	{
// 		return -1;
// 	}

// 	tc_cmd.cl = tigetstr("clear");
// 	tc_cmd.cm = tigetstr("cup");
// 	tc_cmd.vi = tigetstr("civis");
// 	tc_cmd.ve = tigetstr("cnorm");
// 	tc_cmd.ab = tigetstr("setab");
// 	tc_cmd.reset = tigetstr("sgr0");

// 	tc_cmd.ku = tigetstr("kcuu1");
// 	tc_cmd.kd = tigetstr("kcud1");
// 	tc_cmd.kl = tigetstr("kcub1");
// 	tc_cmd.kr = tigetstr("kcuf1");

// #endif
// 	return 0;
}

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
	else
		ft_printf("Terminal type `%s' is defined.\n", termtype);
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
	printf("\n");
	cm_string = tgetstr("cm", BUFFADDR);
	printf("cursor: \n");

	ft_printf(cm_string);

	printf("cursor: \n");

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

void clear_term()
{
	tputs(tc_cmd.cl, 1, putchar);
	fflush(stdout);
}

int main(void)
{
	init_terminal_data();
	interrogate_terminal();

	init_termcap(&tc_cmd);

	struct termios s_termios;
	struct termios s_termios_backup;

	if (tcgetattr(0, &s_termios) == -1)
		return (-1);

	if (tcgetattr(0, &s_termios_backup) == -1)
		return (-1);


	// clear_term();

	s_termios.c_lflag &= ~(ICANON); /* Перевести терминал в канонический режим. Функция чтения будет получать ввод с клавиатуры без ожидания ввода */
	s_termios.c_lflag &= ~(ECHO);   /* Клавиши, набранные на клавиатуре, больше не будут появляться в терминале */

	tputs(tc_cmd.vi, 1, putchar); /* Masque le curseur */
	tputs(tc_cmd.cl, 1, putchar);

	// char *color_cap = tgetstr("AF", NULL);
	// tputs(tparm(color_cap, COLOR_GREEN), 1, putchar);

	// tputs(tgoto(tc_cmd.cm, 20, 20), 1, putchar);
int j = 50;

while(--j)
{
	ft_printf("Cool ! Maintenant j'ecris en vert !");

}
	int i = 1000000000;



	while(--i)
	{
		/* code */;
	}

	tputs(tc_cmd.ve, 1, putchar); // activate cursor;
	// fflush(stdout);

	if (tcsetattr(0, 0, &s_termios_backup) == -1)
		return (-1);

	return (0);
}
