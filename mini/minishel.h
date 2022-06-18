/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishel.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:43:13 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/06/16 16:56:49 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H
# include "./src/includes/lexer.h"
# include "./src/includes/token.h"
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


void	get_back_pipes(char **str);
char	**split_redline_pip(char *str);

#endif