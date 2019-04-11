/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   samle_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:36:29 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/11 20:24:12 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

// void	catch_function(int signo)
// {
// 	if (signo == SIGWINCH)
// 		ft_printf("------ got it --------");
// }

/* 1 */
/* 2 */

// TODO: # define NO_ROOM "Not enough space! Resize window."
// TODO: circular selection with arrows ;
// TODO: One or more choices can be selected or un-selected with the the space key. With
// each selection, the cursor must automatically position itself on the next element.
// TODO: Cursor’s position: underlined text.
// TODO: large vs small window;
// TODO: resize of the window => cursor behavioiur
// TODO: Selected choice: inverse video text.
// TODO: Choice non selected: normal text.
// • If the choices are files names, colorize the list according to the extensions (a bit like
// ls -G on OSX).
// TODO: Selected choice + cursor’s position: inverse video underlined text.
// TODO: Whichever way your program ends, the default configuration of your terminal MUST be restored. This is true even after it received a signal (except for the signals that we cannot intercept, but this would mean that your program does not work).
// TODO: If the user presses either delete or backspace, the element the cursor is pointing to must be erased from the list.
// If there are no more elements in the list, the behavior must be exactly the same as if the user had pressed esc.
// TODO: When the user validates the selection with the return key, the list of choices will be sent back to shell.
// The latter (i.e. list of choices sent back) will be separated by a space. This will allow you to use your program ft_select inside a shell script (to create a “set” for example).
// TODO: sample of commands as in the subject;
// TODO: not possible to show everithing; if size is ok -> show everithing;
// TODO: If the user presses either delete or backspaceIf there are no more elements in the list, the behavior must be exactly the same as if the user had pressed esc.

/* 3 */

// TODO: check how the change size signal works; on every move = +;
// TODO: esc handler;
// TODO: We must be able to interrupt your program with ctrl+z and restore it with fg without seeing any changes in its behavior.
// TODO: If the program is launched in an empty environment, you need to behave reasonably.

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
	// printf("cursor: \n");

	// ft_printf(cm_string);

	// printf("cursor: \n");

	auto_wrap = tgetflag("am");

	height = tgetnum("li");
	// ft_printf("height -> %d\n", height);
	width = tgetnum("co");
	// ft_printf("width -> %d\n", width);

	/* Extract information that termcap functions use.  */
	temp = tgetstr("pc", BUFFADDR);
	PC = temp ? *temp : 0;
	BC = tgetstr("le", BUFFADDR);
	UP = tgetstr("up", BUFFADDR);
}

void clear_term()
{
	tputs(tc_cmd.cl, 1, putchar);
	// fflush(stdout);
}

int main(int argc, char **argv)
{
	// signal(SIGWINCH, catch_function);

	init_terminal_data();
	interrogate_terminal();

	init_termcap(&tc_cmd);

	struct termios s_termios;
	struct termios s_termios_backup;

	if (tcgetattr(0, &s_termios) == -1)
		return (-1);

	if (tcgetattr(0, &s_termios_backup) == -1)
		return (-1);

	while(argc!= 0)
	{
		ft_printf("%s\n",argv[argc]);
argc--;
	}
	


	s_termios.c_lflag &= ~(ICANON); /* Перевести терминал в канонический режим. Функция чтения будет получать ввод с клавиатуры без ожидания ввода */
	s_termios.c_lflag &= ~(ECHO);   /* Клавиши, набранные на клавиатуре, больше не будут появляться в терминале */

	// tputs(tc_cmd.vi, 1, ft_putstr_fd); /* Masque le curseur */
	ft_putstr_fd(tc_cmd.vi, 0);
		// clear_term();
		// tputs(tc_cmd.cl, 1, putchar);

		// char *cm_cap = tgetstr("cm", NULL);

		// tputs(tgoto(cm_cap, 5, 7), 1, putchar);
		// char *color_cap = tgetstr("AF", NULL);
		// tputs(tparm(color_cap, COLOR_GREEN), 1, putchar);
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, 0), 0);
	ft_putstr("Cool ! Maintenant j'ecris en vert !");

	ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, 2), 0);
	ft_putstr("Cool ! Maintenant j'ecris en vert !");
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, 1), 0);
	ft_putstr("Cool ! Maintenant j'ecris en vert !");
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), 40, 2), 0);
	ft_putstr("Cool ! Maintenant j'ecris en vert !");

	ft_putstr_fd(tgoto(tgetstr("cm", NULL), 80, 4), 0);
	ft_printf("asdfasdfasdfasdfas");


	
	int i = 1000000000;

	// ft_putstr_fd(tc_cmd.ve, 0);
	fflush(stdout);
	while(--i)
	{
		/* code */;
	}


	if (tcsetattr(0, 0, &s_termios_backup) == -1)
		return (-1);
	clear_term();
	tputs(tc_cmd.ve, 1, putchar); // activate cursor;
	return (0);
}
