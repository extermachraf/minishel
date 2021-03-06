/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishel.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:43:13 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/06/28 15:29:37 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H
# include "./src/includes/lexer.h"
# include "./src/includes/token.h"
# include "./src/includes/parser.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct nav
{
	int i;
	int	j;
	int	y;
}	t_nav;


typedef struct minishel
{
	t_parser	*parser;
	t_token		*token;
	t_lexer		*lexer;
	char		**env;
	char		*read;
	int			num_pip;
}	t_mini;


int		lent_d_pointer(char **str);
char	**get_env(char	**str);
t_nav	*init_nav(t_nav *nav);

#endif